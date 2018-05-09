grammar Cmm;

/***************************************************
 *                                                 *
 *                     Parser                      *
 *                                                 *
 **************************************************/

primaryExpression
    :   Identifier
    |   Constant
    |   StringLiteral+
    |   '(' expression ')'
    ;

postfixExpression
    :   primaryExpression
    |   postfixExpression '(' argumentExpressionList? ')'
    |   postfixExpression '++'
    |   postfixExpression '--'
    ;

argumentExpressionList
    :   assignmentExpression
    |   argumentExpressionList ',' assignmentExpression
    ;

unaryExpression
    :   postfixExpression
    |   '++' unaryExpression
    |   '--' unaryExpression
    |   unaryOperator unaryExpression
    |   DigitSequence
    ;

unaryOperator
    :   '&' | '*' | '+' | '-' | '~' | '!'
    ;

multiplicativeExpression
    :   unaryExpression
    |   multiplicativeExpression '*' unaryExpression
    |   multiplicativeExpression '/' unaryExpression
    |   multiplicativeExpression '%' unaryExpression
    ;

additiveExpression
    :   multiplicativeExpression
    |   additiveExpression '+' multiplicativeExpression
    |   additiveExpression '-' multiplicativeExpression
    ;

shiftExpression
    :   additiveExpression
    |   shiftExpression '<<' additiveExpression
    |   shiftExpression '>>' additiveExpression
    ;

relationalExpression
    :   shiftExpression
    |   relationalExpression '<' shiftExpression
    |   relationalExpression '>' shiftExpression
    |   relationalExpression '<=' shiftExpression
    |   relationalExpression '>=' shiftExpression
    ;

equalityExpression
    :   relationalExpression
    |   equalityExpression 'is' relationalExpression
    |   equalityExpression 'is not' relationalExpression
    |   equalityExpression '==' relationalExpression
    |   equalityExpression '!=' relationalExpression
    ;

andExpression
    :   equalityExpression
    |   andExpression '&' equalityExpression
    ;

exclusiveOrExpression
    :   andExpression
    |   exclusiveOrExpression '^' andExpression
    ;

inclusiveOrExpression
    :   exclusiveOrExpression
    |   inclusiveOrExpression '|' exclusiveOrExpression
    ;

logicalAndExpression
    :   inclusiveOrExpression
    |   logicalAndExpression '&&' inclusiveOrExpression
    |   logicalAndExpression 'and' inclusiveOrExpression
    ;

logicalOrExpression
    :   logicalAndExpression
    |   logicalOrExpression '||' logicalAndExpression
    |   logicalOrExpression 'or' logicalAndExpression
    ;

conditionalExpression
    :   logicalOrExpression ('?' expression ':' conditionalExpression)?
    ;

assignmentExpression
    :   conditionalExpression
    |   unaryExpression assignmentOperator assignmentExpression
    |   DigitSequence // for
    ;

assignmentOperator
    :   '=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|=' | NegateAssign
    ;

expression
    :   assignmentExpression
    |   expression ',' assignmentExpression
    ;

declaration
    :   declarationSpecifiers initDeclaratorList ';'
    |   declarationSpecifier ';'
    ;

declarationSpecifiers
    :   declarationSpecifier+
    ;

declarationSpecifier
    :   typeSpecifier
    ;

initDeclaratorList
    :   initDeclarator (',' initDeclarator)*
    |   initDeclaratorList ',' initDeclarator
    ;

initDeclarator
    :   declarator
    |   declarator '=' initializer
    ;

typeSpecifier
    :   ('void'
    |   'bool'
    |   'char'
    |   'short'
    |   'int'
    |   'long'
    |   'float'
    |   'double'
    |   'signed'
    |   'unsigned'
    |   'uint32_t'
    |   'int32_t'
    )
    ;

declarator
    :   '*'? directDeclarator
    ;

directDeclarator
    :   Identifier
    |   directDeclarator '(' parameterTypeList ')'
    |   directDeclarator '(' identifierList? ')'
    ;

parameterTypeList
    :   parameterList
    |   parameterList ',' '...'
    ;

parameterList
    :   parameterDeclaration
    |   parameterList ',' parameterDeclaration
    ;

parameterDeclaration
    :   declarationSpecifiers declarator
    |   declarationSpecifiers
    ;

