#include <iostream>

//Переменная — это каким-либо образом проименованная и адресованная область памяти, предназначенная для хранения данных.


//Целочисленные типы данных: знаковые: char, short, int, long, long long
//                           беззнаковые: unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long
//Вещественные: float, double
//Символьные: char, wchar_t
//Логические: bool

int main()
{
    std::cout << "Data types       Razmer      Diapozon" << std::endl;
    std::cout << "char               1           -128...127" << std::endl;
    std::cout << "short              2           -32768...32767" << std::endl;
    std::cout << "int                4           -2147483648...2147483647" << std::endl;
    std::cout << "long               4           -2147483648...2147483647" << std::endl;
    std::cout << "long long          8           -9223372036854775808...9223372036854775807" << std::endl;
    std::cout << "unsigned char      1           0...255" << std::endl;
    std::cout << "unsigned short     2           0...65535" << std::endl;
    std::cout << "unsigned int       4           0...4294967295" << std::endl;
    std::cout << "unsigned long      4           0...4294967295" << std::endl;
    std::cout << "unsigned long long 8           0...18446744073709551615 " << std::endl;
    std::cout << "float              4           from 3.4E-38 to 3.4E+38" << std::endl;
    std::cout << "double             8           from 1.7E-308 to 1 .7E+308" << std::endl;
    std::cout << "bool               1           0 or 1" << std::endl;
    std::cout << "-----------------------------------" << std::endl;


    char chara= 'a';
    char charb= 'b';
    std::cout << "char: a+b=" << (char)(chara+2) << std::endl;
    std::cout << "      a*b=" << chara*charb << std::endl;
    std::cout << "      a-b=" << chara-charb << std::endl;
    std::cout << "      a/b=" << chara/charb << std::endl;

    short shorta {10};
    short shortb {-4};
    std::cout << "short: 10+(-4)=" << shorta+shortb << std::endl;
    std::cout << "       10*(-4)=" << shorta*shortb << std::endl;
    std::cout << "       10-(-4)=" << shorta-shortb << std::endl;
    std::cout << "       10/(-4)=" << shorta/shortb << std::endl;

    int inta {3};
    int intb {1};
    std::cout << "int: "<<inta<<"+"<<intb<<"=" << inta+intb << std::endl;
    std::cout << "     2*1=" << inta*intb << std::endl;
    std::cout << "     2-1=" << inta-intb << std::endl;
    std::cout << "     2/1=" << inta/intb << std::endl;

    long longa{52};
    long longb{-6};
    std::cout << "long: 52+(-6)=" << longa+longb << std::endl;
    std::cout << "      52*(-6)=" << longa*longb << std::endl;
    std::cout << "      52-(-6)=" << longa-longb << std::endl;
    std::cout << "      52/(-6)=" << longa/longb << std::endl;

    long long longlonga {659};
    long long longlongb {23};
    std::cout << "long long: 659+23=" << longlonga+longlongb << std::endl;
    std::cout << "           659*23=" << longlonga*longlongb << std::endl;
    std::cout << "           659-23=" << longlonga-longlongb << std::endl;
    std::cout << "           659/23=" << longlonga/longlongb << std::endl;

    unsigned char uchara{'a'};
    unsigned char ucharb{'b'};
    std::cout << "unsigned char: 254+1=" << uchara+ucharb << std::endl;
    std::cout << "               254*1=" << uchara*ucharb << std::endl;
    std::cout << "               254-1=" << uchara-ucharb << std::endl;
    std::cout << "               254/1=" << uchara/ucharb << std::endl;

    unsigned short ushorta{65534};
    unsigned short ushortb{2};
    std::cout << "unsigned short: 65534+2=" << ushorta+ushortb << std::endl;
    std::cout << "                65534*2=" << ushorta*ushortb << std::endl;
    std::cout << "                65534-2=" << ushorta-ushortb << std::endl;
    std::cout << "                65534/2=" << ushorta/ushortb << std::endl;

    unsigned int uinta{5};
    unsigned int uintb{9};
    std::cout << "unsigned int: 5+9=" << uinta+uintb << std::endl;
    std::cout << "              5*9=" << uinta*uintb << std::endl;
    std::cout << "              5-9=" << uinta-uintb << std::endl;
    std::cout << "              5/9=" << uinta/uintb << std::endl;

    unsigned long ulonga{100};
    unsigned long ulongb{58};
    std::cout << "unsigned long: 100+58=" << ulonga+ulongb << std::endl;
    std::cout << "               100*58=" << ulonga*ulongb << std::endl;
    std::cout << "               100-58=" << ulonga-ulongb << std::endl;
    std::cout << "               100/58=" << ulonga/ulongb << std::endl;

    unsigned long long ulongla{58095738};
    unsigned long long ulonglb{23522512};
    std::cout << "unsigned long long: 58095738+23522512=" << ulongla+ulonglb << std::endl;
    std::cout << "                    58095738*23522512=" << ulongla*ulonglb << std::endl;
    std::cout << "                    58095738-23522512=" << ulongla-ulonglb << std::endl;
    std::cout << "                    58095738/23522512=" << ulongla/ulonglb << std::endl;

    float fa{1.5};
    float fb{2.3};
    std::cout << "float: 1.5+2.3=" << fa+fb << std::endl;
    std::cout << "       1.5*2.3=" << fa*fb << std::endl;
    std::cout << "       1.5-2.3=" << fa-fb << std::endl;
    std::cout << "       1.5/2.3=" << fa/fb << std::endl;

    double da{5.6};
    double db{1.3};
    std::cout << "double: 5.6+1.3=" << da+db << std::endl;
    std::cout << "        5.6*1.3=" << da*db << std::endl;
    std::cout << "        5.6-1.3=" << da-db << std::endl;
    std::cout << "        5.6/1.3=" << da/db << std::endl;

    bool ba{1};
    bool bb{1};
    std::cout << "bool: 0+1=" << (bool)(ba+bb) << std::endl;
    std::cout << "      0*1=" << ba*bb << std::endl;
    std::cout << "      1-0=" << ba-bb << std::endl;
    std::cout << "      1/0=" << ba/bb << std::endl;


    return 0;
}

