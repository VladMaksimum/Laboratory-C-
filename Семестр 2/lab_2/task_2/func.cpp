#include <iostream>
#include "func.hpp"

void read(int* mass, int& n)
{
    std::cout << "n=";
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        int data;
        std:: cin >> data;
        mass[i]=data;
    }
}

void write(int* mass, int n)
{
    for(int i=0; i<n; i++)
        std::cout << mass[i] << " ";
}

void quick_sort(int right_side, int left_side, int* mass)
{
    int j = right_side;
    int i = left_side;
    int pivot = mass[(i+j)/2];

    while(i<=j)
    {
        while(mass[i] < pivot)
            i++;
        while(mass[j] > pivot)
            j--;
        
        if(i<=j)
        {
            std::swap(mass[i],mass[j]);
            i++;
            j--;
        }
    }

    if(j>left_side)
        quick_sort(j,left_side,mass);
    if(i<right_side)
        quick_sort(right_side,i,mass);
    
}