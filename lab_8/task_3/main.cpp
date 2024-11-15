#include <iostream>
#include "func.hpp"
#include <string>


int main()
{
    const int n_max=2000;
    const int p_max=4;
    int cnt;
    std::string words[n_max];
    char popular_letters[p_max];

    read(cnt,words);

    find_popular_letters(cnt,words,popular_letters);
    two_popular_in_row(cnt,words,popular_letters);

    write(cnt,words);

    return 0;
}


