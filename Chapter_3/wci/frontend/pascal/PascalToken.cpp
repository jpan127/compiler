/**
 * <h1>PascalToken</h1>
 *
 * <p>Base class for Pascal token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "PascalToken.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;

map<string, PascalTokenType> PascalToken::RESERVED_WORDS;
map<string, PascalTokenType> PascalToken::SPECIAL_SYMBOLS;
map<PascalTokenType, string> PascalToken::SPECIAL_SYMBOL_NAMES;

bool PascalToken::INITIALIZED = false;

void PascalToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
        "AND", "ARRAY", "BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO",
        "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", "IF", "IN",
        "LABEL", "MOD", "NIL", "NOT", "OF", "OR", "PACKED", "PROCEDURE",
        "PROGRAM", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE",
        "UNTIL", "VAR", "WHILE", "WITH"
    };

    vector<PascalTokenType> rw_keys =
    {
        PascalTokenType::AND,
        PascalTokenType::ARRAY,
        PascalTokenType::BEGIN,
        PascalTokenType::CASE,
        PascalTokenType::CONST,
        PascalTokenType::DIV,
        PascalTokenType::DO,
        PascalTokenType::DOWNTO,

        PascalTokenType::ELSE,
        PascalTokenType::END,
        PascalTokenType::FILE,
        PascalTokenType::FOR,
        PascalTokenType::FUNCTION,
        PascalTokenType::GOTO,
        PascalTokenType::IF,
        PascalTokenType::IN,

        PascalTokenType::LABEL,
        PascalTokenType::MOD,
        PascalTokenType::NIL,
        PascalTokenType::NOT,
        PascalTokenType::OF,
        PascalTokenType::OR,
        PascalTokenType::PACKED,
        PascalTokenType::PROCEDURE,

        PascalTokenType::PROGRAM,
        PascalTokenType::RECORD,
        PascalTokenType::REPEAT,
        PascalTokenType::SET,
        PascalTokenType::THEN,
        PascalTokenType::TO,
        PascalTokenType::TYPE,

        PascalTokenType::UNTIL,
        PascalTokenType::VAR,
        PascalTokenType::WHILE,
        PascalTokenType::WITH
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "+", "-", "*", "/", ":=", ".", ",", ";", ":", "'", "=", "<>",
        "<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}",  "^", ".."
    };

    vector<PascalTokenType> ss_keys =
    {
        PascalTokenType::PLUS,
        PascalTokenType::MINUS,
        PascalTokenType::STAR,
        PascalTokenType::SLASH,
        PascalTokenType::COLON_EQUALS,
        PascalTokenType::DOT,
        PascalTokenType::COMMA,
        PascalTokenType::SEMICOLON,
        PascalTokenType::COLON,
        PascalTokenType::QUOTE,
        PascalTokenType::EQUALS,
        PascalTokenType::NOT_EQUALS,

        PascalTokenType::LESS_THAN,
        PascalTokenType::LESS_EQUALS,
        PascalTokenType::GREATER_EQUALS,
        PascalTokenType::GREATER_THAN,
        PascalTokenType::LEFT_PAREN,
        PascalTokenType::RIGHT_PAREN,
        PascalTokenType::LEFT_BRACKET,
        PascalTokenType::RIGHT_BRACKET,
        PascalTokenType::LEFT_BRACE,
        PascalTokenType::RIGHT_BRACE,
        PascalTokenType::UP_ARROW,
        PascalTokenType::DOT_DOT
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
        "PLUS", "MINUS", "STAR", "SLASH", "COLON_EQUALS", "DOT", "COMMA",
        "SEMICOLON", "COLON", "QUOTE", "EQUALS", "NOT_EQUALS",

        "LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
        "LEFT_BRACE", "RIGHT_BRACE", "UP_ARROW", "DOT_DOT"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

PascalToken::PascalToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::pascal
