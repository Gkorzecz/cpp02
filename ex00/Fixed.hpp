#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private :
        int value_;
        static const int fract_bits_ = 8;
    public :
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        void setRawBits(int const raw);
        int getRawBits(void) const;
};

#endif