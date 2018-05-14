void foo(int bar)
{
    bar = 5;
}

void main()
{
    /// Initialize variables first
    bool   a = 10;
    double b = 20;
    int    c = a * b;   /// 200
    float  d = c + c;   /// 400
    float  e = d * 5;

    int multiples_of_ten = 0;

    /// True
    if (d == 400)
    {
        while (d > 0)
        {
            d = d - 1;
            if (d % 10 == 0)
            {
                multiples_of_ten = multiples_of_ten + 1;
            }
        }
    }
}