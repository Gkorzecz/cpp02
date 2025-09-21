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

// Fixed Fixed::operator+(const Fixed& other) const
// {
//     return (Fixed(this->toFloat() + other.toFloat()));
// }

// Fixed Fixed::operator-(const Fixed& other) const
// {
//     return (Fixed(this->toFloat() - other.toFloat()));
// }

// Fixed Fixed::operator*(const Fixed& other) const
// {
//     return (Fixed(this->toFloat() * other.toFloat()));
// }

// Fixed Fixed::operator/(const Fixed& other) const
// {
//     return (Fixed(this->toFloat() / other.toFloat()));
// }

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed Fix_Add;
    Fix_Add._value = this->_value + other._value;
    return (Fix_Add);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed Fix_Sub;
    Fix_Sub._value = this->_value - other._value;
    return (Fix_Sub);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    int64_t wide = static_cast<int64_t>(_value) * other._value;
    Fixed Fix_Mul;
    Fix_Mul._value = static_cast<int>(wide >> _fract_bits);
    return (Fix_Mul);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._value == 0)
        throw std::runtime_error("division by zero");
    int64_t wide = (static_cast<int64_t>(_value) << _fract_bits);
    Fixed Fix_Div;
    Fix_Div._value = static_cast<int>(wide / other._value);
    return (Fix_Div);
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