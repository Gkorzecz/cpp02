#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    Fixed d;
    Fixed f;
    // Fixed e(e);
    d.setRawBits(0);
    c.setRawBits(2147483647);
    f.setRawBits(-1);

    std::cout << a.getRawBits() << "\n";
    std::cout << b.getRawBits() << "\n";
    std::cout << c.getRawBits() << "\n";
    std::cout << d.getRawBits() << "\n";
    std::cout << f.getRawBits() << std::endl;

    return (0);
}