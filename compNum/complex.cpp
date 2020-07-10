//complex.cpp
#include <iostream>
#include <cmath>
#include "complex.hpp"

/* Object initialisation */

/* Defualt constructor */
complex::complex(){
    std::cout << " -- Constructing (defualt) object of type complex --" << std::endl;
    modulus = 0;
    argument = 0;
};

/* 
   Parameterised constructor
   If user enters cartesian coordinates (polar == false),
   then modulus and argument are calculated
*/
complex::complex(double inp_a, double inp_b, bool polar) {
    if (polar == true) {
        modulus = inp_a;
        argument = inp_b;
        std::cout << "-- Constructing object of type complex. --\n" << std::endl;
    } else {
        std::cout << "-- Converting from cartesian to polar --\n";
        modulus = calc_modulus(inp_a,inp_b);
        argument = calc_arg(inp_a,inp_b);
        std::cout << "-- Constructing object of type complex --\n" << std::endl;
    };
};

complex::~complex(){
    std::cout << "-- Destructing object of type complex --\n";
}

/* Private member functions */

/* Calculate modulus from real and imaginary parameters */
double complex::calc_modulus(double real, double imaginary){
    modulus = std::sqrt(real*real + imaginary*imaginary);
    return modulus;
};

/* Calculate argument from real and imaginary paramaters */
double complex::calc_arg(double real, double imaginary){
    argument = std::atan2(imaginary, real);
    return argument;
};

/* Public member functions */

/* Return modulus */
double complex::get_modulus(){
    return modulus;
};

/* Return argument */
double complex::get_argument(){
    return argument;
};

double complex::calc_real(){
    double real = modulus*std::cos(argument);
    return real;
};

double complex::calc_imag(){
    double imaginary = modulus*std::sin(argument);
    return imaginary;
}

/* Output */

/* Overloaded Operators */

complex complex::operator+ (complex complex_input){
    double temp_real = calc_real() + complex_input.calc_real();
    double temp_imag = calc_imag() + complex_input.calc_imag();
    complex temp_complex(temp_real, temp_imag, false);
    return temp_complex;
};

complex complex::operator- (complex complex_input){
    double temp_real = calc_real() - complex_input.calc_real();
    double temp_imag = calc_imag() - complex_input.calc_imag();
    complex temp_complex(temp_real,temp_imag, false);
    return temp_complex;
};

complex complex::operator* (complex complex_input){
    double temp_mod = modulus * complex_input.get_modulus();
    double temp_arg = argument + complex_input.get_argument();

    complex temp_complex(temp_mod, temp_arg);
    return temp_complex;
};

complex complex::operator/ (complex complex_input){
    double temp_mod = modulus / complex_input.get_modulus();
    double temp_arg = argument - complex_input.get_argument();

    complex temp_complex(temp_mod, temp_arg);
    return temp_complex;
};

std::ostream &operator<<(std::ostream & os, complex& output){
    // Define output stream
    os << output.get_modulus() << "(cos(" << output.get_argument() << ") + isin(" 
        << output.get_argument() << ")\n";

    // Return output stream
    return os;
};
