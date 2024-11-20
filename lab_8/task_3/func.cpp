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

void write(int cnt, std::string words[n_max])
{
    std::ofstream out("result.txt");

    for(int i=0;i<cnt;i++)
    {
        out << words[i] << " ";
    }

    return;

}

void find_popular_letters(int cnt, std::string words[n_max], unsigned char popular_letters[p_max])
{
    unsigned char letters[256]={0};
    for(int i=0; i<cnt; i++)
        for(int j=0; j<words[i].length();j++)
        {
            if(isalpha(words[i][j]))
                letters[tolower(words[i][j])]++;
        }
    

    for(int i=0; i<p_max; i++)
    {
        int max=INT_MIN;
        char index=-1;
        for(int j=0; j<256;j++)
        {
            if(letters[j]>max)
            {
                max=letters[j];
                index=j;
            }
        }

        popular_letters[i]= index;
        letters[index]=0;
    }
}

void two_popular_in_row(int cnt, std::string words[n_max], unsigned char popular_letters[p_max])
{
    for(int i=0;i<cnt; i++)
    {
        int len=words[i].length();
        for(int j=0; j< len - 1;j++)
        {
            if((tolower(words[i][j])==popular_letters[0] || tolower(words[i][j])==popular_letters[1] || 
                tolower(words[i][j])==popular_letters[2] || tolower(words[i][j])==popular_letters[3]) && 
                (tolower(words[i][j+1])==popular_letters[0] || tolower(words[i][j+1])==popular_letters[1] || 
                tolower(words[i][j+1])==popular_letters[2] || tolower(words[i][j+1])==popular_letters[3]))
            {
                words[i][j]=toupper(words[i][j]);
                words[i][j+1]=toupper(words[i][j+1]);
                words[i]= words[i] + "(" + words[i][j] + words[i][j+1] + ")";
            }
        }
    }
}
