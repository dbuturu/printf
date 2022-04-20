

void printf_unsigned(unsigned long long number, int radix)
{
    char buffer[32];
    int pos = 0;
    const char hexChars_lower[] = "0123456789abcdef";
    const char hexChars_upper[] = "0123456789ABCDEF";

    // convert number to ASCII
    do
    {
        unsigned long long rem = number % radix;
        number /= radix;
        buffer[pos++] = g_HexChars[rem];
    } while (number > 0);

    // print number in reverse order
    while (--pos >= 0)
        putc(buffer[pos]);
}

void printf_signed(long long number, int radix)
{
    if (number < 0)
    {
        putc('-');
        printf_unsigned(-number, radix);
    }
    else printf_unsigned(number, radix);
}
