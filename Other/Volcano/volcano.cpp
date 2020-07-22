#include <iostream>
#include <string>
#include <vector>
#include "volcano.hpp"

using namespace std;


// Default constructor
volcano::volcano(){
    cout << "Constructing object of type volcano" << endl;
    name = "";
    height = 0;
};

// Parameterised contructor
volcano::volcano(string input_name, double input_height){
    cout << "Constructing object of type volcano: " << input_name << endl;
    name = input_name;
    height = input_height;
};

// Return information about volcano
void volcano::getinfo(){
    cout << "Name: " << name << endl;
    cout << "Height: " << height <<endl;
};

string volcano::get_name(){
    return name;
};

// Destructor
volcano::~volcano (){
    cout << "Destructing object of type volcano: " << name << endl;
};

///////////////////////////////////////////////////////////////////////////////
 

///////////////////////////////////////////////////////////////////////////////


