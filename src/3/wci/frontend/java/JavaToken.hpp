#pragma once

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci::frontend::java
{

    using namespace std;
    using namespace wci::frontend;

    enum class JavaTokenType
    {
        /// Keywords
        token_abstract,
        token_break,
        token_case,
        token_char,
        token_class,
        token_const,
        token_continue,
        token_do,
        token_double,
        token_else,
        token_enum,
        token_extends,
        token_float,
        token_for,
        token_goto,
        token_if,
        token_int,
        token_long,
        token_native,
        token_return,
        token_short,
        token_package,
        token_protected,
        token_static,
        token_switch,
        token_super,
        token_this,
        token_throw,
        token_void,
        token_volatile,
        token_while,

        /// Symbols and operators
        token_negate,
        token_not,
        token_annotation,
        token_modulus,
        token_xor,
        token_and,
        token_multiply,
        token_minus,
        token_add,
        token_assign,
        token_or,
        token_divide,
        token_colon,
        token_semicolon,
        token_ternary,
        token_less_than,
        token_greater_than,
        token_dot,
        token_comma,
        token_single_quote,
        token_double_quote,
        token_opening_parentheses,
        token_closing_parentheses,
        token_opening_bracket,
        token_closing_bracket,
        token_opening_curly,
        token_closing_curly,
        token_increment,
        token_decrement,
        token_shift_left,
        token_shift_right,
        token_less_than_or_equal,
        token_greater_than_or_equal,
        token_plus_equal,
        token_minus_equal,
        token_multiply_equal,
        token_divide_equal,
        token_equal,
        token_or_equal,
        token_mod_equal,
        token_and_equal,
        token_xor_equal,
        token_not_equal,
        token_shift_left_equal,
        token_shift_right_equal,
        token_boolean_or,
        token_boolean_and,
        token_single_comment,
        token_opening_multi_comment,
        token_closing_multi_comment,

        /// Identifiers
        token_identifier,
        token_character,
        token_integer,
        token_fpoint,
        token_string,

        token_error,

        /// Special characters (escaped by a backslash)
        token_escaped_single_quote,
        token_escaped_double_quote,
        token_new_line,
        token_tab,
    };

    class JavaToken : public Token
    {
    public:

        static map <string, JavaTokenType> RESERVED_WORDS;
        static map <string, JavaTokenType> SPECIAL_SYMBOLS;
        static map <JavaTokenType, string> SPECIAL_SYMBOL_NAMES;

        static void initialize();

    protected:

        /**
         * Constructor.
         * @param source the source from where to fetch the token's characters.
         * @throw a string message if an error occurred.
         */
        JavaToken(Source *source);

    private:

        static bool is_initialized;
    };

} /// namespace wci::frontend::java
