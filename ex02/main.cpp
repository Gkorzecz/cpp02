#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed c = 0;
    Fixed d(c);
    Fixed(e) = 3;
    Fixed(f) = 9;
    Fixed const g = 42;

    std::cout << a << "\n";
    std::cout << ++a << "\n";
    std::cout << a << "\n";
    std::cout << a++ << "\n";
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << Fixed::max(a, b) << "\n";
    std::cout << f / e << "\n";
    std::cout << g + f << "\n";
    // std::cout << e / d << std::endl;

    return (0);
}