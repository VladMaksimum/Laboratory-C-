#include <iostream>
#include <string>
#include <fstream>
#include "func.hpp"


void read(int& cnt, std::string words[n_max])
{
    std::ifstream in("text.txt");

    cnt=0;
    while(!in.eof())
    {
        in >> words[cnt];
        cnt++;
    }
    
    return;
}

void write(int cnt, std::string words[n_max], int vowel_counter[n_max])
{
    std::ofstream out("result.txt");

    for(int i=0;i<cnt;i++)
    {
        out << "<" << words[i] << "> " << vowel_counter[i] << std::endl;
    }

    return;

}

void clean_words(int cnt, std::string words[n_max])
{
    for(int i=0;i<cnt;i++)
        for(int j=0; j<words[i].length();j++)
        {
            if(!isalpha(words[i][j]))
            {
                words[i].erase(j,1);
            }
        }
}

void lower_case(int cnt, std::string words[n_max])
{
    for(int i=0; i<cnt; i++)
        for(int j=0; j<words[i].length(); j++)
        {
            words[i][j]=tolower(words[i][j]);
        }
}


bool find_palindrome(int cnt, std::string words[n_max])
{
    
    for(int i=0;i<cnt;i++)
    {
        if(words[i].length()>1)
        {
            bool flag = true;
            for(int j=0;j< (words[i].length())/2 ;j++)
            {
                if(words[i][j] != words[i][words[i].length()-j-1])
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
                return true;
        }

        else
            continue;
    }

    return false;
    
}

void count_letters(int cnt, std::string words[n_max], int vowel_counter[n_max])
{
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<words[i].length(); j++)
        {
            if(words[i][j]=='a' || words[i][j]=='e' || words[i][j]=='i' || words[i][j]=='o' || words[i][j]=='u' || words[i][j]=='y')
            {
                vowel_counter[i]++;
            }
        }
    }
}

void sort_vowels(int cnt, std::string words[n_max], int vowel_counter[n_max])
{
    for(int i=0; i<cnt-1;i++)
        for(int j=i+1; j<cnt; j++)
        {
            if(vowel_counter[i] < vowel_counter[j])
            {
                std::swap(words[i], words[j]);
                std::swap(vowel_counter[i], vowel_counter[j]);
            }
        }
}

void sort_alphabet(int cnt, std::string words[n_max], int vowel_counter[n_max])
{
    for(int i=0; i<cnt-1;i++)
        for(int j=i+1; j<cnt; j++)
        {
            if(words[i][0] > words[j][0])
            {
                std::swap(words[i], words[j]);
                std::swap(vowel_counter[i], vowel_counter[j]);
            }
        }
}

void duplicate(int cnt, std::string words[n_max])
{
    for(int i=0; i<cnt-1;i++)
        for(int j=0; j<words[i].length(); j++)
        {
            if(words[i][j]=='a' || words[i][j]=='e' || words[i][j]=='i' || words[i][j]=='o' || words[i][j]=='u' || 
                words[i][j]=='y')
            {
                words[i].insert(j, 1, words[i][j]);
                j++;
            }
        }
}
