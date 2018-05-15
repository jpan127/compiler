grammar Pcl2;

@header {
#include "wci/intermediate/symtab.h"
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

functionDefinition 
    locals [
        string function_header,
        uint32_t num_local_vars = 0,
        size_t stack_size = 0,
    ]
    : typeSpecifier Identifier parameterTypeList compoundStatement;

functionDeclaration
    locals [
        TypeSpec * type = nullptr,
        char type_letter = 0,
    ]
    :   typeSpecifier Identifier(Comma typeSpecifier Identifier)*
    ;

declaration 
    locals [
        TypeSpec * type = nullptr, 
        char type_letter = 0
    ]
    :   typeSpecifier Identifier (Comma Identifier)* Semi
    |   typeSpecifier assignmentExpression (Comma assignmentExpression)* Semi
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

functionCall
    : Identifier LeftParen identifierList? RightParen Semi
    ;

functionReturn
    : Identifier LeftParen identifierList? RightParen
    ;

jumpStatement
    :      Return expression? Semi
    ;

identifierList
    : Identifier (Comma Identifier)*
    ;

compoundStatement locals [ string scope_name = "Anonymous" ]
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
    |   ifElseStatement
    |   iterationStatement
    |   assignmentStatement
    |   jumpStatement
    |   unaryStatement Semi
    ;

unaryStatement
    locals [
        TypeSpec * type = nullptr,
        char type_letter = '?'
    ]
    :   PlusPlus   Identifier  # unaryIncrementStatement
    |   MinusMinus Identifier  # unaryDecrementStatement
    |   Identifier PlusPlus    # unaryIncrementStatement
    |   Identifier MinusMinus  # unaryDecrementStatement
    |   Identifier Power       # unarySquareStatement
    ;

assignmentStatement
    :   assignmentExpression Semi
    ;

expressionStatement
    :   expression? Semi
    ;

ifElseStatement
    : ifStatement elseIfStatement* elseStatement*
    ;

ifStatement
    : If LeftParen conditionalExpression RightParen statement
    ;

elseIfStatement
    locals [
        uint32_t id = 0
    ]
    : Else If LeftParen conditionalExpression RightParen statement
    ;

elseStatement
    : Else statement
    ;

/// While Statement
iterationStatement
    :   While LeftParen conditionalExpression RightParen statement
    ;

primaryExpression
    locals [
        char type_letter = '?',
        uint32_t current_nesting_level = 0
    ]
    :   Identifier
    |   IntegerConstant
    |   FloatConstant
    |   LeftParen expression RightParen
    ;

expression 
    locals [
        TypeSpec * type = nullptr,
        string expr_operator,
        char type_letter = '?',
        expression_type_E expression_type
    ]
    :   expression opr=( '*' | '/' | '%' ) expression                       # mulDivExpr
    |   expression opr=( '+' | '-' ) expression                             # addminExpr
    |   expression opr=( '<<' | '>>' | '&' | '|' | '~' | '^' ) expression   # bitExpr
    |   primaryExpression                                                   # primExpr
    ;

conditionalExpression 
    locals [ 
        string iteration_name,  /// Stores the name of the parent statement (while_N | if_N)
        string opr,             /// Stores the operator chars
        string opcode           /// Stores the instruction opcode used in Pass 2
    ]
    :   expression ConditionalOperator expression                               # basicConditionalExpr
    |   conditionalExpression ConditionalConnectOperator conditionalExpression  # connectedConditionalExpr
    |   LeftParen conditionalExpression RightParen                              # parenthesizedConditionalExpr
    |   Not LeftParen conditionalExpression RightParen                          # negatedConditionalExpr
    ;

assignmentExpression
    locals [
        TypeSpec * type = nullptr, 
        char type_letter = 0,
        uint32_t current_nesting_level = 0
    ]
    :   Identifier Assign expression
    |   Identifier Assign functionReturn
    ;

parameterTypeList
    :   LeftParen functionDeclaration? RightParen;

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
    :   '-'? NonzeroDigit Digit*
    |   '0'
    ;

FloatConstant
    :   '-'? DigitSequence? '.' DigitSequence
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