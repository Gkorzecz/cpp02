#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    this->_value = 0;
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    // this->_value = other.getRawBits();
    this->_value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_value = other._value;
        // this->_value = other.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "Fixed class raw value set to : " << raw << "\n";
    this->_value = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return(this->_value);
}
