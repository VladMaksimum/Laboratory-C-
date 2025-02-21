#include <iostream>
#include <string>
#include <cmath>

class bint
{
    private:
        int bi_size;
        int* bi_value;

        void my_swap(bint& a, bint& b)
        {
            std::swap(a.bi_size, b.bi_size);
            std::swap(a.bi_value, b.bi_value);
        }

        int str_to_int(std::string& s)
        {
            int n = (int)s[0] - 48;
            s = s.substr(1);
            int len = s.length();

            for(int i=0; i<len; i++)
            {
                n = n*10 + (int)s[0] - 48;
                s = s.substr(1);
            }
            return n;
        }
        
    public:
    
        bint()
        {
            std::cout << "basector" << std::endl;
            bi_size = 0;
            bi_value = nullptr;
        } 

        bint(std::string value): bi_size(value.length()/9)
        {
            std::cout << "mainctor" << std::endl;
            if(value.length()%9!=0)
            {
                bi_size++;
                bi_value = new int[bi_size];
                bi_value[bi_size-1] = str_to_int(value.substr(0,value.length()%9));
                value=value.substr(value.length()%9);
            
                for(int i=bi_size-2;i>-1;i--)
                {
                    bi_value[i] = str_to_int(value.substr(0,9));
                    value=value.substr(9);
                }
            }
            else
            {
                bi_value = new int[bi_size];
                for(int i=bi_size-1;i>-1;i--)
                {
                    bi_value[i] = str_to_int(value.substr(0,9));
                    value=value.substr(9);
                }
            }
        }

        bint(const bint& other)
        {
            std::cout << "copyctor" << std::endl;
            bi_size = other.bi_size;
            bi_value = new int[bi_size];
            std::copy(other.bi_value,other.bi_value + bi_size, bi_value);
        }
        
        
        bint& operator=(bint tmp)
        {
            std::cout << "eqctor" << std::endl;
            my_swap(*this, tmp);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream &os, const bint &number)
        {
            if(number.bi_value==nullptr || (number.bi_size==1 && number.bi_value[0]==0))
            {
                os << 0;
            }
            else
            {
                for(int i=number.bi_size-1;i>-1;i--)
                {
                    if(number.bi_value[i]==0)
                    {
                        for(int i=0; i<9; i++)
                            os << 0;
                    }
                    else
                    {
                        int j =100'000'000;
                        while(number.bi_value[i]%j==number.bi_value[i] && i!=number.bi_size-1)
                        {
                            os << 0;
                            j/=10;
                        }
                        os << number.bi_value[i];
                    }
                }
            }

            return os;
        }

        friend std::istream& operator>>(std::istream& in, bint& num)
        {
            std::string s;
            in >> s;

            if(s.length()%9!=0)
            {
                num.bi_size = (s.length()/9) + 1;
                num.bi_value = new int[num.bi_size];

                num.bi_value[num.bi_size-1] = num.str_to_int(s.substr(0,s.length()%9));
                s=s.substr(s.length()%9);
            
                for(int i=num.bi_size-2;i>-1;i--)
                {
                    num.bi_value[i] = num.str_to_int(s.substr(0,9));
                    s=s.substr(9);
                }
            }
            else
            {
                num.bi_size = s.length()/9;
                num.bi_value = new int[num.bi_size];
                for(int i=num.bi_size-1;i>-1;i--)
                {
                    num.bi_value[i] = num.str_to_int(s.substr(0,9));
                    s=s.substr(9);
                }
            }

            return in;
        }

        bint operator+(const bint& other)
        {
            bint res(*this);
            res += other;
            return res;
        }

        bint& operator+=(const bint& other)
        {
            int surplus = 0;
            for(int i=0; i<std::max(this->bi_size, other.bi_size); i++)
            {
                if(i>other.bi_size-1)
                {
                    surplus = bi_value[i] / 1'000'000'000;
                    bi_value[i] = bi_value[i] % 1'000'000'000;
                }
                else
                {
                    this->bi_value[i] = bi_value[i] + other.bi_value[i];
                    surplus = bi_value[i] / 1'000'000'000;
                    bi_value[i] = bi_value[i] % 1'000'000'000;
                }

                if(i+1 == std::max(this->bi_size, other.bi_size) && surplus!=0)
                {
                    int* value = new int[bi_size+1];
                    std::copy(bi_value,bi_value + bi_size, value); 
                    value[i+1] = surplus;

                    delete[] bi_value;
                    bi_value = value;
                    bi_size++;
                }
                else
                {
                    bi_value[i+1] += surplus;
                }
            }
            return *this;
        }

        bint operator*(bint& other)
        {
            if((other.bi_size == 1 && other.bi_value[0] == 0 ) || (bi_size == 1 && bi_value[0] == 0 ))
            {
                bint r("0");
                return r;
            }
            bint res(*this);
            res *= other;
            return res;
        }

        bint& operator*=(bint& other)
        {
            std::cout << (other.bi_size == 1 && other.bi_value[0] == 0 );
            if((other.bi_size == 1 && other.bi_value[0] == 0 ) || (bi_size == 1 && bi_value[0] == 0 ))
            {
                bint r("0");
                return r;
            }
            
            bint add(*this);
            for(int i=0; other>i+1; i++)
                *this+=add;
            return *this;

        }

        bool operator<(const bint& other)
        {
            if(bi_size < other.bi_size)
                return true;
            else if(bi_size > other.bi_size)
                return false;
            else
            {
                for(int i=bi_size-1 ; i>-1; i--)
                {
                    if(bi_value[i]<other.bi_value[i])
                        return true;
                    if(bi_value[i]>other.bi_value[i])
                        return false;
                }
                return false;
            }
            
        }

        bool operator>(const bint& other)
        {
            if(bi_size > other.bi_size)
                return true;
            else if(bi_size < other.bi_size)
                return false;
            else
            {
                for(int i=bi_size-1 ; i>-1; i--)
                {
                    if(bi_value[i]>other.bi_value[i])
                        return true;
                    if(bi_value[i]<other.bi_value[i])
                        return false;
                }
                return false;
            }
            
        }

        bool operator>(int other)
        {
            if(bi_size > 1)
                return true;

            if(bi_value[0]>other)
                return true;

            return false;
        }

        bool operator==(const bint& other)
        {
            if(bi_size == other.bi_size)
            {
                for(int i=0; i<bi_size; i++)
                {
                    if(bi_value[i]!=other.bi_value[i])
                        return false;
                }
                return true;
            }
            return false;
        }

        bool operator!=(const bint& other)
        {
            bool res = *this == other;
            return !res;
        }

        ~bint()
        {
            if(bi_value!=nullptr)
                delete[] bi_value;
        }

};







int main()
{
    std::cout << "--------" << std::endl;
    bint i1("12");
    std::cout << "--------" << std::endl;
    bint i2("0");
    std::cout << "--------" << std::endl;

    //std::cin >> i1;
    std::cout << i1*i2;
    

    return 0;
}
