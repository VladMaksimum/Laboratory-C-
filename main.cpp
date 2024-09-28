#include <iostream>


int main()
{
    unsigned int A;
    unsigned int B;
    unsigned int C;

    std::cout << "A=";
    std::cin >> A;
    
    std::cout << "B=";
    std::cin >> B;

    std::cout << "C=";
    std::cin >> C;

    if ( ((A%C)==0) && ((B%C)==0) )
    {
        std::cout << "Result: " << (A+B)/C;
    }
    else if( ((A%C)==0) && ((B%C)!=0) )
    {
        std::cout << "Result: " << A/C +B;
    }
    else
    {
        std::cout << "Result: " << (int)(A-B-C);
    }
    
    return 0;
}