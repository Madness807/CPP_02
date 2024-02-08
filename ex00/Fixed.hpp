#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
    public:
        // Constructeur par default
        Fixed();

        // Constructeur par copie
        Fixed(const Fixed &src);

        // Surcharge de l operateur d affectation 
        Fixed &operator=(const Fixed &source);
        
        // Destructeur
        ~Fixed();

        // Autres méthodes publiques
        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int fixed_nbr;
        static const int point_place = 8;
};

#endif
