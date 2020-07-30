/// chkType.hpp
#ifndef CHKTYPE_HPP //include guard
#define CHKTYPE_HPP

#include <string>

namespace inp{
// ------------ Check Double -------------

bool check_point(const std::string & str_input, int point_pos);

bool check_exp(const std::string & str_input, int exp_pos);

bool is_double(const std::string & input);
// --------------- Check int -----------------

bool is_int(const std::string & input);

// General Check Type
template<typename T>
bool check_type(const std::string & str_input, const T & input ){
    if (std::is_same<T,int>::value == true){
        return is_int(str_input);
    }
    else if (std::is_same<T,double>::value == true){
        return is_double(str_input);
    }
    // TODO: include seperate else if for each type of function checker
}

}
#endif
