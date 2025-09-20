#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{}

Fixed::Fixed(const int value)
{
    this->_value = value << this->_fract_bits;
}

Fixed::Fixed(const float value)
{
	this->_value = static_cast<int>(roundf(value * (1 << _fract_bits)));

}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _value = other._value;
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int Fixed::getRawBits(void) const
{
    return(this->_value);
}

float   Fixed::toFloat(void)const
{
    return (static_cast<float>(_value) / (1 << _fract_bits));
}

int     Fixed::toInt(void)const
{
    return (this->_value >> _fract_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_value == other._value);
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
    ++_value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++_value;
    return (tmp);
}

Fixed& Fixed::operator--()
{
    --_value; 
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --_value;
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}

Fixed Fixed::fromRaw(int raw)
{
    Fixed tmp;
    tmp._value = raw;
    return (tmp);
}