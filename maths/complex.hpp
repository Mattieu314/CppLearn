// complex.hpp
#ifndef COMPLEX_HPP //include guard
#define COMPLEX_HPP

#include <iostream>
#include <vector>
// Complex number class. 
// Complex number stored in polar form, defined by its
// modulus and argument.

namespace math {

class complex{
    private:
        double modulus;     // Modulus (r)
        double argument;    // Argument (theta)

        double calc_modulus(double, double);  
        double calc_arg(double, double);
        bool get_type();
        bool is_zero(double, double, bool polar = true);
        complex get_user();
        bool inp_polar;

    public:
        complex();      // Defualt constructor
        complex(double, double, bool polar = true); // Parameterised constructor
        ~complex();

        double get_modulus() const;
        double get_argument() const;
        bool get_polar() const;
        double calc_real() const; // Calculate and return real part
        double calc_imag() const; // Calculate and return imaginary part

        complex pow(int); // Calculate the power of the complex number
        std::vector<complex> calc_roots(int); // Calculate th e nth roots of the comlex number
        // Overloaded operators
        complex operator+ (const complex &);
        complex operator- (const complex &);
        complex operator* (const complex &);
        complex operator/ (const complex &);

        friend std::ostream &operator<<(std::ostream &, const complex &);
        friend std::istream &operator>>(std::istream &, const complex &);
};
}
#endif 
