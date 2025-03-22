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
        unsigned char* bv_values= new unsigned char[1];
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

                tmp[len] = (unsigned char)value;
                delete[] bv_values;
                bv_values = tmp;
            }
            else
            {
                bv_values[len/8 -1] += value * 10 * (len%8);
            }
        }

        friend std::ostream& operator<<(std::ostream& out, vector<bool>& obj);

};

std::ostream& operator<<(std::ostream& out, vector<bool>& obj)
{
    if(obj.len%8==0)
    {
        for(int i=obj.len/8; i>0; i--)
        {
            out << (int)obj.bv_values[i];
        }
    }
    else
        for(int i=0; i<obj.len/8+1; i++)
        {
            out << obj.bv_values[i];
        }
    return out;
}

int main()
{
    vector<bool> test;
    for(int i=0; i<8; i++)
    {
        bool v;
        std::cin >> v;
        test.push_back(v);
    }

    std::cout << test;

}

