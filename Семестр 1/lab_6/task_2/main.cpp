#include <iostream>



int main()
{
    const int n_max=1000;
    int a_j[n_max];
    char first[n_max];
    int mult[n_max];

    int n;
    std::cin >> n;
    for(int i=0;i<n;i++)
    {
        std::cin >> a_j[i];

        int d1=a_j[i];
        while(d1>9)
        {
            d1/=10;
        }
        first[i]=d1;

        int d2=a_j[i];
        int m=1;
        while(d2!=0)
        {
            m*=(d2%10);
            d2/=10;
        }
        mult[i]=m;
    }

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if((first[i]>first[j]) || 
            (first[i]==first[j] && mult[i]>mult[j]) || 
            (first[i]==first[j] && mult[i]==mult[j] && a_j[i]>a_j[j]))
            {
                int tmp1 = a_j[i];
                a_j[i]=a_j[j];
                a_j[j]=tmp1;

                char tmp2 = first[i];
                first[i]=first[j];
                first[j]=tmp2;

                int tmp3 = mult[i];
                mult[i]=mult[j];
                mult[j]=tmp3;
            }

        }

    for(int i=0;i<n;i++)
        std::cout << a_j[i] << " ";


    return 0;
}


