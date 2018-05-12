grammar Pcl2;

@header {
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
}

compilationUnit
    :translationUnit? EOF
    ;

translationUnit
    :   externalDeclaration
    |   translationUnit externalDeclaration
    ;

externalDeclaration
    :   functionDefinition
    |   declaration
    |   Semi
    ;

primaryExpression
    :   Identifier
    |   IntegerConstant
    |   FloatConstant
    |   LeftParen expression RightParen
    ;

functionDefinition
    : typeSpecifier Identifier paramaterTypeList compoundStatement;

functionCall
    : Identifier LeftParen identifierList? RightParen Semi
    ;

functionReturn
    : Identifier LeftParen identifierList? RightParen
    ;

identifierList
    : Identifier (Comma Identifier)*
    ;

compoundStatement
    :   LeftBrace blockItemList? RightBrace
    ;

blockItemList
    :   blockItem
    |   blockItemList blockItem
    ;

blockItem
    :   statement
    |   declaration
    ;

statement
    :   compoundStatement
    |   expressionStatement
    |   selectionStatement
    |   iterationStatement
    |   assignmentStatement
    ;

assignmentStatement
    :   assignmentExpression Semi
    ;

expressionStatement
    :   expression? Semi
    ;

selectionStatement
    : If LeftParen conditionalExpression RightParen statement
    ;

iterationStatement
    :   While LeftParen conditionalExpression RightParen statement
    ;

expression locals [TypeSpec * type = nullptr ]
    :   expression opr=('*'|'/'|'%') expression # mulDivExpr
    |   expression opr=('+'|'-') expression     # addminExpr
    |   primaryExpression                       # primExpr
    ;

conditionalExpression
    :   expression ConditionalOperator expression
    |   conditionalExpression ConditionalConnectOperator conditionalExpression
    |   Not LeftParen conditionalExpression RightParen
    ;

assignmentExpression
    :   Identifier Assign expression
    |   Identifier Assign functionReturn
    ;

typeSpecifier
    :   (Void
    |   Bool
    |   Char
    |   Int
    |   Float
    |   Double
    )
    ;

paramaterTypeList
    :   LeftParen (declaration)* RightParen;

declaration locals [TypeSpec * type = nullptr ]
    :   typeSpecifier Identifier (Comma Identifier)* Semi
    |   typeSpecifier assignmentExpression (Comma assignmentExpression)* Semi
    ;



fragment
IdentifierNondigit
    :   Nondigit
    //|   // other implementation-defined characters...
    ;

fragment
Nondigit
    :   [a-zA-Z_]
    ;

fragment
DigitSequence
    :   Digit+
    ;

fragment
Digit
    :   [0-9]
    ;

fragment
NonzeroDigit
    :   [1-9]
    ;

fragment
Constant
    :   IntegerConstant
    |   FloatConstant
    ;

ConditionalConnectOperator
    :   OrOr
    |   AndAnd
    ;

ConditionalOperator
    :   Less
    |   LessEqual
    |   Greater
    |   GreaterEqual
    |   Equal
    |   NotEqual
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

IntegerConstant
    :   Digit+
    ;

FloatConstant
    :   DigitSequence? '.' DigitSequence
    |   DigitSequence '.'
    ;

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