identifierList
    :   Identifier
    |   identifierList ',' Identifier
    ;

statement
    :   compoundStatement
    |   expressionStatement
    |   selectionStatement
    ;
//        |   expressionStatement
//        |   selectionStatement
//        |   iterationStatement
//        |   jumpStatement

compoundStatement
    :   '{' blockItemList? '}'
    ;

blockItemList
    :   blockItem
    |   blockItemList blockItem
    ;

blockItem
    :   statement
    |   declaration
    ;

initializer
    :   assignmentExpression;


expressionStatement
    :   expression? ';'
    ;

selectionStatement
    :   'if' '(' expression ')' statement ('else' statement)?
    ;

compilationUnit
    :   translationUnit? EOF
    ;

translationUnit
    :   externalDeclaration
    |   translationUnit externalDeclaration
    ;

externalDeclaration
    :   functionDefinition
    |   declaration
    |   ';' // stray ;
    ;

functionDefinition
    :   declarationSpecifiers? declarator compoundStatement
    ;


/***************************************************
 *                                                 *
 *                   Fragments                     *
 *                                                 *
 **************************************************/

fragment
IdentifierNondigit
    :   Nondigit
    |   UniversalCharacterName
    ;

fragment
Nondigit
    :   [a-zA-Z_]
    ;

fragment
Digit
    :   [0-9]
    ;

fragment
UniversalCharacterName
    :   '\\u' HexQuad
    |   '\\U' HexQuad HexQuad
    ;

fragment
HexQuad
    :   HexadecimalDigit HexadecimalDigit HexadecimalDigit HexadecimalDigit
    ;

Constant
    :   IntegerConstant
    |   FloatingConstant
    //|   EnumerationConstant
    |   CharacterConstant
    ;

fragment
IntegerConstant
    :   DecimalConstant IntegerSuffix?
    |   OctalConstant IntegerSuffix?
    |   HexadecimalConstant IntegerSuffix?
    |   BinaryConstant
    ;

fragment
BinaryConstant
    :   '0' [bB] [0-1]+
    ;

fragment
DecimalConstant
    :   NonzeroDigit Digit*
    ;

fragment
OctalConstant
    :   '0' OctalDigit*
    ;

fragment
HexadecimalConstant
    :   HexadecimalPrefix HexadecimalDigit+
    ;

fragment
HexadecimalPrefix
    :   '0' [xX]
    ;

fragment
NonzeroDigit
    :   [1-9]
    ;

fragment
OctalDigit
    :   [0-7]
    ;

fragment
HexadecimalDigit
    :   [0-9a-fA-F]
    ;

fragment
IntegerSuffix
    :   UnsignedSuffix LongSuffix?
    |   UnsignedSuffix LongLongSuffix
    |   LongSuffix UnsignedSuffix?
    |   LongLongSuffix UnsignedSuffix?
    ;

fragment
UnsignedSuffix
    :   [uU]
    ;

fragment
LongSuffix
    :   [lL]
    ;

fragment
LongLongSuffix
    :   'll' | 'LL'
    ;

fragment
FloatingConstant
    :   DecimalFloatingConstant
    |   HexadecimalFloatingConstant
    ;

fragment
DecimalFloatingConstant
    :   FractionalConstant ExponentPart? FloatingSuffix?
    |   DigitSequence ExponentPart FloatingSuffix?
    ;

fragment
HexadecimalFloatingConstant
    :   HexadecimalPrefix HexadecimalFractionalConstant BinaryExponentPart FloatingSuffix?
    |   HexadecimalPrefix HexadecimalDigitSequence BinaryExponentPart FloatingSuffix?
    ;

fragment
FractionalConstant
    :   DigitSequence? '.' DigitSequence
    |   DigitSequence '.'
    ;

fragment
ExponentPart
    :   'e' Sign? DigitSequence
    |   'E' Sign? DigitSequence
    ;

fragment
Sign
    :   '+' | '-'
    ;

DigitSequence
    :   Digit+
    ;

fragment
HexadecimalFractionalConstant
    :   HexadecimalDigitSequence? '.' HexadecimalDigitSequence
    |   HexadecimalDigitSequence '.'
    ;

fragment
BinaryExponentPart
    :   'p' Sign? DigitSequence
    |   'P' Sign? DigitSequence
    ;

