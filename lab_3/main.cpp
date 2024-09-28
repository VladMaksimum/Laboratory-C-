#include <iostream>

//Установить i-ый бит числа x(0...10^9) 0

int main()
{
    unsigned int x;
    unsigned short i;

    std::cout << "x=";
    std::cin >> x;

    std::cout << "i=";
    std::cin >> i;

    std::cout << "Result: " << ~(~x | (1 << i));

    std::cout << "\nResult 2: " << (x & ~(1 << i));

    //5=00000'101
    //~5=11111010
    //~5 | (1 << 2)=11111110
    //~(~5 | (1 << 2))=0000000'1

    return 0;
}
