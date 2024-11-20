#include <iostream>
#include <fstream>
#include <string>
#include "func.hpp"


bool read(int& n, int& cnt, std::string words[n_max])
{
    std::ifstream in("text.txt");

    in >> n;
    if(!in.is_open())
    {
        return false;
    }

    cnt=0;
    while(!in.eof())
    {
        in >> words[cnt];
        cnt++;
    }
    
    return true;
}

void full_write(int n, int cnt, std::string words[n_max], int counter_letters[n_max])
{
    std::ofstream out("result.txt");

    for(int i=0;i<cnt;i++)
    {
        out << "<" << words[i] << "> " << counter_letters[i] <<  std::endl;
    }

    return;

}

void final_write(int n, int cnt, std::string words[n_max], int counter_letters[n_max])
{
    int i=0;
    std::ofstream out("result.txt");

    while(n!=0)
    {
        if(words[i]==words[i+1])
        {
            i++;
            continue;
        }
        out << "<" << words[i] << "> " << counter_letters[i] <<  std::endl;
        i++;
        n--;

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

void max_letters(int cnt, std::string words[n_max], int counter_letters[n_max])
{

    for(int i=0;i<cnt;i++)
    {
        char letters[256] = {0};
        
        for(int j=0;j<words[i].length();j++)
        {
            if('A' < words[i][j] && words[i][j] < 'Z')
                words[i][j]+=32;
            
            letters[words[i][j]]++;
        }

        int max=INT_MIN;
        for(int k=0;k<256;k++)
        {
            if(letters[k]>max)
            {
                max=letters[k];
            }
        }

        counter_letters[i]=max;
    }
    
    return;

}

void sort(int cnt, std::string words[n_max], int counter_letters[n_max])
{
    for(int i=0; i<cnt-1;i++)
        for(int j=i+1; j<cnt; j++)
        {
            if((words[i].length() > words[j].length()) || (words[i].length() == words[j].length() && words[i] > words[j]))
            {
                std::swap(words[i],words[j]);
                std::swap(counter_letters[i],counter_letters[j]);
            }
        }

    return;
}

void delete_unsuitable_words(int& cnt, std::string words[n_max], int counter_letters[n_max])
{
    int j=0;
    for(int i=0; i<cnt; i++)
    {
        if(counter_letters[i]<3)
        {
            continue;
        }
        
        words[j]=words[i];
        counter_letters[j]=counter_letters[i];
        j++;
    }
    cnt=j;
}

