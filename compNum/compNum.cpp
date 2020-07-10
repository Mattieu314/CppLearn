#include <iostream>
#include <string>
#include <sstream>
#include "complex.hpp"
#include "doubleCheck.hpp"

// Get user input of whether they will enter the number in cartesian form
// or polar form 
bool user_type() {
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

// Check whether complex number is 0
bool is_zero(double a, double b, bool polar = true){
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

complex user_complex() {
    double inp_a, inp_b;
    bool zero;
    bool polar = user_type();
    do{
    if (polar == false) 
    {
        std::cout << "\n====================\n";
        std::cout << "Enter the real part: ";
        inp_a = get_input();
        std::cout << "Enter the imaginary part: ";
        inp_b = get_input();
        std::cout << "====================\n";
    }
    else 
    {
        std::cout << "\n====================\n";
        std::cout << "Enter the modulus: ";
        inp_a = get_input();
        std::cout << "Enter the argument: ";
        inp_b = get_input();
        std::cout << "====================\n";
    };
    zero = is_zero(inp_a, inp_b, polar);
    } while (zero == true);

    complex num(inp_a, inp_b, polar);
    return num;
};

int main(){
    std::string input;
    
    complex A(2,4, false);
    complex B(5,7, false);

    std::cout << "A is " << A << std::endl;

    std::cout << "B is " << B << std::endl;

    complex C = A + B;
    std::cout << "......................";
    complex D = A - B;
    complex E = A * B;
    complex F = A / B;

    std::cout << "Addition: " << C << std::endl;
    std::cout << "\nSubtraction: " << D << std::endl;
    std::cout << "\nMultpilication: " << E << std::endl;
    std::cout << "\nDivision: " << F << std::endl;

    return 0 ;
};
