// sin.hpp
#ifndef SIN_HPP //include guard
#define SIN_HPP

#include <iostream>
#include <string>
#include <sstream>

namespace mio{
    // Wrapper around std::cin, which includes a type check
    class inp{
        private:
            std::string str_input;


            bool check_point(std::string &, int &);
            bool check_exp(std::string &, int &);
            
        /* protected: */
        /*     std::string type; */
            
        public:
            std::string type;
            inp(); // Defualt constructor
            inp(std::string &); // Parameterised constructor
            ~inp(){}; // Destructor
            

            bool is_double(std::string &);
            bool is_int(std::string &);
            bool is_accept(); // Check that input is one of acceptable inputs

            std::istream &operator>>(std::istream&);




    };

};

#endif
