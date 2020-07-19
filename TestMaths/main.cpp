#include <iostream>
#include <string>
#include <sstream>

#include "complex.hpp"

int main(){
    std::string input;
    
    math::complex A(1,1, false);
    math::complex B(2,1, false);

    std::cout << "A is " << A << std::endl;

    std::cout << "B is " << B << std::endl;

    math::complex C = A + B;
    std::cout << "......................";
    math::complex D = A - B;
    math::complex E = A * B;
    math::complex F = A / B;
    std::vector<math::complex> roots = A.calc_roots(3);


    std::cout << "Addition: " << C << std::endl;
    std::cout << "\nSubtraction: " << D << std::endl;
    std::cout << "\nMultpilication: " << E << std::endl;
    std::cout << "\nDivision: " << F << std::endl;

    std::cout << "The 3rd roots of " << A << "are: " << std::endl;
    for (int i = 0 ; i < (int) roots.size(); i++){
        std::cout << roots[i];
    };
    return 0 ;
};
