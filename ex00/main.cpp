#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    Fixed d;
    d.setRawBits(0);
    c.setRawBits(2147483647);

    std::cout << a.getRawBits() << "\n";
    std::cout << b.getRawBits() << "\n";
    std::cout << c.getRawBits() << "\n";
    std::cout << d.getRawBits() << std::endl;

    return (0);
}