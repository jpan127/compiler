#pragma once

#include "common.hpp"
#include "logger.hpp"



/**
 *  @class : FormatStringParser
 *
 *  This class is responsible for handling a formatted string
 *  A formatted string is represented by zero or more specifiers, denoted with a preceding '%'
 */
class FormatStringParser
{

public:

    /**
     *  Constructor
     *  @param format_string : The formatted string in which subsequent operations will depend on
     */
    FormatStringParser(const std::string & format_string) : m_format_string(format_string) { }

    /**
     *  Checks if the number of specifiers matches the number of arguments
     *  @param args : The arguments that follow the format string in a printf statement
     *  @returns    : True if the number matches, false if it doesn't
     *  @TODO       : Can check if the type matches
     */
    bool check_num_specifiers_match(const std::vector <std::string> & args)
    {
        // Set of possible specifiers
        static const std::set <char> valid_specifiers =
        {
            'd', 'f', 'i', 'l', 's',
        };

        const auto logger = logger_get_default_logger();

        // For counting the number of specifiers in the format string
        uint32_t num_specifiers = 0;

        // For keeping track of a 2-state machine : currently a specifier, currently not a specifier
        bool next_char_is_specifier = false;

        // Parse the format string char by char
        for (const auto & c : m_format_string)
        {
            // If current char is a percent symbol, the next one needs to be checked
            if (format_symbol == c)
            {
                next_char_is_specifier = true;
            }
            else if (next_char_is_specifier)
            {
                // Check if specifier is valid
                const std::string c_string(1, c);
                if (valid_specifiers.find(c) != valid_specifiers.end())
                {
                    num_specifiers++;
                    logger->debug("  %{}", c_string);
                }
                else
                {
                    THROW_EXCEPTION(KeyError, "Invalid specifier : " + c_string);
                }

                next_char_is_specifier = false;
            }
        }

        return (num_specifiers == args.size());
    }

private:

    /// Preceding character of a specifier
    static constexpr char format_symbol = '%';

    /// Saved reference to format string
    const std::string & m_format_string;

};
