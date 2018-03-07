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
map<PascalTokenType, string> PascalToken::token_to_string_map =
{
    { PascalTokenType::AND             , "AND"            },
    { PascalTokenType::ARRAY           , "ARRAY"          },
    { PascalTokenType::BEGIN           , "BEGIN"          },
    { PascalTokenType::CASE            , "CASE"           },
    { PascalTokenType::CONST           , "CONST"          },
    { PascalTokenType::DIV             , "DIV"            },
    { PascalTokenType::DO              , "DO"             },
    { PascalTokenType::DOWNTO          , "DOWNTO"         },
    { PascalTokenType::ELSE            , "ELSE"           },
    { PascalTokenType::END             , "END"            },
    { PascalTokenType::FILE            , "FILE"           },
    { PascalTokenType::FOR             , "FOR"            },
    { PascalTokenType::FUNCTION        , "FUNCTION"       },
    { PascalTokenType::GOTO            , "GOTO"           },
    { PascalTokenType::IF              , "IF"             },
    { PascalTokenType::IN              , "IN"             },
    { PascalTokenType::LABEL           , "LABEL"          },
    { PascalTokenType::MOD             , "MOD"            },
    { PascalTokenType::NIL             , "NIL"            },
    { PascalTokenType::NOT             , "NOT"            },
    { PascalTokenType::OF              , "OF"             },
    { PascalTokenType::OR              , "OR"             },
    { PascalTokenType::PACKED          , "PACKED"         },
    { PascalTokenType::PROCEDURE       , "PROCEDURE"      },
    { PascalTokenType::PROGRAM         , "PROGRAM"        },
    { PascalTokenType::RECORD          , "RECORD"         },
    { PascalTokenType::REPEAT          , "REPEAT"         },
    { PascalTokenType::SET             , "SET"            },
    { PascalTokenType::THEN            , "THEN"           },
    { PascalTokenType::TO              , "TO"             },
    { PascalTokenType::TYPE            , "TYPE"           },
    { PascalTokenType::UNTIL           , "UNTIL"          },
    { PascalTokenType::VAR             , "VAR"            },
    { PascalTokenType::WHILE           , "WHILE"          },
    { PascalTokenType::WITH            , "WITH"           },
    { PascalTokenType::PLUS            , "PLUS"           },
    { PascalTokenType::MINUS           , "MINUS"          },
    { PascalTokenType::STAR            , "STAR"           },
    { PascalTokenType::SLASH           , "SLASH"          },
    { PascalTokenType::COLON_EQUALS    , "COLON_EQUALS"   },
    { PascalTokenType::DOT             , "DOT"            },
    { PascalTokenType::COMMA           , "COMMA"          },
    { PascalTokenType::SEMICOLON       , "SEMICOLON"      },
    { PascalTokenType::COLON           , "COLON"          },
    { PascalTokenType::QUOTE           , "QUOTE"          },
    { PascalTokenType::EQUALS          , "EQUALS"         },
    { PascalTokenType::NOT_EQUALS      , "NOT_EQUALS"     },
    { PascalTokenType::LESS_THAN       , "LESS_THAN"      },
    { PascalTokenType::LESS_EQUALS     , "LESS_EQUALS"    },
    { PascalTokenType::GREATER_EQUALS  , "GREATER_EQUALS" },
    { PascalTokenType::GREATER_THAN    , "GREATER_THAN"   },
    { PascalTokenType::LEFT_PAREN      , "LEFT_PAREN"     },
    { PascalTokenType::RIGHT_PAREN     , "RIGHT_PAREN"    },
    { PascalTokenType::LEFT_BRACKET    , "LEFT_BRACKET"   },
    { PascalTokenType::RIGHT_BRACKET   , "RIGHT_BRACKET"  },
    { PascalTokenType::LEFT_BRACE      , "LEFT_BRACE"     },
    { PascalTokenType::RIGHT_BRACE     , "RIGHT_BRACE"    },
    { PascalTokenType::UP_ARROW        , "UP_ARROW"       },
    { PascalTokenType::DOT_DOT         , "DOT_DOT"        },
    { PascalTokenType::IDENTIFIER      , "IDENTIFIER"     },
    { PascalTokenType::INTEGER         , "INTEGER"        },
    { PascalTokenType::REAL            , "REAL"           },
    { PascalTokenType::STRING          , "STRING"         },
    { PascalTokenType::ERROR           , "ERROR"          },
    { PascalTokenType::END_OF_FILE     , "END_OF_FILE"    },
};

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