fragment
HexadecimalDigitSequence
    :   HexadecimalDigit+
    ;

fragment
FloatingSuffix
    :   'f' | 'l' | 'F' | 'L'
    ;

fragment
CharacterConstant
    :   '\'' CCharSequence '\''
    |   'L\'' CCharSequence '\''
    |   'u\'' CCharSequence '\''
    |   'U\'' CCharSequence '\''
    ;

fragment
CCharSequence
    :   CChar+
    ;

fragment
CChar
    :   ~['\\\r\n]
    |   EscapeSequence
    ;

fragment
EscapeSequence
    :   SimpleEscapeSequence
    |   OctalEscapeSequence
    |   HexadecimalEscapeSequence
    |   UniversalCharacterName
    ;

fragment
SimpleEscapeSequence
    :   '\\' ['"?abfnrtv\\]
    ;

fragment
OctalEscapeSequence
    :   '\\' OctalDigit
    |   '\\' OctalDigit OctalDigit
    |   '\\' OctalDigit OctalDigit OctalDigit
    ;

fragment
HexadecimalEscapeSequence
    :   '\\x' HexadecimalDigit+
    ;

StringLiteral
    :   EncodingPrefix? '"' SCharSequence? '"'
    ;

fragment
EncodingPrefix
    :   'u8'
    |   'u'
    |   'U'
    |   'L'
    ;

fragment
SCharSequence
    :   SChar+
    ;

fragment
SChar
    :   ~["\\\r\n]
    |   EscapeSequence
    |   '\\\n'   // Added line
    |   '\\\r\n' // Added line
    ;
/***************************************************
 *                                                 *
 *                      Lexer                      *
 *                                                 *
 **************************************************/

/// @ { Custom tokens
Coalescing       : '??';
Bit              : '@';
Power            : '**';
IgnoreWildCard   : '_';
Namespace        : 'namespace';
ScopeResolution  : '::';
String           : 'string';
/// @ }
Break            : 'break';
Case             : 'case';
Char             : 'char';
Const            : 'const';
Continue         : 'continue';
Bool             : 'bool';
Default          : 'default';
Double           : 'double';
Else             : 'else';
Extern           : 'extern';
Float            : 'float';
For              : 'for';
If               : 'if';
Int              : 'int';
Uint32           : 'uint32_t';
Int32            : 'int32_t';
Long             : 'long';
Return           : 'return';
Short            : 'short';
Signed           : 'signed';
Sizeof           : 'sizeof';
Static           : 'static';
Switch           : 'switch';
Typedef          : 'typedef';
Unsigned         : 'unsigned';
Void             : 'void';
While            : 'while';
LeftParen        : '(';
RightParen       : ')';
LeftBracket      : '[';
RightBracket     : ']';
LeftBrace        : '{';
RightBrace       : '}';
Less             : '<';
LessEqual        : '<=';
Greater          : '>';
GreaterEqual     : '>=';
LeftShift        : '<<';
RightShift       : '>>';
Plus             : '+';
PlusPlus         : '++';
Minus            : '-';
MinusMinus       : '--';
Star             : '*';
Div              : '/';
Mod              : '%';
And              : '&';
Or               : '|';
Negate           : '~';
Caret            : '^';
Question         : '?';
Colon            : ':';
Semi             : ';';
Comma            : ',';
Assign           : '=';
StarAssign       : '*=';
DivAssign        : '/=';
ModAssign        : '%=';
PlusAssign       : '+=';
MinusAssign      : '-=';
LeftShiftAssign  : '<<=';
RightShiftAssign : '>>=';
AndAssign        : '&=';
XorAssign        : '^=';
OrAssign         : '|=';
NegateAssign     : '~=';
Arrow            : '->';
Dot              : '.';
Ellipsis         : '...';

AndAnd
    : '&&'
    | 'and'
    ;

OrOr
    : '||'
    | 'or'
    ;
Not
    : '!'
    | 'not'
    ;

Equal
    : '=='
    | 'is'
    ;

NotEqual
    : '!='
    | 'is not'
    ;

Identifier
    :   IdentifierNondigit
        (   IdentifierNondigit
        |   Digit
        )*
    ;
Whitespace
    :   [ \t]+
        -> skip
    ;

Newline
    :   (   '\r' '\n'?
        |   '\n'
        )
        -> skip
    ;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
    ;