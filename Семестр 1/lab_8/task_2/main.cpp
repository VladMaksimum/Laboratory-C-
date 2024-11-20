#include <iostream>
#include "func.hpp"
#include <string>


int main()
{
    const int n_max=2000;
    int cnt;
    std::string words[n_max];
    int vowel_counter[n_max] = {0};

    read(cnt,words);
    clean_words(cnt,words);
    lower_case(cnt,words);

    if(find_palindrome(cnt,words))
    {
        count_letters(cnt,words,vowel_counter);
        sort_vowels(cnt,words,vowel_counter);
    }
    else
    {
        duplicate(cnt,words);
        sort_alphabet(cnt,words,vowel_counter);
    }

    write(cnt,words,vowel_counter);

    return 0;
}


