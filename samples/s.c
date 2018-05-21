/// Global variables
int mak1 = 128;
int mak2 = 256;
int mak3 = 1;
int mak4 = -1;
float mak5 = .1;

/**
 *  Function 1
 *  Negates the input
 */
int fizzy(int f)
{
    int negate = f * -1;
    return negate;
}

/**
 *  Function 2
 *  Squares the input
 */
int buzzy(int b)
{
    int square;
    square = b;
    square**;
    return square;
}

/// Main
void main()
{
    /// Initialize variables first
    int fizz_counter = 0;
    int buzz_counter = 0;
    int fizz = 5;
    int buzz = 3;
    int fizz_buzz = fizz * buzz;

    /// Change me, try values 0, 200, in between, etc
    double d = 100;

    /// Testing floating point and signed
    double e = -1.1;

    /// While loop
    while ((d > 0) and (d < 1000))   /// Multiple conditions using the "and" operator
    {
        /// If statement
        if (d % fizz_buzz == 0)
        {
            /// Square operator, shows working on floating point
            e**;
        }
        /// Else if statement
        else if (d % fizz == 0)
        {
            /// Unary operator
            fizz_counter++;
        }
        /// Multiple else if statements, supports infinite, scalable
        else if (d % buzz == 0)
        {
            /// Unary operator
            ++buzz_counter;
        }
        /// Optional ending else statement
        else
        {
            /// Bit operations
            mak1 = mak1 ^ mak2;
            mak2 = mak2 & mak3;
            mak3 = mak3 << 1;
            mak4 = mak4 * -2;
        }

        /// Unary operator
        d--;
    }

    /// Call functions and store value in lvalue
    fizz_counter = fizzy(fizz_counter);
    buzz_counter = buzzy(buzz_counter);

    /// Function return statement
    return;
}
