#include <iostream>



int main()
{

    const int n_max = 10000;
    int a_j[n_max];

    int n;
    std::cin >> n;
    for(int i=0;i<n;i++)
    {
        std::cin >> a_j[i];
    }
    

    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a_j[i]==a_j[j])
            {
                flag=true;
                break;
            }

        }
    }
    
    if(flag)
    {
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
            {
                char last_a=a_j[i]%10;
                char last_b=a_j[j]%10;

                if(last_a<last_b)
                {
                    int tmp=a_j[i];
                    a_j[i]=a_j[j];
                    a_j[j]=tmp;

                }

            } 
    
    }
    

    for(int i=0;i<n;i++)
    {
        std::cout << a_j[i] << " ";
    }


    return 0;
}


