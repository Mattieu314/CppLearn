#include <iostream>

#include <cmath>
#include "complexcart.hpp"

// Private Member functions

double complex::modulus(){
    return (std::sqrt(real*real+ imaginary*imaginary));
}

double complex::argument(){
    return (std::atan2(imaginary, real));
}

complex::complex(){
    real = 0;
    imaginary = 0;
}

complex::complex(double inp_real, double inp_imaginary){
    real = inp_real;
    imaginary = inp_imaginary;
}

complex::~complex(){
    std::cout << "Destructing object of type complex";
}


// Public member functions

complex complex::conj() const{
    complex conjugate(real, -imaginary);
    return conjugate;
}

double * complex::get_cart() const{
    static double cartesian[2] = {real,imaginary};

    return cartesian;
}

double * complex::get_polar() const{
    static double polar[2] = {modulus(), arg()};
    return polar;
}

//  Overloaded operators
complex complex::operator+(const complex & compNum){
    double temp_real = real + compNum.real;
    double temp_imag = real + compNum.imaginary;
    complex result(temp_real, temp_imag);
    return result;
}

complex complex::operator-(const complex & compNum){
    double temp_real = real - compNum.real;
    double temp_imag = imaginary - compNum.imaginary;
    complex result(temp_real, temp_imag);
    return result;
}

complex complex::operator*(const complex & compNum){
    double temp_real = real * compNum.real \
                       - imaginary * compNum.imaginary;
    double temp_imag = imaginary * compNum.real \
                       + real * compNum.imaginary;
    complex result(temp_real, temp_imag);
    return result;
}

complex complex::operator/(const complex & compNum){
    complex temp_conj = compNum.conj();
    complex temp_numerator = temp_conj* *this;
    complex temp_denominator =  compNum * temp_conj;
    double temp_real = temp_numerator.real / temp_denominator.real;
    double temp_imaginary = temp_numerator.imaginary / temp_denominator.real;
    complex temp_complex(temp_real, temp_imaginary);
    return temp_complex;

}

complex& complex::operator+=(const complex & comp_rhs){
    real += comp_rhs.real;
    imaginary += comp_rhs.imaginary;
    return *this;
}

complex& complex::operator-=(const complex & comp_rhs){
    real -= comp_rhs.real;
    imaginary -= comp_rhs.imaginary;
    return *this;
}

bool operator==(const complex & lhs, const complex & rhs){
    return ((lhs.get_polar() == rhs.get_polar()));
}

