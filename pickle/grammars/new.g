

grammar C;

/***************************************************
 *                                                 *
 *                     Parser                      *
 *                                                 *
 **************************************************/

compilationUnit
    :   translationUnit? EOF
    ;

translationUnit
    :   externalDeclaration
    |   translationUnit externalDeclaration
    ;

primaryExpression
    :   Identifier
    |   Constant
    |   '(' expression ')'
    ;

postfixExpression
    :   primaryExpression
    |   postfixExpression '[' expression ']'
    |   postfixExpression '(' argumentExpressionList? ')'
    |   postfixExpression '++'
    |   postfixExpression '--'
    |   '(' typeName ')' '{' initializerList '}'
    |   '(' typeName ')' '{' initializerList ',' '}'
    ;

argumentExpressionList
    :   assignmentExpression
    |   argumentExpressionList ',' assignmentExpression
    ;

unaryExpression
    :   postfixExpression
    |   '++' unaryExpression
    |   '--' unaryExpression
    |   unaryOperator castExpression
    ;

unaryOperator
    :   '&' | '*' | '+' | '-' | '~' | '!'
    ;

castExpression
    :   '(' typeName ')' castExpression
    |   unaryExpression
    |   DigitSequence // for
    ;

multiplicativeExpression
    :   castExpression
    |   multiplicativeExpression '*' castExpression
    |   multiplicativeExpression '/' castExpression
    |   multiplicativeExpression '%' castExpression
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
    |   equalityExpression Equal relationalExpression
    |   equalityExpression NotEqual relationalExpression
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
    ;

logicalOrExpression
    :   logicalAndExpression
    |   logicalOrExpression '||' logicalAndExpression
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

constantExpression
    :   conditionalExpression
    ;

declaration
    :   declarationSpecifiers initDeclaratorList ';'
    |   declarationSpecifiers ';'
    ;

declarationSpecifiers
    :   declarationSpecifier+
    ;

declarationSpecifiers2
    :   declarationSpecifier+
    ;

declarationSpecifier
    :   typeSpecifier
    |   typeQualifier
    |   functionSpecifier
    ;

initDeclaratorList
    :   initDeclarator
    |   initDeclaratorList ',' initDeclarator
    ;

initDeclarator
    :   declarator
    |   declarator '=' initializer
    ;

typeSpecifier
    :   ('void'
    |   'bool'
    |   'uint32_t'
    |   'int32_t'
    |   'char'
    |   'int'
    |   'long'
    |   'float'
    |   'double'
    )
    |   typedefName
    ;

specifierQualifierList
    :   typeSpecifier specifierQualifierList?
    |   typeQualifier specifierQualifierList?
    ;

typeQualifier
    :   'const'
    ;

declarator
    :   directDeclarator
    ;

directDeclarator
    :   Identifier
    |   '(' declarator ')'
    |   directDeclarator '(' parameterTypeList ')'
    |   directDeclarator '(' identifierList? ')'
    ;

nestedParenthesesBlock
    :   (   ~('(' | ')')
        |   '(' nestedParenthesesBlock ')'
        )*
    ;

typeQualifierList
    :   typeQualifier
    |   typeQualifierList typeQualifier
    ;

parameterTypeList
    :   parameterList
    ;

parameterList
    :   parameterDeclaration
    |   parameterList ',' parameterDeclaration
    ;

parameterDeclaration
    :   declarationSpecifiers declarator
    |   declarationSpecifiers2 abstractDeclarator?
    ;

identifierList
    :   Identifier
    |   identifierList ',' Identifier
    ;

typeName
    :   specifierQualifierList abstractDeclarator?
    ;

abstractDeclarator
    :   directAbstractDeclarator
    ;

directAbstractDeclarator
    :   '(' abstractDeclarator ')'
    |   '[' typeQualifierList? assignmentExpression? ']'
    |   '(' parameterTypeList? ')'
    |   directAbstractDeclarator '[' typeQualifierList? assignmentExpression? ']'
    |   directAbstractDeclarator '(' parameterTypeList? ')'
    ;


initializer
    :   assignmentExpression
    |   '{' initializerList '}'
    |   '{' initializerList ',' '}'
    ;

initializerList
    :   designation? initializer
    |   initializerList ',' designation? initializer
    ;

designation
    :   designatorList '='
    ;

designatorList
    :   designator
    |   designatorList designator
    ;

designator
    :   '[' constantExpression ']'
    |   '.' Identifier
    ;

statement
    :   compoundStatement
    |   expressionStatement
    |   selectionStatement
    |   iterationStatement
    |   jumpStatement
    ;

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

expressionStatement
    :   expression? ';'
    ;

selectionStatement
    :   'if' '(' expression ')' statement ('else' statement)?
    ;

iterationStatement
    :   While '(' expression ')' statement
    |   For '(' forCondition ')' statement
    ;

forCondition
    :   forDeclaration ';' forExpression? ';' forExpression?
    |   expression? ';' forExpression? ';' forExpression?
    ;

forDeclaration
    :   declarationSpecifiers initDeclaratorList
    |   declarationSpecifiers
    ;

forExpression
    :   assignmentExpression
    |   forExpression ',' assignmentExpression
    ;

externalDeclaration
    :   functionDefinition
    |   declaration
    |   ';' // stray ;
    ;

functionDefinition
    :   declarationSpecifiers? declarator declarationList? compoundStatement
    ;

declarationList
    :   declaration
    |   declarationList declaration
    ;

/***************************************************
 *                                                 *
 *                   Fragments                     *
 *                                                 *
 **************************************************/

fragment
IdentifierNondigit
    :   Nondigit
    ;

fragment
Nondigit
    :   [a-zA-Z_]
    ;

fragment
Digit
    :   [0-9]
    ;

DigitSequence
    :   Digit+
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

/***************************************************
 *                                                 *
 *                      Skips                      *
 *                                                 *
 **************************************************/

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