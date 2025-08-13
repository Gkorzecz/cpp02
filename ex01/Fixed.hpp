#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private :  
        int                 _value;
        static const int    _fract_bits = 8;

    public :
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        void    setRawBits(int const raw);
        int     getRawBits(void) const;

        float   toFloat(void)const;
		int     toInt(void)const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif