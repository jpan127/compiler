int mak1 = 128;
int mak2 = 256;
int mak3 = 1;
int mak4 = -1;

void fizzy(int f)
{
    int y;
    y = f;
    return;
}

void buzzy(int b)
{
    int x;
    x = b;
    return;
}

/// Function
void main(double args)
{
    /// Initialize variables first
    int fizz_counter = 0;
    int buzz_counter = 0;

    int fizz = 5;
    int buzz = 3;
    int fizz_buzz = fizz * buzz;

    /// Change me
    double d = 15;

    /// Testing floating point
    double e = 1.1;

    while (d > 0)
    {
        if (d % fizz_buzz == 0)
        {
            /// Square operator
            e**;
        }
        else if (d % fizz == 0)
        {
            /// Unary operator
            fizz_counter++;
        }
        else if (d % buzz == 0)
        {
            /// Unary operator
            ++buzz_counter;
        }
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

    fizzy(fizz_counter);

    /// Function return statement
    return;
}
