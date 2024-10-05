#include <iostream>


int main()
{
    int n;
    std::cout << "n=";
    std::cin >> n;

    double max;
    int n_max;
    double sum;
    sum=0;
    max = INT_MIN;

    for(int i=0; i<n; i++)
    {
        double x;
        std::cin >> x;
        if(x>=-7 && x<=19)
        {
            if(x>max)
            {
                max=x;
                n_max=i+1;
            }

            sum+=x;
        }
    }


    if(max==INT_MIN)
    {
        std::cout << "No numbers in [-7...19]";
    }
    else
    {
        std::cout << "Result: "<< sum << "  " << max << "  " << n_max;
    }
    
    return 0;
}
