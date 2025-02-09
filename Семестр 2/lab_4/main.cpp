#include <iostream>

class bint
{
    private:
        std::string bi_value;
        bool bi_sign;
    public:
        bint(): bi_value("0"), bi_sign(true)
        {}

        bint(std::string value): bi_value(value)
        {
            if(value[0]=='-')
            {
                bi_sign = false;
                bi_value=bi_value.substr(1);
            }
            else
            {
                bi_sign = true;
            }
        }

        bint(bint& other): bint(other.bi_value)
        {}

        bint& operator=(bint& other)
        {
            std::cout << "All right" << std::endl;
            if(this != &other)
            {
                this->bi_sign = other.bi_sign;
                this->bi_value = other.bi_value;
            }

            return *this;
        }

};

int main()
{
    bint i1("1233465");
    bint i2 = i1;

    return 0;
}
