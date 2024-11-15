#include <iostream>
#include "func.hpp"
#include <string>


int main()
{
    const int n_max=2000;
    int n;
    int cnt;
    std::string words[n_max];
    int counter_letters[n_max] = {0};


    if(!read(n, cnt, words))
    {
        std::cout << "File not found";
        return -1;
    }

    clean_words(cnt,words);
    max_letters(cnt,words,counter_letters);
    sort(cnt,words,counter_letters);


    //full_write(n,cnt,words,counter_letters);
    final_write(n,cnt,words,counter_letters);
    

    return 0;
}


