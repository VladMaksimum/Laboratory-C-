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
        int len;
        unsigned char* bv_values = new unsigned char[1];
    public:
        vector<bool>()
        {
            len = 0;
            bv_values[0] = 0;
        }

        ~vector<bool>()
        {
            delete[] bv_values;
        }

        void push_back(bool value)
        {
            if(len%8==0)
            {
                unsigned char* tmp = new unsigned char[len/8+1];

                std::copy(bv_values, bv_values + (len/8), tmp);
                tmp[len/8] = value;

                delete[] bv_values;
                bv_values = tmp;
            }
            else if(value)
            {
                bv_values[len/8] |= (1 << len%8);
            }
            //std::cerr << (int)bv_values[0] << " " << (int)bv_values[1] << std::endl;
            len++;
        }

        int size()
        {
            return len;
        }

        bool getElement(int i)
        {
            return (bv_values[i/8] >> (i%8)) & 1;
        }

        void setElement(int i, bool value)
        {   
            if(value)
            {
                bv_values[(i)/8] |= (1 << (i%8));
            }
            else
            {
                bv_values[(i)/8] &= ~(1 << (i%8));
            }
        }

        void insert(int index, bool value)
        {
            if(len%8==0)
            {
                unsigned char* tmp = new unsigned char[len/8 +1];

                tmp[len/8] = 0;
                for(int i=len; i>-1; i--)
                {
                    if(i!=index)
                    {
                        if((bv_values[(i-1)/8] >> ((i-1)%8)) & 1)
                        {
                            tmp[i/8] |= (1 << (i%8));
                        }
                        else
                        {
                            tmp[i/8] &= ~(1 << (i%8));
                        }
                    }
                    else
                    {
                        if(value)
                        {
                            tmp[i/8] |= (1 << (i%8));
                        }
                        else
                        {
                            tmp[i/8] &= ~(1 << (i%8));
                        }
                    }
                }

                delete[] bv_values;
                bv_values = tmp;
            }
            else
            {
                this->push_back(false);
                for(int i=len-1; i>-1; i--)
                {
                    if(i!=index)
                    {
                        if((bv_values[(i-1)/8] >> ((i-1)%8)) & 1)
                        {
                            bv_values[i/8] |= (1 << (i%8));
                        }
                        else
                        {
                            bv_values[i/8] &= ~(1 << (i%8));
                        }
                    }
                    else
                    {
                        if(value)
                        {
                            bv_values[i/8] |= (1 << (i%8));
                        }
                        else
                        {
                            bv_values[i/8] &= ~(1 << (i%8));
                        }
                    }
                }
            }
            len++;
        }

        void erase(int index)
        {
            int j=0;
            for(int i=0; i<len; i++)
            {
                if(i!=index)
                {
                    this->setElement(j, this->getElement(i));
                    j++;
                }
            }
            len--;
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

    std::cout << "----------" << std::endl;
    std::cout << test.getElement(2) << std::endl;
    test.insert(2,true);
    std::cout << test.getElement(2) << std::endl;
    test.erase(2);
    std::cout << test.getElement(2) << std::endl;

}

