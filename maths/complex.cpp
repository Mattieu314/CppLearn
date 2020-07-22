//complex.cpp
#include <iostream>
#include <cmath>

#include "complex.hpp"
#include "getInput.hpp"

// Object initialisation 
// Defualt constructor 
namespace math{

    complex::complex(){
        std::cout << " -- Constructing (defualt) object of type complex --" << std::endl;
        modulus = 0;
        argument = 0;
    };

    // Parameterised constructor
    // If user enters cartesian coordinates (polar == false),
    // then modulus and argument are calculated

    complex::complex(double inp_a, double inp_b, bool polar) {
        if (polar == true) {
            modulus = inp_a;
            argument = inp_b;
            inp_polar = true;
            std::cout << "-- Constructing object of type complex. --\n" << std::endl;
        } else {
            std::cout << "-- Converting from cartesian to polar --\n";
            modulus = calc_modulus(inp_a,inp_b);
            argument = calc_arg(inp_a,inp_b);
            inp_polar = false;
            std::cout << "-- Constructing object of type complex --\n" << std::endl;
        };
    };

    complex::~complex(){
        std::cout << "-- Destructing object of type complex --\n";
    }

    // Private member functions

    // Get user to input whether their input is polar or cartesian
    bool complex::get_type(){
        std::string valid_options = "cCpP";
        std::string input; 
        bool polar;     // Polar: polar = true; Cartesian: polar = false

        std::cout << "Would you like to enter the complex number in polar (p) or cartesian (c) form: ";
        std::getline(std::cin, input);

        while (input.size() != 1 || valid_options.find(input) == std::string::npos) {
            std::cout << "This is an invalid input, please enter c or p:\n";
            std::getline(std::cin, input);
        };

        if (input == "c" || input == "C") {
            polar = false;
        }
        else{
            polar = true;
        };
        return polar;
    };

    bool complex::is_zero(double a, double b, bool polar){
        if (polar == true){
            if (a == 0)
            {
                std::cout << "You have entered the zero complex number. Please re-enter.\n";
                return true;
            }
            else 
                return false;
        }
        else // polar == false
        {
            if (a == 0 && b == 0)
            {
                std::cout << "You have entered the zero complex number. Please re-enter\n";
                return true;
            }
            else
                return false;
        };
    };

    complex complex::get_user(){
        double inp_a, inp_b;
        bool zero;
        bool polar = get_type();
        do{
            if (polar == false) 
            {
                std::cout << "\n====================\n";
                std::cout << "Enter the real part: ";
                inp_a = inp::get_double();
                std::cout << "Enter the imaginary part: ";
                inp_b = inp::get_double();
                std::cout << "====================\n";
            }
            else 
            {
                std::cout << "\n====================\n";
                std::cout << "Enter the modulus: ";
                inp_a = inp::get_double();
                std::cout << "Enter the argument: ";
                inp_b = inp::get_double();
                std::cout << "====================\n";
            };
            zero = is_zero(inp_a, inp_b, polar);
        } while (zero == true);

        complex num(inp_a, inp_b, polar);
        return num;

    };

    // Calculate modulus from real and imaginary parameters 
    double complex::calc_modulus(double real, double imaginary){
        modulus = std::sqrt(real*real + imaginary*imaginary);
        return modulus;
    };

    // Calculate argument from real and imaginary paramaters
    double complex::calc_arg(double real, double imaginary){
        argument = std::atan2(imaginary, real);
        return argument;
    };

    // Public member functions

    // Return modulus
    double complex::get_modulus() const{
        return modulus;
    };

    // Return argument
    double complex::get_argument() const{
        return argument;
    };

    double complex::calc_real() const{
        double real = modulus*std::cos(argument);
        return real;
    };

    double complex::calc_imag() const{
        double imaginary = modulus*std::sin(argument);
        return imaginary;
    }

    bool complex::get_polar() const{
        return inp_polar;
    };


    std::vector<complex> complex::calc_roots(int n){
        std::vector<complex> roots;

        double temp_mod = std::pow(get_modulus(), 1/n);
        // Calculate each of the nth roots
        for (int k = 0; k <= n-1; k++) {
            double temp_arg = (2 * M_PI * k) / n + get_argument()/n;
            if (temp_arg <=-M_PI)
                temp_arg += 2*M_PI;
            else if (temp_arg > M_PI)
                temp_arg -= 2*M_PI;
            complex temp_complex(temp_mod, temp_arg);
            roots.push_back(temp_complex);
        };
        return roots;
    };

    complex complex::pow(int n){
        double temp_mod = std::pow(get_modulus(),n);
        double temp_arg = get_argument() * n;
        complex temp_comp(temp_mod, temp_arg);
        return temp_comp;
    };

    // Overloaded Operators

    complex complex::operator+ (const complex &complex_input){
        double temp_real = calc_real() + complex_input.calc_real();
        double temp_imag = calc_imag() + complex_input.calc_imag();
        complex temp_complex(temp_real, temp_imag, false);
        return temp_complex;
    };

    complex complex::operator- (const complex &complex_input){
        double temp_real = calc_real() - complex_input.calc_real();
        double temp_imag = calc_imag() - complex_input.calc_imag();
        complex temp_complex(temp_real,temp_imag, false);
        return temp_complex;
    };

    complex complex::operator* (const complex &complex_input){
        double temp_mod = modulus * complex_input.get_modulus();
        double temp_arg = argument + complex_input.get_argument();

        complex temp_complex(temp_mod, temp_arg);
        return temp_complex;
    };

    complex complex::operator/ (const complex &complex_input){
        double temp_mod = modulus / complex_input.get_modulus();
        double temp_arg = argument - complex_input.get_argument();

        complex temp_complex(temp_mod, temp_arg);
        return temp_complex;
    };

    std::ostream &operator<<(std::ostream &os, const complex &output){
        // Define output stream, dependant on input type
        if (output.get_polar() == true)
        {
            os << output.get_modulus() << "(cos(" << output.get_argument() 
                << ") + isin(" << output.get_argument() << ")\n";
        }
        else // output.polar == false
            os << output.calc_real() << " + " << output.calc_imag() << "i.\n";
        // Return output stream
        return os;
    };
}
