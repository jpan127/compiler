/// Arithmetic

void arithmetic(void)
{
    uint32_t x = 0;

    x += 0x1234;
    x -= 0x1234;
    x /= 0x1234;
    x *= 0x1234;
    x ^= 0x1234;
    x ~= 0x1234;
    x |= 0x1234;
    x &= 0x1234;

    uint32_t y = 0xFFFFFFFF;

    y = x + 9999;
    y = x - 9999;
    y = x / 9999;
    y = x * 9999;
    y = x ^ 9999;
    y = x | 9999;
    y = x & 9999;

    uint32_t z  = ((x & (1 << 0)) >> (31 - 0)) |
                  ((x & (1 << 1)) >> (31 - 1)) |
                  ((x & (1 << 2)) >> (31 - 2)) |
                  ((x & (1 << 3)) >> (31 - 3)) |
                  ((x & (1 << 4)) >> (31 - 4)) |
                  ((x & (1 << 5)) >> (31 - 4));
                        
    const bool a = false;
    const bool b = true;
    const bool c = false;
    const bool d = true;
    const bool e = false;
    const bool f = true;

    if (a)                               { }
    else if (b)                          { }
    else if (c)                          { }
    else if (!d)                         { }
    else if (e && !f)                    { }
    else if (a || b || c || d || e || f) { }
    else if (a && b && c && d && e && f) { }
    else if (a is b)                     { }
    else if (c is not d)                 { }
    else if (a == b)                     { }
    else if (c != d)                     { }
    else if (a and b)                    { }
    else if (c or d)                     { }
    else                                 { }
}
