// check_int.hpp
#ifndef CHECK_INT_HPP //include guard
#define CHECK_INT_HPP

#include <string>

bool is_int(std::string input){
    int acceptable = 0; // Number of acceptable characters
    for (int i = 0; i < (int) input.size(); i++){
        if (std::isdigit(input[i]))
                acceptable++;
    };
    if (acceptable == (int) input.size())
        return true;
    else
        return false;
};

#endif
