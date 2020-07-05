#include <iostream>
#include "complex.hpp"
/* bool user_type() {*/
/*     bool cart;    // 'cartesian?' -- cartesian = true; polar = false*/
/*     char cn_type; // Type of complex number -- polar or cartesian*/

/*      NOTE: this doesn't work fully. If the user enters more than a*/
/*        single character, the cin stream is not flushed. Is there a*/
/*        better;/different way of doing this.*/

/*     while (true) {*/
/*         std::cout << "Is your complex number cartesian (c) or polar (p): ";*/
/*         std::cin >> cn_type;*/
/*         if (cn_type == 'c') {*/
/*             cart = true;*/
/*             break;*/
/*         } else if (cn_type == 'p') {*/
/*             cart = false;*/
/*             break;*/
/*         } else*/
/*             continue;*/
/*     };*/
/*     return cart;*/
/* };*/

/* // Check whether complex number is 0*/
/* bool is_zero(double a, double b){*/
/*     if (a ==0 && b == 0)*/
/*     {*/
/*         std::cout << "You have entered the zero complex number. Please re-enter";*/
/*         return true;*/
/*     }*/
/*     else*/
/*         return false;*/
/* };*/

/* void user_complex(bool cart) {*/
/*     double inp_a, inp_b;*/
/*     bool zero;*/
/*     do{*/
/*     if (cart == true)*/ 
/*     {*/
/*         std::cout << "Enter the real part: ";*/
/*         std::cin >> inp_a;*/
/*         std::cout << " Enter the Imaginary part: ";*/
/*         std::cin >> inp_b;*/
/*     }*/
/*     else*/ 
/*     {*/
/*         std::cout << "Enter the modulus: ";*/
/*         std::cin >> inp_a;*/
/*         std::cout << " Enter the argument: ";*/
/*         std::cin >> inp_b;*/
/*     };*/

/*     zero = is_zero(inp_a, inp_b);*/
/*     } while (zero == true);*/

/*     complex num(inp_a, inp_b, cart);*/
/* };*/

/* void get_input(){*/
/*     bool cart = user_type();*/
/*     user_complex(cart);*/
/* };*/

int main(){
    complex A(2,4);
    complex B(5,7);

    std::cout << "A is "; 
    std::cout << "in cartesian form, or ";
    std::cout<< "in polar form.\n";

    std::cout << "B is "; 
    std::cout << "in cartesian form, or ";
    std::cout<< "in polar form.\n";

    complex C = A + B;
    complex D = A - B;
    complex E = A * B;
    complex F = A / B;

    std::cout << "Addition";
    std::cout << "\nSubtraction";
    std::cout << "\nMultpilication";
    std::cout << "\nDivision";

    return 0 ;
};
