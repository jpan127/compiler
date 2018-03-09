int main()
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
   
    for (uint8_t i = 1; i < 10; i++)
    {
        a += i;
        b -= i;
        c *= i;
        d /= i;
    }

    return 0;
}