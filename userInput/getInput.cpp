#include <iostream>
#include <string>
#include <sstream>

#include "getInput.hpp"
#include "checkType.hpp"

namespace inp{

int get_int(){
    std::string str_input;
    std::getline(std::cin, str_input);
    while (is_int(str_input) == false){
        std::cout << "You haven't entered an integer. Please re-enter: ";
        std::getline(std::cin, str_input);
        std::cout << std::endl;
    };
    int int_input;
    std::stringstream(str_input) >> int_input;
    return int_input;
}

double get_double(){
    std::string str_input;
    std::getline(std::cin, str_input);
    while (is_double(str_input) == false){
        std::cout << "You haven't entered a real number. Please re-enter: ";
        std::getline(std::cin, str_input);
        std::cout<< std::endl;
    };
    double double_input;
    std::stringstream(str_input) >> double_input;
    return double_input;
}
}
