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

    for(int i1=0;i1<n-1;i1++)
        for(int i2=i1+1;i2<n;i2++)
        {
            bool flag=true;

            for(int j=0;j<n;j++)
            {
                if(matrix[i1][j]!=matrix[i2][j])
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
            {
                return true;
            }
        }
    
    return false;
}


int min_in_column(int n, int j, int matrix[n_max][n_max])
{
    int min=matrix[0][j];

    for(int i=1;i<n;i++)
    {
        if(matrix[i][j]<min)
        {
            min=matrix[i][j];
        }
    }

    return min;

}
