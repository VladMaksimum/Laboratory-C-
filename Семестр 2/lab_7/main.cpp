#include <iostream>

template <typename T>
class vector
{
    private:
    public:
};

template<>
class vector<bool>
{
    private:
        size_t len;
        unsigned char* bv_values;
    public:
        vector<bool>()
        {
            len = 0;
        }

        void push_back(bool value)
        {
            if(len%8==0)
            {
                unsigned char* tmp = new unsigned char[len/8+1];
                std::copy(bv_values, bv_values + len/8, tmp);

                tmp[len/8] = (unsigned char)value;

                if(len!=0)
                    delete[] bv_values;
                bv_values = tmp;
            }
            else if(value)
            {
                bv_values[len/8] |= 1 << (len%8);
            }
            len++;
        }

        bool getElement(int i)
        {
            if(len%8==0)
            {
                return bv_values[(len-i-1)/8] & (1 << (7-i%8));
            }
            else if(i<=len%8)
            {
                return bv_values[len/8] & (1 << (len%8 - i%8 -1));
            }
            else
            {
                return bv_values[(len-i-1)/8] & (1 << (8-(i%8)));
            }
            
        }

        void setElement(int i, bool value)
        {
            if(value)
            {
                if(len%8==0)
                {
                    bv_values[(len-i-1)/8] = bv_values[(len-i-1)/8] | (1 << (7-i%8));
                }
                else if(i<=len%8)
                {
                    bv_values[len/8] = bv_values[len/8] | (1 << (len%8 - i%8 -1));
                }
                else
                {
                    bv_values[(len-i-1)/8] = bv_values[(len-i-1)/8] | (1 << (8-(i%8)));
                }
            }
            else
            {
                if(len%8==0)
                {
                    bv_values[(len-i-1)/8] = bv_values[(len-i-1)/8] ^ (1 << (7-i%8));
                }
                else if(i<=len%8)
                {
                    bv_values[len/8] = bv_values[len/8] ^ (1 << (len%8 - i%8 -1));
                }
                else
                {
                    bv_values[(len-i-1)/8] = bv_values[(len-i-1)/8] ^ (1 << (8-(i%8)));
                }
            }
        }

};


int main()
{
    vector<bool> test;
    for(int i=0; i<10; i++)
    {
        bool v;
        std::cin >> v;
        test.push_back(v);
    }
    std::cout << test.getElement(2) << std::endl;
    test.setElement(2,true);

    std::cout << test.getElement(2);

}

