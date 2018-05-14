// void foo(int bar)
// {
//     bar = 5;
// }

void main()
{
    /// Initialize variables first
    int fizz_counter = 0;
    int buzz_counter = 0;

    int fizz = 5;
    int buzz = 3;
    int fizz_buzz = fizz * buzz;

    double d = 1000000;
    double e = 2;

    while (d > 0)
    {
        if (d % fizz_buzz == 0)
        {
            fizz_counter++;
            buzz_counter++;
        }
        else if (d % fizz == 0)
        {
            fizz_counter++;
        }
        else if (d % buzz == 0)
        {
            buzz_counter++;
        }
        else
        {
            e**;
        }

        d--;
    }
}
