grammar Cmm;

@header {
#include "TypeSpecifier.hpp"
}

/***************************************************
 *                                                 *
 *                   C O M M O N                   *
 *                                                 *
 **************************************************/

compilationUnit
    :   translationUnit? EOF
    ;

translationUnit
    :   externalDeclaration
    |   translationUnit externalDeclaration
    ;

typeSpecifier
    :
    (   Void
    |   Bool
    |   Char
    |   Int
    |   Float
    |   Double
    )
    ;

blockItemList
    :   blockItem
    |   blockItemList blockItem
    ;

blockItem
    :   statement
    |   declaration
    |   functionCall
    ;

/***************************************************
 *                                                 *
 *             D E C L A R A T I O N S             *
 *                                                 *
 **************************************************/

externalDeclaration
    :   functionDefinition
    |   declaration
    |   Semi
    ;

declaration
    locals [
        backend::TypeSpecifier type,
        char type_letter = 0
    ]
    :   typeSpecifier Identifier (Comma Identifier)* Semi
    |   typeSpecifier assignmentExpression (Comma assignmentExpression)* Semi
    ;

/***************************************************
 *                                                 *
 *                  F U N C T I O N                *
 *                                                 *
 **************************************************/

functionParameterList
    locals [
        backend::TypeSpecifier type,
        char type_letter = 0,
    ]
    :   typeSpecifier Identifier (Comma typeSpecifier Identifier)*
    ;

functionDefinition
    locals [
        string function_header,
        uint32_t num_local_vars = 0,
        size_t stack_size = 0,
    ]
    :   typeSpecifier Identifier parameterTypeList compoundStatement
    ;

parameterTypeList
    :   LeftParen functionParameterList? RightParen
    ;

functionCall
    :   Identifier LeftParen identifierList? RightParen Semi
    ;

functionReturn
    :   Identifier LeftParen identifierList? RightParen
    ;

/***************************************************
 *                                                 *
 *                S T A T E M E N T S              *
 *                                                 *
 **************************************************/

statement
    :   compoundStatement
    |   expressionStatement
    |   ifElseStatement
    |   iterationStatement
    |   assignmentStatement
    |   jumpStatement
    |   unaryStatement Semi
    ;

compoundStatement
    locals [
        string scope_name = "Anonymous"
    ]
    :   LeftBrace blockItemList? RightBrace
    ;

expressionStatement
    :   expression? Semi
    ;

ifElseStatement
    :   ifStatement elseIfStatement* elseStatement*
    ;

ifStatement
    :   If LeftParen conditionalExpression RightParen statement
    ;

elseIfStatement
    locals [
        uint32_t id = 0
    ]
    :   Else If LeftParen conditionalExpression RightParen statement
    ;

elseStatement
    :   Else statement
    ;

iterationStatement
    :   While LeftParen conditionalExpression RightParen statement
    ;

assignmentStatement
    :   assignmentExpression Semi
    ;

jumpStatement
    :   Return expression? Semi
    ;

unaryStatement
    locals [
        backend::TypeSpecifier type,
        char type_letter = '?'
    ]
    :   PlusPlus   Identifier  # unaryIncrementStatement
    |   MinusMinus Identifier  # unaryDecrementStatement
    |   Identifier PlusPlus    # unaryIncrementStatement
    |   Identifier MinusMinus  # unaryDecrementStatement
    |   Identifier Power       # unarySquareStatement
    ;

/***************************************************
 *                                                 *
 *               E X P R E S S I O N S             *
 *                                                 *
 **************************************************/

identifierList
    :   expression (Comma expression)*
    ;

expression
    locals [
        backend::TypeSpecifier type,
        string expr_operator,
        char type_letter = '?'
    ]
    :   expression opr=( '*' | '/' | '%' ) expression                       # mulDivExpr
    |   expression opr=( '+' | '-' ) expression                             # addminExpr
    |   expression opr=( '<<' | '>>' | '&' | '|' | '~' | '^' ) expression   # bitExpr
    |   primaryExpression                                                   # primExpr
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
        backend::TypeSpecifier type,
        char type_letter = 0,
        uint32_t current_nesting_level = 0
    ]
    :   Identifier Assign expression
    |   Identifier Assign functionReturn
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
    :   '&&'
    |   'and'
    ;

OrOr
    :   '||'
    |   'or'
    ;
Not
    :   '!'
    |   'not'
    ;

Equal
    :   '=='
    |   'is'
    ;

NotEqual
    :   '!='
    |   'is not'
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
