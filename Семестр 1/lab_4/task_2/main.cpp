#include <iostream>


int main()
{
    unsigned short N;

    std::cout << "N=";
    std::cin >> N;

    switch(N)
    {
        case 1:
            std::cout << "Monday";
            break;
        case 2:
            std::cout << "Tuestday";
            break;
        case 3:
            std::cout << "Wednesday";
            break;
        case 4:
            std::cout << "Thursday";
            break;
        case 5:
            std::cout << "Friday";
            break;
        case 6:
            std::cout << "Saturday";
            break;
        case 7:
            std::cout << "Sunday";
            break;
        default:
            std::cout << "Input Error";
            break;
    }
    
    return 0;
}
