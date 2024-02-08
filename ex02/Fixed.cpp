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
    this->fixed_nbr = src.fixed_nbr;
}

// surchare d operateur
Fixed &Fixed::operator=(const Fixed &source) {
    if (this == &source) {
        return *this;
    }
    this->fixed_nbr = source.getRawBits();
    return *this;
}
std::ostream& operator<<(std::ostream& out, const Fixed& source) {
    out << source.toFloat();
    return out;
}

// Operateur de comparaison 
bool Fixed::operator>(const Fixed &rhs) const {
    return this->fixed_nbr > rhs.fixed_nbr;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->fixed_nbr < rhs.fixed_nbr;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->fixed_nbr >= rhs.fixed_nbr;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->fixed_nbr <= rhs.fixed_nbr;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->fixed_nbr == rhs.fixed_nbr;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->fixed_nbr != rhs.fixed_nbr;
}

// Operateur d incrementation
Fixed &Fixed::operator++() {
    this->fixed_nbr++;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}
Fixed &Fixed::operator--() {
    this->fixed_nbr--;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

// operateur arithmetique
Fixed Fixed::operator+(const Fixed &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs.toFloat() == 0) {
        std::cerr << "Erreur : division par zéro." << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

// les 4 fonctions supplementaire
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a.fixed_nbr < b.fixed_nbr) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a.fixed_nbr < b.fixed_nbr) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a.fixed_nbr > b.fixed_nbr) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a.fixed_nbr > b.fixed_nbr) ? a : b;
}


// Constructeur && Destructeur
Fixed::Fixed(){
    this->fixed_nbr = 0;
}

Fixed::Fixed(int const num) {
    this->fixed_nbr = num << this->point_place;
}

Fixed::Fixed(float const num) {
    this->fixed_nbr = roundf(num * (1 << this->point_place));
}


Fixed::~Fixed(){
}