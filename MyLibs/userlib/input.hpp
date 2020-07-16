// input.hpp
#ifndef INPUT_HPP //include guard
#define INPUT_HPP

#include <iostream>

#include "check_double.hpp"
#include "check_int.hpp"

// Check and return an input of type double
double input_double(){
    std::string str_input;
    double input;
    std::getline(std::cin, str_input);
    while (is_double(str_input) == false) {
        std::cout << "Your input is invalid. Please re-enter: ";
        std::getline(std::cin, str_input);
    };
    std::stringstream(str_input) >> input;
    return input;
};

int input_int(){
    std::string str_input;
    int input;
    std::getline(std::cin, str_input);
    while (is_int(str_input) == false){
        std::cout << "\nYour input is not an integer. Please re-enter: ";
        std::getline(std::cin,str_input);
    };
    std::stringstream(str_input) >> input;
    return input;
};

#endif
