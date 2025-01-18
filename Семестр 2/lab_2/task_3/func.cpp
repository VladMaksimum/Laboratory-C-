#include <iostream>
#include <fstream>
#include "func.hpp"

void read(char map[n_max][n_max],int& n, int& m)
{
    std::ifstream in("input.txt");

    in >> n;
    in >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            in >> map[i][j];
        }
}

void write(int table[n_max][n_max], int n ,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void find_end_start(int& is, int& js, int& ie, int& je, char map[n_max][n_max], int n, int m,int table[n_max][n_max])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(map[i][j]=='S')
            {
                is=i;
                js=j;
            }
            else
            {
                table[i][j]=INT_MAX;
            }
        }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(map[i][j]=='E')
            {
                ie=i;
                je=j;
                break;
            }
        }
}

void search(char map[n_max][n_max], int i, int j, int steps, int n, int m, int table[n_max][n_max])
{
    table[i][j] = steps;
    if(map[i][j]=='E')
        return;
        
    if(table[i][j]+1 <= table[i+1][j] && !(i+1>n || j>m || map[i+1][j]=='#'))
        search(map, i+1, j, steps+1, n,m, table);
    if(table[i][j]+1 <= table[i-1][j]  && !(i-1>n || j>m || map[i-1][j]=='#'))
        search(map, i-1, j, steps+1, n,m, table);
    if(table[i][j]+1 <= table[i][j+1]  && !(i>n || j+1>m || map[i][j+1]=='#'))
        search(map, i, j+1, steps+1, n,m, table);
    if(table[i][j]+1 <= table[i][j-1]  && !(i>n || j-1>m || map[i][j-1]=='#'))
        search(map, i, j-1, steps+1, n,m, table);
    if(table[i][j]+1 <= table[i+1][j+1]  && !(i+1>n || j+1>m || map[i+1][j+1]=='#'))
        search(map, i+1, j+1, steps+1, n,m, table);
    if(table[i][j]+1 <= table[i+1][j-1]  && !(i+1>n || j-1>m || map[i+1][j-1]=='#'))
        search(map, i+1, j-1, steps+1, n,m, table);
    if(table[i][j]+1 <= table[i-1][j+1]  && !(i-1>n || j+1>m || map[i-1][j+1]=='#'))
        search(map, i-1, j+1, steps+1, n,m, table);
    if(table[i][j]+1 <= table[i-1][j-1]  && !(i-1>n || j-1>m || map[i-1][j-1]=='#'))
        search(map, i-1, j-1, steps+1, n,m, table);
}
