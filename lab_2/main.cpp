#include <iostream>

//Программа, рассчитывающая площадь треугольника по высоте и стороне, значения которых вводятся с клавиатуры.

int main()
{
    unsigned int a;
    unsigned int h;
    std::cout << "Vvedite dlinu vysoty treugolnika: ";
    std::cin >> h;

    std::cout << "Vvedite dlinu storony treugolnika: ";
    std::cin >> a;

    std::cout << "Ploshad treugolnika ravna: " << (double)0.5*a*h;

    return 0;
}

