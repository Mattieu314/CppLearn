/// chkType.hpp
#ifndef CHKTYPE_HPP //include guard
#define CHKTYPE_HPP

#include <string>

namespace inp{
// ------------ Check Double -------------

// Checks that there is a number before and after the decimal point
bool check_point(std::string str_input, int point_pos);

// Checks that there is a number before and after the exponent ('e'/'E')
bool check_exp(std::string str_input, int exp_pos);

// Checks that the input number is a double by:
//       - Confirming it only contains acceptable input
//        - Has a number before and after a point, if it exists
//        - Has a number before and after the e, it it exists

bool is_double(std::string input);
// --------------- Check int -----------------

bool is_int(std::string input);
}
#endif
