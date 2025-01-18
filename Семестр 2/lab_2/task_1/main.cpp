#include <iostream>

int sum_digits(int x)
{
    if(x<10)
        return x;
    return (x%10) + sum_digits(x/10);
}

int main()
{
    std::cout << sum_digits(569);

    return 0;
}
