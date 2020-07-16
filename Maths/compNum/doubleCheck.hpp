#ifndef DOUBLECHECK_HPP // include guard
#define DOUBLECHECK_HPP

#include <iostream>
#include <string>
#include <sstream>

// Used to check that there are there is a number before
//   and after the decimal point
bool check_point(std::string str_input, int point_pos){
    try {
        if (std::isdigit(str_input[point_pos-1]) \
                && std::isdigit(str_input[point_pos+1]))
            return true;
        else
            return false;
    }
    catch (const std::out_of_range){
        return false;
    };
};

// Check that there is a number before and after the exponent 
bool check_exp(std::string str_input, int exp_pos){
    try {
        if (std::isdigit(str_input[exp_pos-1]) \
                && std::isdigit(str_input[exp_pos+1]))
            return true;
        else
            return false;
    }
    catch (const std::out_of_range)
    {
        return false;
    }
};

// Check that the input number is a double by:
//       - Confirming it only contains acceptable input
//        - Has a number before and after a point, if it exists
//        - Has a number before and after the e, it it exists

bool is_double(std::string input) {
    int acceptable = 0; // Number of accetable characters (0-9 . e E). (Accept: ==lenght)
    int point = 0; // Number of decimal points. (Accept: 0 or 1)
    int exp = 0;   // Number of exponents. (Accept: 0 or 1)
    int point_pos = 1;
    int exp_pos = 1;
    for (int i = 0; i < (int)input.size(); i++) {
        if (std::isdigit(input[i])) {
            acceptable++;
        } else if (input[i] == '.') {
            acceptable++;
            point++;
            point_pos = i;
        } else if (input[i] == 'e' || input[i] == 'E') {
            acceptable++;
            exp++;
            exp_pos = i;
        }
        else if (input[i] == ' ')
        {
            std::cout << "SPACE";
            return false;
        };
    };
    if (exp <= 1 && point <= 1 && acceptable == (int)input.size())
        // Check correct number of acceptable character
    {
        if (point != 0 || exp != 0) {
            if (exp + point != (int)input.size())
                // Check that '.' and 'e' aren't the only characters
                if ((check_point(input, point_pos) || point == 0) &&
                        (check_exp(input, exp_pos) || exp == 0))
                    // Check there is a number before and after point and/or exp.
                    return true;
                else
                    return false;
            else
                return false;
        } else
            return true;

    } else
        return false;
};

double get_input(){
    std::string str_input;
    double d_input;
    std::getline(std::cin, str_input);
    while (is_double(str_input) == false) {
        std::cout << "Your input is invalid. Please re-enter: ";
        std::cin >> str_input;
    };
    std::stringstream(str_input) >> d_input;
    return d_input;
};

#endif
