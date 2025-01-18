#include <iostream>
#include "func.hpp"


int main()
{
    char map[n_max][n_max];
    int table[n_max][n_max];
    int n,m;
    int is;
    int js;
    int ie;
    int je;

    read(map, n, m);
    
    find_end_start(is,js,ie,je,map,n,m,table);
    search(map,is,js,0,n,m,table);
    //write(table,n,m);

    if(table[ie][je]==INT_MAX)
        std::cout << -1;
    else
        std::cout << table[ie][je];

    return 0;
}
