#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
	private:
		int fixed_nbr;
		static const int point_place = 8;
		
	public:
		// Constructeur par default
		Fixed();

		// Constructeur par copie
		Fixed(const Fixed &src);
		Fixed(int const num);
		Fixed(float const num);

		// Surcharge de l operateur d affectation 
		Fixed &operator=(const Fixed &source);
		
		// Destructeur
		~Fixed();

		// Autres méthodes publiques
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		// operateur de comparaison
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const; 
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		
		// operateur artithmetique
		Fixed operator+(const Fixed &rhs) const;	// +
		Fixed operator-(const Fixed &rhs) const;	// -
		Fixed operator*(const Fixed &rhs) const;	// *
		Fixed operator/(const Fixed &rhs) const;	// /
		

		// operateur d incrementation et de decrementation
		Fixed &operator++();	// ++value
		Fixed operator++(int);	// value++
		Fixed &operator--();	// --value
		Fixed operator--(int);	// value--

		// les 4 fonctions supplementaire
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);


};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);

#endif