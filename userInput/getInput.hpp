// getInp.hpp
#ifndef GETINP_HPP //include guard
#define GETINP_HPP

#include <iostream>
#include <sstream>

namespace inp{

template <typename T>
T get_input(T & input){
    std::string str_input;
    std::getline(std::cin, str_input);
    while (check_type(str_input, input) == false){
        std::cout << "Incorrect input. Please re-enter: ";
        std::getline(std::cin, str_input);
        std::cout<< std::endl;
    }
    std::stringstream(str_input) >> input;
    return input;
}
}
#endif
