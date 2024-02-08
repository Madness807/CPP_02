#include "Fixed.hpp"


// Methode
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_nbr;
}
void Fixed::setRawBits(int const raw)
{
    this->fixed_nbr = raw;
}

Fixed::Fixed(const Fixed &src){
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_nbr = src.fixed_nbr;
}

Fixed &Fixed::operator=(const Fixed &source) {
    std::cout << "Copy assigment operator called" << std::endl;
    if (this == &source) {
        return *this;
    }
    this->fixed_nbr = source.getRawBits();
    return *this;
}


// Constructeur && Destructeur
Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_nbr = 0;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

