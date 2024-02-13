#include "Fixed.hpp"


// Methode
int Fixed::getRawBits(void) const{
    return this->fixed_nbr;
}
void Fixed::setRawBits(int const raw){
    this->fixed_nbr = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->fixed_nbr / std::pow(2, this->point_place);
}

int Fixed::toInt(void) const {
    return this->fixed_nbr / std::pow(2, this->point_place);
}

// constructeur par copie
Fixed::Fixed(const Fixed &src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// surchare d operateur
Fixed &Fixed::operator=(const Fixed &source) {
    std::cout << "Copy assigment operator called" << std::endl;
    if(this != &source)
    {
        fixed_nbr = source.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& source) {
    out << source.toFloat();
    return out;
}

// Constructeur && Destructeur
Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_nbr = 0;
}

Fixed::Fixed(int const num) {
    std::cout << "Int constructor called" << std::endl;
    this->fixed_nbr = num << this->point_place;
}

Fixed::Fixed(float const num) {
    std::cout << "Float constructor called" << std::endl;
    this->fixed_nbr = (int)roundf(num * (1 << this->point_place));
}


Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}