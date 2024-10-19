#include <iostream>
#include "func.hpp"


int main()
{

    int matrix[n_max][n_max];
    int n;

    read(n,matrix);

    if(same_row(n, matrix))
    {
        std::cout << "1";
    }

    write(n,matrix);

    return 0;
}


