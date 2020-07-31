// complex2.hpp
// NOTE: Second implementation of complex, just cartesian

#ifndef COMPLEX2_HPP //include guard
#define COMPLEX2_HPP

#include <iostream>

    class complex{
        private:
            double real;
            double imaginary;


            double modulus();
            double argument();
        public:
            complex(); // Defualt constructor
            complex(double, double); // Parameterised constructor
            ~complex(); // Destructor

            // Public member functions
            double * get_polar() const;
            double * get_cart() const;

            complex conj() const;


            // Overloaded Operators
            // On two complex:

            complex operator+(const complex &);
            complex operator-(const complex &);
            complex operator*(const complex &);
            complex operator/(const complex &);
            complex& operator+=(const complex &);
            complex& operator-=(const complex &);
            bool operator==(const complex &);
            bool operator!=(const complex &);


            friend bool operator==(const complex & lhs,\
                    const complex & rhs);

            inline friend bool operator!=(const complex & lhs, \
                    const complex & rhs){return (!(lhs==rhs));}



            // Comparison: real vs complex
            template<typename T> friend bool operator==\
                            (const complex & lhs, const T & rhs){
                return ((lhs.get_cart()[0] == (double) rhs));
            }
            template<typename T> friend bool operator!=\
                                    (const complex & lhs, const T & rhs){
                return (!(lhs==rhs));                                                                  
            }
            
            // Comparison: complex vs real
            template<typename T> friend bool operator ==\
                            (const T & lhs, const complex & rhs){
                return ((lhs == rhs.get_cart()[0]));
            }

            template<typename T> friend bool operator!=\
                             (const T & lhs, const complex & rhs){
                return(!(lhs==rhs));
            }

            
            // Friend functions
            friend std::ostream &operator<<(std::ostream &, const complex &);
            friend std::istream &operator>>(std::istream &, const complex &);
    };

#endif
