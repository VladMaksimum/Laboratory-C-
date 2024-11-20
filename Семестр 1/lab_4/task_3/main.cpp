#include <iostream>


int main()
{
    short x;
    
    std::cout << "x=";
    std::cin >> x;

    switch(x)
    {
        case 1:
            std::cout << "Positive number";
            break;
        case -1:
            std::cout << "Negative number";
            break;
        default:
            std::cout << "Input error";
            break;
    }
    
    return 0;
}
