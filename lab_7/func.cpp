#include <iostream>
#include "func.hpp"


void read(int& n, int matrix[n_max][n_max])
{
    std::cout << "n=";
    std::cin >> n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                std::cin >> matrix[i][j];
            }
    
    return;
}


void write(int n, int matrix[n_max][n_max])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                std::cout << matrix[i][j] << " ";
            }
        std::cout << std::endl;
    }

    return;     
}


bool same_row(int n, int matrix[n_max][n_max])
{
    


}
