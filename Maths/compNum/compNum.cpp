#include <iostream>
#include <string>
#include <sstream>

#include "complex.hpp"

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
