/**
 * <h1>PascalToken</h1>
 *
 * <p>Base class for Pascal token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_PASCAL_PASCALTOKEN_H_
#define WCI_FRONTEND_PASCAL_PASCALTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace wci::frontend;

/**
 * Pascal token types.
 */
enum class PascalTokenType
{
    // Reserved words.
    AND, ARRAY, BEGIN, CASE, CONST, DIV, DO, DOWNTO, ELSE, END,
    FILE, FOR, FUNCTION, GOTO, IF, IN, LABEL, MOD, NIL, NOT,
    OF, OR, PACKED, PROCEDURE, PROGRAM, RECORD, REPEAT, SET,
    THEN, TO, TYPE, UNTIL, VAR, WHILE, WITH,

    // Special symbols.
    PLUS, MINUS, STAR, SLASH, COLON_EQUALS,
    DOT, COMMA, SEMICOLON, COLON, QUOTE,
    EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS,
    GREATER_EQUALS, GREATER_THAN, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    UP_ARROW, DOT_DOT,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr PascalTokenType PT_AND = PascalTokenType::AND;
constexpr PascalTokenType PT_ARRAY = PascalTokenType::ARRAY;
constexpr PascalTokenType PT_BEGIN = PascalTokenType::BEGIN;
constexpr PascalTokenType PT_CASE = PascalTokenType::CASE;
constexpr PascalTokenType PT_CONST = PascalTokenType::CONST;
constexpr PascalTokenType PT_DIV = PascalTokenType::DIV;
constexpr PascalTokenType PT_DO = PascalTokenType::DO;
constexpr PascalTokenType PT_DOWNTO = PascalTokenType::DOWNTO;

constexpr PascalTokenType PT_ELSE = PascalTokenType::ELSE;
constexpr PascalTokenType PT_END = PascalTokenType::END;
constexpr PascalTokenType PT_FILE = PascalTokenType::FILE;
constexpr PascalTokenType PT_FOR = PascalTokenType::FOR;
constexpr PascalTokenType PT_FUNCTION = PascalTokenType::FUNCTION;
constexpr PascalTokenType PT_GOTO = PascalTokenType::GOTO;
constexpr PascalTokenType PT_IF = PascalTokenType::IF;
constexpr PascalTokenType PT_IN = PascalTokenType::IN;

constexpr PascalTokenType PT_LABEL = PascalTokenType::LABEL;
constexpr PascalTokenType PT_MOD = PascalTokenType::MOD;
constexpr PascalTokenType PT_NIL = PascalTokenType::NIL;
constexpr PascalTokenType PT_NOT = PascalTokenType::NOT;
constexpr PascalTokenType PT_OF = PascalTokenType::OF;
constexpr PascalTokenType PT_OR = PascalTokenType::OR;
constexpr PascalTokenType PT_PACKED = PascalTokenType::PACKED;
constexpr PascalTokenType PT_PROCEDURE = PascalTokenType::PROCEDURE;

constexpr PascalTokenType PT_PROGRAM = PascalTokenType::PROGRAM;
constexpr PascalTokenType PT_RECORD = PascalTokenType::RECORD;
constexpr PascalTokenType PT_REPEAT = PascalTokenType::REPEAT;
constexpr PascalTokenType PT_SET = PascalTokenType::SET;
constexpr PascalTokenType PT_THEN = PascalTokenType::THEN;
constexpr PascalTokenType PT_TO = PascalTokenType::TO;
constexpr PascalTokenType PT_TYPE = PascalTokenType::TYPE;

constexpr PascalTokenType PT_UNTIL = PascalTokenType::UNTIL;
constexpr PascalTokenType PT_VAR = PascalTokenType::VAR;
constexpr PascalTokenType PT_WHILE = PascalTokenType::WHILE;
constexpr PascalTokenType PT_WITH = PascalTokenType::WITH;

constexpr PascalTokenType PT_PLUS = PascalTokenType::PLUS;
constexpr PascalTokenType PT_MINUS = PascalTokenType::MINUS;
constexpr PascalTokenType PT_STAR = PascalTokenType::STAR;
constexpr PascalTokenType PT_SLASH = PascalTokenType::SLASH;
constexpr PascalTokenType PT_COLON_EQUALS = PascalTokenType::COLON_EQUALS;
constexpr PascalTokenType PT_DOT = PascalTokenType::DOT;
constexpr PascalTokenType PT_COMMA = PascalTokenType::COMMA;
constexpr PascalTokenType PT_SEMICOLON = PascalTokenType::SEMICOLON;
constexpr PascalTokenType PT_COLON = PascalTokenType::COLON;
constexpr PascalTokenType PT_QUOTE = PascalTokenType::QUOTE;
constexpr PascalTokenType PT_EQUALS = PascalTokenType::EQUALS;
constexpr PascalTokenType PT_NOT_EQUALS = PascalTokenType::NOT_EQUALS;

constexpr PascalTokenType PT_LESS_THAN = PascalTokenType::LESS_THAN;
constexpr PascalTokenType PT_LESS_EQUALS = PascalTokenType::LESS_EQUALS;
constexpr PascalTokenType PT_GREATER_EQUALS = PascalTokenType::GREATER_EQUALS;
constexpr PascalTokenType PT_GREATER_THAN = PascalTokenType::GREATER_THAN;
constexpr PascalTokenType PT_LEFT_PAREN = PascalTokenType::LEFT_PAREN;
constexpr PascalTokenType PT_RIGHT_PAREN = PascalTokenType::RIGHT_PAREN;
constexpr PascalTokenType PT_LEFT_BRACKET = PascalTokenType::LEFT_BRACKET;
constexpr PascalTokenType PT_RIGHT_BRACKET = PascalTokenType::RIGHT_BRACKET;
constexpr PascalTokenType PT_LEFT_BRACE = PascalTokenType::LEFT_BRACE;
constexpr PascalTokenType PT_RIGHT_BRACE = PascalTokenType::RIGHT_BRACE;
constexpr PascalTokenType PT_UP_ARROW = PascalTokenType::UP_ARROW;
constexpr PascalTokenType PT_DOT_DOT = PascalTokenType::DOT_DOT;

constexpr PascalTokenType PT_IDENTIFIER = PascalTokenType::IDENTIFIER;
constexpr PascalTokenType PT_INTEGER = PascalTokenType::INTEGER;
constexpr PascalTokenType PT_REAL = PascalTokenType::REAL;
constexpr PascalTokenType PT_STRING = PascalTokenType::STRING;
constexpr PascalTokenType PT_ERROR = PascalTokenType::ERROR;
constexpr PascalTokenType PT_END_OF_FILE = PascalTokenType::END_OF_FILE;

class PascalToken : public Token
{
public:
    static map<string, PascalTokenType> RESERVED_WORDS;
    static map<string, PascalTokenType> SPECIAL_SYMBOLS;
    static map<PascalTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    PascalToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::pascal

#endif /* WCI_FRONTEND_PASCAL_PASCALTOKEN_H_ */
