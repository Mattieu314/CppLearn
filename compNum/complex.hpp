// complex.hpp
#ifndef COMPLEX_HPP //include guard
#define COMPLEX_HPP
/*
    Complex number class holding complex number as:
        - cartesian: x + iy
        - polar: r(cos(theta) + isin(theta))
*/
class complex{
    private:
        // Cartesian form
        double real;        // Real part (x)
        double imaginary;   // Imaginary part (y)
        // Polar form
        double modulus;     // Modulus (r)
        double argument;    // Argument (theta)

        /* Private member functions */
        // cartesian to polar
        double calc_modulus();     
        double calc_arg();   
        // polar to cartesian
        double calc_real();
        double calc_imaginary();

    public:
        complex();      // Defualt constructor
        complex(double inp_a, double inp_b, bool cart = true);
        double get_real();
        double get_imaginary();
        double get_modulus();
        double get_argument();

        /* Output */
        void print_cart();
        void print_polar();


        /* Overloaded operators */
        complex operator+ (complex);
        complex operator- (complex);
        complex operator* (complex);
        complex operator/ (complex);
};


#endif 
