#include "JavaToken.hpp"

#include <string>
#include <vector>
#include <map>

#include "../../Globals.h"

namespace wci::frontend::java
{

    using namespace std;

    /// Static variables
    map <string, JavaTokenType> JavaToken::RESERVED_WORDS;
    map <string, JavaTokenType> JavaToken::SPECIAL_SYMBOLS;
    map <JavaTokenType, string> JavaToken::SPECIAL_SYMBOL_NAMES;

    bool JavaToken::is_initialized = false;

    /// Post Increment operator
    JavaTokenType& operator++(JavaTokenType& token, int)
    {
        token++;
        return token;
    }

    JavaToken::JavaToken(Source *source) : Token(source)
    {
    }

    void JavaToken::initialize()
    {
        if (!is_initialized)
        {
            // Get enum token from string
            RESERVED_WORDS["abstract"]  = JavaTokenType::token_abstract;
            RESERVED_WORDS["break"]     = JavaTokenType::token_break;
            RESERVED_WORDS["case"]      = JavaTokenType::token_case;
            RESERVED_WORDS["char"]      = JavaTokenType::token_char;
            RESERVED_WORDS["class"]     = JavaTokenType::token_class;
            RESERVED_WORDS["const"]     = JavaTokenType::token_const;
            RESERVED_WORDS["continue"]  = JavaTokenType::token_continue;
            RESERVED_WORDS["do"]        = JavaTokenType::token_do;
            RESERVED_WORDS["double"]    = JavaTokenType::token_double;
            RESERVED_WORDS["else"]      = JavaTokenType::token_else;
            RESERVED_WORDS["enum"]      = JavaTokenType::token_enum;
            RESERVED_WORDS["extends"]   = JavaTokenType::token_extends;
            RESERVED_WORDS["float"]     = JavaTokenType::token_float;
            RESERVED_WORDS["for"]       = JavaTokenType::token_for;
            RESERVED_WORDS["goto"]      = JavaTokenType::token_goto;
            RESERVED_WORDS["if"]        = JavaTokenType::token_if;
            RESERVED_WORDS["int"]       = JavaTokenType::token_int;
            RESERVED_WORDS["long"]      = JavaTokenType::token_long;
            RESERVED_WORDS["native"]    = JavaTokenType::token_native;
            RESERVED_WORDS["return"]    = JavaTokenType::token_return;
            RESERVED_WORDS["short"]     = JavaTokenType::token_short;
            RESERVED_WORDS["package"]   = JavaTokenType::token_package;
            RESERVED_WORDS["protected"] = JavaTokenType::token_protected;
            RESERVED_WORDS["static"]    = JavaTokenType::token_static;
            RESERVED_WORDS["switch"]    = JavaTokenType::token_switch;
            RESERVED_WORDS["super"]     = JavaTokenType::token_super;
            RESERVED_WORDS["this"]      = JavaTokenType::token_this;
            RESERVED_WORDS["throw"]     = JavaTokenType::token_throw;
            RESERVED_WORDS["void"]      = JavaTokenType::token_void;
            RESERVED_WORDS["volatile"]  = JavaTokenType::token_volatile;
            RESERVED_WORDS["while"]     = JavaTokenType::token_while;

            // Get string from character/string
            SPECIAL_SYMBOLS["~"]    = JavaTokenType::token_negate;                           
            SPECIAL_SYMBOLS["!"]    = JavaTokenType::token_not;                              
            SPECIAL_SYMBOLS["@"]    = JavaTokenType::token_annotation;                             
            SPECIAL_SYMBOLS["%"]    = JavaTokenType::token_modulus;                          
            SPECIAL_SYMBOLS["^"]    = JavaTokenType::token_xor;                              
            SPECIAL_SYMBOLS["&"]    = JavaTokenType::token_and;                              
            SPECIAL_SYMBOLS["*"]    = JavaTokenType::token_multiply;                         
            SPECIAL_SYMBOLS["-"]    = JavaTokenType::token_minus;                            
            SPECIAL_SYMBOLS["+"]    = JavaTokenType::token_add;                              
            SPECIAL_SYMBOLS["="]    = JavaTokenType::token_assign;                           
            SPECIAL_SYMBOLS["|"]    = JavaTokenType::token_or;                         
            SPECIAL_SYMBOLS["/"]    = JavaTokenType::token_divide;                           
            SPECIAL_SYMBOLS[":"]    = JavaTokenType::token_colon;                            
            SPECIAL_SYMBOLS[";"]    = JavaTokenType::token_semicolon;                              
            SPECIAL_SYMBOLS["?"]    = JavaTokenType::token_ternary;                          
            SPECIAL_SYMBOLS["<"]    = JavaTokenType::token_less_than;                              
            SPECIAL_SYMBOLS[">"]    = JavaTokenType::token_greater_than;                           
            SPECIAL_SYMBOLS["."]    = JavaTokenType::token_dot;                              
            SPECIAL_SYMBOLS[","]    = JavaTokenType::token_comma;                            
            SPECIAL_SYMBOLS["'"]    = JavaTokenType::token_single_quote;                           
            SPECIAL_SYMBOLS["\""]   = JavaTokenType::token_double_quote;            ///< Needs escaping
            SPECIAL_SYMBOLS["("]    = JavaTokenType::token_opening_parentheses;          
            SPECIAL_SYMBOLS[")"]    = JavaTokenType::token_closing_parentheses;          
            SPECIAL_SYMBOLS["["]    = JavaTokenType::token_opening_bracket;              
            SPECIAL_SYMBOLS["]"]    = JavaTokenType::token_closing_bracket;              
            SPECIAL_SYMBOLS["{"]    = JavaTokenType::token_opening_curly;           
            SPECIAL_SYMBOLS["}"]    = JavaTokenType::token_closing_curly;           
            SPECIAL_SYMBOLS["++"]   = JavaTokenType::token_increment;               
            SPECIAL_SYMBOLS["--"]   = JavaTokenType::token_decrement;               
            SPECIAL_SYMBOLS["<<"]   = JavaTokenType::token_shift_left;              
            SPECIAL_SYMBOLS[">>"]   = JavaTokenType::token_shift_right;             
            SPECIAL_SYMBOLS["<="]   = JavaTokenType::token_less_than_or_equal;           
            SPECIAL_SYMBOLS[">="]   = JavaTokenType::token_greater_than_or_equal;              
            SPECIAL_SYMBOLS["+="]   = JavaTokenType::token_plus_equal;              
            SPECIAL_SYMBOLS["-="]   = JavaTokenType::token_minus_equal;             
            SPECIAL_SYMBOLS["*="]   = JavaTokenType::token_multiply_equal;          
            SPECIAL_SYMBOLS["/="]   = JavaTokenType::token_divide_equal;            
            SPECIAL_SYMBOLS["=="]   = JavaTokenType::token_equal;                   
            SPECIAL_SYMBOLS["|="]   = JavaTokenType::token_or_equal;                
            SPECIAL_SYMBOLS["%="]   = JavaTokenType::token_mod_equal;               
            SPECIAL_SYMBOLS["&="]   = JavaTokenType::token_and_equal;               
            SPECIAL_SYMBOLS["^="]   = JavaTokenType::token_xor_equal;               
            SPECIAL_SYMBOLS["!="]   = JavaTokenType::token_not_equal;               
            SPECIAL_SYMBOLS["<<="]  = JavaTokenType::token_shift_left_equal;             
            SPECIAL_SYMBOLS[">>="]  = JavaTokenType::token_shift_right_equal;            
            SPECIAL_SYMBOLS["||"]   = JavaTokenType::token_boolean_or;              
            SPECIAL_SYMBOLS["&&"]   = JavaTokenType::token_boolean_and;             
            SPECIAL_SYMBOLS["//"]   = JavaTokenType::token_single_comment;
            SPECIAL_SYMBOLS["/*"]   = JavaTokenType::token_opening_multi_comment;
            SPECIAL_SYMBOLS["*/"]   = JavaTokenType::token_closing_multi_comment;

            // Get string from token enum
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_negate]                = "token_negate";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_not]                   = "token_not";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_annotation]            = "token_annotation";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_modulus]               = "token_modulus";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_xor]                   = "token_xor";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_and]                   = "token_and";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_multiply]              = "token_multiply";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_minus]                 = "token_minus";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_add]                   = "token_add";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_assign]                = "token_assign";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_or]                    = "token_or";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_divide]                = "token_divide";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_colon]                 = "token_colon";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_semicolon]             = "token_semicolon";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_ternary]               = "token_ternary";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_less_than]             = "token_less_than";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_greater_than]          = "token_greater_than";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_dot]                   = "token_dot";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_comma]                 = "token_comma";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_single_quote]          = "token_single_quote";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_double_quote]          = "token_double_quote";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_opening_parentheses]   = "token_opening_parentheses";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_closing_parentheses]   = "token_closing_parentheses";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_opening_bracket]       = "token_opening_bracket";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_closing_bracket]       = "token_closing_bracket";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_opening_curly]         = "token_opening_curly";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_closing_curly]         = "token_closing_curly";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_increment]             = "token_increment";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_decrement]             = "token_decrement";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_shift_left]            = "token_shift_left";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_shift_right]           = "token_shift_right";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_less_than_or_equal]    = "token_less_than_or_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_greater_than_or_equal] = "token_greater_than_or_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_plus_equal]            = "token_plus_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_minus_equal]           = "token_minus_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_multiply_equal]        = "token_multiply_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_divide_equal]          = "token_divide_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_equal]                 = "token_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_or_equal]              = "token_or_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_mod_equal]             = "token_mod_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_and_equal]             = "token_and_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_xor_equal]             = "token_xor_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_not_equal]             = "token_not_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_shift_left_equal]      = "token_shift_left_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_shift_right_equal]     = "token_shift_right_equal";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_boolean_or]            = "token_boolean_or";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_boolean_and]           = "token_boolean_and";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_single_comment]        = "token_single_comment";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_opening_multi_comment] = "token_opening_multi_comment";
            SPECIAL_SYMBOL_NAMES[JavaTokenType::token_closing_multi_comment] = "token_closing_multi_comment";

            is_initialized = true;
        }
    }

} /// namespace wci::frontend::java
