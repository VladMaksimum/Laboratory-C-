#include <iostream>

int main()
{
   long long x;
   std::cout << "x=";
   std::cin >> x;

   long long* p = &x;
   for(int i=0; i<8; i++)
   {
    unsigned char* c = reinterpret_cast <unsigned char*>(p);
    std::cout << static_cast<int>(*(c+i)) << std::endl;
   }

    return 0;
}


