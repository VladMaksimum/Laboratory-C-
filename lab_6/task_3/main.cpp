#include <iostream>



int main()
{

    const int n_max = 100;
    int a_j[n_max][n_max];
    int sum[n_max];
    char n_min;

    int n,m;
    std::cin >> n >> m;
    long long min=INT_MAX * n;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            std::cin >> a_j[i][j];

    for(int j=0;j<m;j++)
    {
        sum[j]=0;
        for(int i=0;i<n;i++)
        {
            sum[j]+=a_j[i][j];
        }

        if(sum[j]<min)
        {
            min=sum[j];
            n_min=j;
        }
    }


    for(int i=0;i<n;i++)
    {
        a_j[i][n_min]+=3;
    }

    std::cout << std::endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout << a_j[i][j] << " ";
            
        }
        std::cout << std::endl;
    }

    return 0;
}


