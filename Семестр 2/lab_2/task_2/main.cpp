#include <iostream>
#include "func.hpp"


int main()
{
    int mass[100];
    int n;

    read(mass, n);

    quick_sort(n-1,0,mass);
    //swap_sort(mass,n);

    write(mass, n);

    return 0;
}
