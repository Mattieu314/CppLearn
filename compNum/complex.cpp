//complex.cpp
#include <iostream>
#include <cmath>
#include "complex.hpp"

// Get user to input the type of complex number they want
/* Object initialisation */
complex::complex(){
    std::cout << " -- Constructing object of type complex --\n";
    real = 0;
    imaginary = 0;
    modulus = 0;
    argument = 0;
};

complex::complex(double inp_a, double inp_b, bool cart){
    if (cart == true)
    {
        real = inp_a;
        imaginary = inp_b;
        modulus = get_modulus();
        argument = calc_arg();
    }
    else
    {
        modulus = inp_a;
        argument = inp_b;
        real = calc_real();
        imaginary = calc_imaginary();
    };
};

/* Private member functions */

double complex::calc_modulus(){
    modulus = std::sqrt(real*real + imaginary*imaginary);
    return modulus;
};

double complex::calc_arg(){
argument = std::atan2(imaginary, real);
    return argument;
};

double complex::calc_real(){
    real = modulus*std::cos(argument);
    return real;
};

double complex::calc_imaginary(){
    imaginary = modulus*std::sin(argument);
    return imaginary;
};

/* Public member functions */

double complex::get_real(){
    return real;
};

double complex::get_imaginary(){
    return imaginary;
};

double complex::get_modulus(){
    return modulus;
};

double complex::get_argument(){
    return argument;
};


/* Overloaded Operators */

complex complex::operator+ (complex complex_input){
    double temp_real = real + complex_input.get_real();
    double temp_imag = imaginary + complex_input.get_imaginary();
    
    complex temp_complex(temp_real, temp_imag);
    return temp_complex;
};

complex complex::operator- (complex complex_input){
    double temp_real = real - complex_input.get_real();
    double temp_imag = imaginary - complex_input.get_imaginary();

    complex temp_complex(temp_real, temp_imag);
    return temp_complex;
};

complex complex::operator* (complex complex_input){
    double temp_mod = modulus * complex_input.get_modulus();
    double temp_arg = argument + complex_input.get_argument();

    complex temp_complex(temp_mod, temp_arg, false);
    return temp_complex;
};

complex complex::operator/ (complex complex_input){
    double temp_mod = modulus / complex_input.get_modulus();
    double temp_arg = argument - complex_input.get_argument();

    complex temp_complex(temp_mod, temp_arg, false);
    return temp_complex;
};

