#include <iostream>


int main()
{

    const int n_max = 10000;
    int a_j[n_max];
    bool flags[n_max];
    int mult[n_max];

    int n;
    std::cin >> n;
    for(int i=0;i<n;i++)
    {
        std::cin >> a_j[i];
    }

    for(int i=0;i<n;i++)
    {
        int x =a_j[i];
        int digits_count[10] ={0};
        while (x>0){
            digits_count[x%10]++;
            x/=10;
        }

        flags[i]=true;
        for (int j = 0; j<=9; j++){
            
            if (digits_count[j]>1) flags[i]=false;
        }

        
    }
    
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(flags[i])
        {
            continue;
        }
        a_j[k]=a_j[i];
        k++;
    }
    n=k;

    std::cout <<  std::endl;
    for(int i=0;i<n;i++)
    {
        int cur = a_j[i];
        int mult = 1;
        while (cur){
            mult*=cur%10;
            cur/=10;
        }

            if(mult%14==0)
            {
                for(int i1=n;i1>i;i1--)
                {
                    a_j[i1]=a_j[i1-1];
                }
                n++;
                i++;
            }
    }

    for(int i=0;i<n;i++)
    {
        std::cout << a_j[i] << " ";
    }

    
    return 0;
}


