#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private :
        int _value;
        int _fract_bits = 8;
    public :
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        void setRawBits(int const raw);
        int getRawBits(void) const;
};

#endif