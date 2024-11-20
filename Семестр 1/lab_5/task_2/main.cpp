#include <iostream>


int main()
{
    unsigned int N;
    std::cout << "N=";
    std::cin >> N;

    int sum;
    sum=0;

    while(N!=0)
    {
        sum+=(N%10);
        N/=10;
    }
    
    std::cout << "Result: " << sum;

    return 0;
}
