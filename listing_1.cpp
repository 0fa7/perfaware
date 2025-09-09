
int __attribute__ ((noinline)) listing_1(const int a, const int b)
{
    return a + b;
}

int main()
{
    return listing_1(1234, 5678);
}