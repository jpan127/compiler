/**
 * <h1>PascalNumberToken</h1>
 *
 * <p>Pascal number tokens (integer and real).</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <map>
#include <math.h>
#include "PascalNumberToken.h"
#include "../PascalError.h"

namespace wci { namespace frontend { namespace pascal { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;

int PascalNumberToken::MAX_EXPONENT = 37;

PascalNumberToken::PascalNumberToken(Source *source) throw (string)
    : PascalToken(source)
{
    extract();
}

/**
 * Extract a Pascal number token from the source.
 * @throws Exception if an error occurred.
 */
void PascalNumberToken::extract() throw (string)
{
    string whole_digits = "";     // digits before the decimal point
    string fraction_digits = "";  // digits after the decimal point
    string exponent_digits = "";  // exponent digits
    char exponent_sign = '+';     // exponent sign '+' or '-'
    bool saw_dot_dot = false;     // true if saw .. token
    char current_ch;              // current character

    // Assume INTEGER token type for now.
    type = (TokenType) PT_INTEGER;

    // Extract the digits of the whole part of the number.
    whole_digits = unsigned_integer_digits();

    if (type == (TokenType) PT_ERROR) return;

    // Is there a . ?
    // It could be a decimal point or the start of a .. token.
    current_ch = current_char();
    if (current_ch == '.')
    {
        if (peek_char() == '.')
        {
            saw_dot_dot = true;  // it's a ".." token, so don't consume it
        }
        else
        {
            // Decimal point, so token type is REAL.
            type = (TokenType) PT_REAL;
            text += current_ch;
            current_ch = next_char();  // consume decimal point

            // Collect the digits of the fraction part of the number.
            fraction_digits = unsigned_integer_digits();
            if (type == (TokenType) PT_ERROR)
            {
                return;
            }
        }
    }

    // Is there an exponent part?
    // There cannot be an exponent if we already saw a ".." token.
    current_ch = current_char();
    if (!saw_dot_dot && ((current_ch == 'E') || (current_ch == 'e')))
    {
        // Exponent, so token type is REAL.
        type = (TokenType) PT_REAL;
        text += current_ch;
        current_ch = next_char();  // consume 'E' or 'e'

        // Exponent sign?
        if ((current_ch == '+') || (current_ch == '-'))
        {
            text += current_ch;
            exponent_sign = current_ch;
            current_ch = next_char();  // consume '+' or '-'
        }

        // Extract the digits of the exponent.
        exponent_digits = unsigned_integer_digits();
    }

    // Compute the value of an integer number token.
    if (type == (TokenType) PT_INTEGER)
    {
        int integer_value = compute_integer_value(whole_digits);

        if (type != (TokenType) PT_ERROR)
        {
            value = integer_value;
        }
    }

    // Compute the value of a real number token.
    else if (type == (TokenType) PT_REAL)
    {
        float float_value = compute_float_value(whole_digits,
                                                fraction_digits,
                                                exponent_digits,
                                                exponent_sign);

        if (type != (TokenType) PT_ERROR)
        {
            value = float_value;
        }
    }
}

/**
 * Extract and return the digits of an unsigned integer.
 * @param textBuffer the buffer to append the token's characters.
 * @return the string of digits.
 * @throws Exception if an error occurred.
 */
string PascalNumberToken::unsigned_integer_digits() throw (string)
{
    char current_ch = current_char();

    // Must have at least one digit.
    if (!isdigit(current_ch))
    {
        type = (TokenType) PT_ERROR;
        value = (int) INVALID_NUMBER;
        return "";
    }

    // Extract the digits.
    string digits = "";
    while (isdigit(current_ch))
    {
        text += current_ch;
        digits += current_ch;
        current_ch = next_char();  // consume digit
    }

    return digits;
}

/**
 * Compute and return the integer value of a string of digits.
 * Check for overflow.
 * @param digits the string of digits.
 * @return the integer value.
 */
int PascalNumberToken::compute_integer_value(string digits)
{
    // Return 0 if no digits.
    if (digits == "") return 0;

    int integer_value = 0;
    int prev_value = -1;    // overflow occurred if prevValue > integerValue
    int index = 0;

    // Loop over the digits to compute the integer value
    // as long as there is no overflow.
    while ((index < digits.length()) && (integer_value >= prev_value))
    {
        prev_value = integer_value;
        integer_value = 10*integer_value + (digits[index] - '0');
        index++;
    }

    // No overflow:  Return the integer value.
    if (integer_value >= prev_value) return integer_value;

    // Overflow:  Set the integer out of range error.
    else {
        type = (TokenType) PT_ERROR;
        value = (int) RANGE_INTEGER;
        return 0;
    }
}

/**
 * Compute and return the float value of a real number.
 * @param whole_digits the string of digits before the decimal point.
 * @param fraction_digits the string of digits after the decimal point.
 * @param exponent_digits the string of exponent digits.
 * @param exponent_sign the exponent sign.
 * @return the float value.
 */
float PascalNumberToken::compute_float_value(string whole_digits,
                                             string fraction_digits,
                                             string exponent_digits,
                                             char exponent_sign)
{
    double float_value = 0.0;
    int exponent_value = compute_integer_value(exponent_digits);
    string digits = whole_digits;  // whole and fraction digits

    // Negate the exponent if the exponent sign is '-'.
    if (exponent_sign == '-') exponent_value = -exponent_value;

    // If there are any fraction digits, adjust the exponent value
    // and append the fraction digits.
    if (fraction_digits != "")
    {
        exponent_value -= fraction_digits.length();
        digits += fraction_digits;
    }

    // Check for a real number out of range error.
    int whole_length = whole_digits.length();
    if (abs(exponent_value + whole_length) > MAX_EXPONENT)
    {
        type = (TokenType) PT_ERROR;
        value = (int) RANGE_REAL;
        return 0.0f;
    }

    // Loop over the digits to compute the float value.
    int index = 0;
    while (index < digits.length()) {
        float_value = 10*float_value + (digits[index] - '0');
        index++;
    }

    // Adjust the float value based on the exponent value.
    if (exponent_value != 0) {
        float_value *= pow(10, exponent_value);
    }

    return float_value;
}

}}}}  // namespace wci::frontend::pascal::tokens
