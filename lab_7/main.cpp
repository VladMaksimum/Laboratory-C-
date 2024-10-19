#include <iostream>
#include "func.hpp"


int main()
{

    int matrix[n_max][n_max];
    int n;

    std::cout << "Input" << std::endl;
    read(n,matrix);


    if(same_row(n, matrix))
    {
        for(int j=0;j<n;j++)
        {
            int min;
            min = min_in_column(n,j,matrix);

            for(int i=0; i<n; i++)
            {
                if(matrix[i][j]==min)
                {
                    matrix[i][j]=max_simple(n,matrix);
                }
            }
            
        }
    }


    std::cout << "Output" << std::endl;
    write(n,matrix);

    return 0;
}


