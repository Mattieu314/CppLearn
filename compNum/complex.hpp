// complex.hpp
#ifndef COMPLEX_HPP //include guard
#define COMPLEX_HPP
#include <iostream>
/*
   Complex number class. 
   Complex number stored in polar form, defined by its
   modulus and argument
*/
class complex{
    private:
        double modulus;     // Modulus (r)
        double argument;    // Argument (theta)
        
        // Used if user inputs cartesian form 
        double calc_modulus(double, double);  
        double calc_arg(double, double);

    public:
        complex();      // Defualt constructor
        complex(double inp_b, double inp_a, bool polar = true); // Parameterised constructor
        ~complex();

        double get_modulus();
        double get_argument();
        
        double calc_real(); // Calculate and return real part
        double calc_imag(); // Calculate and return imaginary part

        /* Overloaded operators */
        complex operator+ (complex);
        complex operator- (complex);
        complex operator* (complex);
        complex operator/ (complex);
        
        friend std::ostream &operator<<(std::ostream &, complex &);
};


#endif 
