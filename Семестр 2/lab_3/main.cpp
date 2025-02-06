#include <iostream>

class rectangle
{
    private:
        int r_length;
        int r_width;

    public:
        rectangle(int length, int width):
                r_length(length), r_width(width)
                {}

        int square()
        {
            return r_length * r_width;
        }

        int perimeter()
        {
            return 2*(r_length + r_width);
        }

        float diagonal()
        {
            return sqrt(r_length*r_length + r_width*r_width);
        }

};

int main()
{
    int a,b;
    std::cin >> a;
    std::cin >> b;

    rectangle test(a,b);

    std::cout << "square= " << test.square() << std::endl;
    std::cout << "diagonal= " << test.diagonal() << std::endl;
    std::cout << "perimetr= " << test.perimeter() << std::endl;

    return 0;
}
