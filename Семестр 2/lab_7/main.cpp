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

        vector<bool>& operator=(vector<bool> other)
        {
            std::swap(len, other.len);
            std::swap(bv_values, other.bv_values);
            return *this;
        }

        vector<bool>(const vector<bool>& other)
        {
            len = other.len;
            if(len%8==0)
            {
                bv_values = new unsigned char[len/8];
                std::copy(other.bv_values, other.bv_values + other.len/8, bv_values);
            }
            else
            {
                bv_values = new unsigned char[len/8 +1];
                std::copy(other.bv_values, other.bv_values + other.len/8 +1, bv_values);
            }
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

                bool carry = false;
                //std::cerr << (int)tmp[0] << std::endl;
                tmp[len/8] = bv_values[len/8] >> 7;
                //std::cerr << (int)tmp[0] << " " << (int)bv_values[0] << std::endl;
                for(int i=0; i<len/8; i++)
                {
                    //std::cerr << tmp[i] << std::endl;
                    tmp[i] = (bv_values[i] << 1) | carry;
                    carry = bv_values[i] >> 7;
                    //std::cerr << tmp[i] << std::endl;
                }

                tmp[0] |= value;

                delete[] bv_values;
                bv_values = tmp;
            }
            else
            {
                bool carry = false;
                for(int i=0; i<len/8+1; i++)
                {
                    //std::cerr << carry << std::endl;
                    bool tmp = bv_values[i] >> 7;
                    bv_values[i] = (bv_values[i] << 1) | carry;
                    carry = tmp;
                    //std::cerr << (int)bv_values[i] << std::endl;
                }

                bv_values[0] |= value;
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
                bv_values[(i-1)/8] |= (1 << (i%8));
            }
            else
            {
                bv_values[(i-1)/8] &= ~(1 << (i%8));
            }
        }

        void insert(int index, bool value)
        {
            vector<bool> tmp;
            for(int i=len-1; i>index; i--)
            {
                //std::cerr <<(int)this->getElement(i) << std::endl;
                tmp.push_back(this->getElement(i));
            }
            //std::cerr << "here" << std::endl;
            tmp.push_back(value);
            for(int j=index-1; j>-1; j--)
            {
                //std::cerr << (int)this->getElement(j) << std::endl;
                tmp.push_back(this->getElement(j));
            }

            *this = tmp;

        }

        void erase(int index)
        {
            vector<bool> tmp;
            for(int i=len-1; i>-1; i--)
            {
                if(i!=index)
                {
                    tmp.push_back(this->getElement(i));
                    //std::cerr << this->getElement(i) << std::endl;
                }
                
            }

            *this = tmp;
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

