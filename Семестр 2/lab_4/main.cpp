#include <iostream>
#include <string>
#include <cmath>

class bint
{
    private:
        int bi_size;
        int* bi_value;
        bool bi_sign;

        void my_swap(bint a, bint b)
        {
            std::swap(a.bi_size, b.bi_size);
            std::swap(a.bi_value, b.bi_value);
            std::swap(a.bi_sign, b.bi_sign);
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
            bi_size = 0;
            bi_sign = true;
            bi_value = nullptr;
        } 

        bint(std::string value): bi_size((value.length()/9) + 1), bi_value(new int[bi_size])
        {
            if(value[0]=='-')
            {
                bi_sign = false;
                value=value.substr(1);
            }

            for(int i=0;i<bi_size;i++)
            {
                if(value.length()>=9)
                {
                    bi_value[i] = str_to_int(value.substr(0,9));
                    value=value.substr(9);
                }
                else
                {
                    bi_value[i] = str_to_int(value);
                }
            }
        }

        bint(const bint& other)
        {
            bi_size = other.bi_size;
            bi_sign = other.bi_sign;
            bi_value = new int[bi_size];
            std::copy(other.bi_value,other.bi_value + bi_size, bi_value);  
        }

        bint& operator=(bint tmp)
        {
            my_swap(*this, tmp);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream &os, const bint &number)
        {
            if(number.bi_value==nullptr)
                os << 0;
            else
            {
                if(!number.bi_sign)
                    os << '-';
                
                for(int i=0;i<number.bi_size;i++)
                    os << number.bi_value[i];
            }

            return os;
        }

        friend std::istream& operator>>(std::istream& in, bint& num)
        {
            std::string s;
            in >> s;

            num.bi_size = (s.length()/9) + 1;
            num.bi_value = new int[num.bi_size];

            if(s[0]=='-')
            {
                num.bi_sign = false;
                s=s.substr(1);
            }

            for(int i=0;i<num.bi_size;i++)
            {
                if(s.length()>=9)
                {
                    num.bi_value[i] = num.str_to_int(s.substr(0,9));
                    s=s.substr(9);
                }
                else
                {
                    num.bi_value[i] = num.str_to_int(s);
                }
            }

            return in;
        }

        ~bint()
        {
            if(bi_value!=nullptr)
                delete[] bi_value;
        }

        

};

int main()
{
    bint i1;
    bint i3(i1);
    bint i2 = i1;

    std::cin >> i1;
    std::cout << i1;
    

    return 0;
}
