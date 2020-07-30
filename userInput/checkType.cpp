#include <iostream>
#include <string>
#include <type_traits>

#include "checkType.hpp"
#include "getInput.hpp"

namespace inp{
// ------------ Check Double -------------
// Hello check
// Checks that there is a number before and after the decimal point
bool check_point(const std::string & str_input, int point_pos){
    if (point_pos == 0 || point_pos ==(int) str_input.size())
        return false;
    else if (std::isdigit(str_input[point_pos-1]) \
            && std::isdigit(str_input[point_pos+1]))
        return true;
    else
        return false;
}

// Checks that there is a number before and after the exponent ('e'/'E')
bool check_exp(const std::string & str_input, int exp_pos){
    if (exp_pos == 0 || exp_pos == (int) str_input.size())
        return false;
    else if (std::isdigit(str_input[exp_pos-1]) \
            && std::isdigit(str_input[exp_pos+1]))
        return true;
    else
        return false;
}

// Checks that the input number is a double by:
//       - Confirming it only contains acceptable input
//        - Has a number before and after a point, if it exists
//        - Has a number before and after the e, it it exists

bool is_double(const std::string & input) {
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

// --------------- Check int -----------------

bool is_int(const std::string & input){
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




}
