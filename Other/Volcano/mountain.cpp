#include "mountain.hpp"

// default constructor
mountain_type::mountain_type(){
    name ="";
    number_of_volcanoes=0;
    list_of_volcanoes = {};
};

// parameterised constructor
mountain_type::mountain_type(string input_name){
    name = input_name;
    number_of_volcanoes = 0;
    list_of_volcanoes = {};
};

mountain_type::~mountain_type(){
    cout << "Destructing object of type mountain_type: " << name << endl;
};


// Adding volcano object to list_of_volcanoes
void mountain_type::add_volcano(volcano input_volcano){
    cout << "Adding: " << input_volcano.get_name() << endl;

    // pushback input volcano into vector
    list_of_volcanoes.push_back(input_volcano);
    // Update number of volcanoes
    update_number();
};


void mountain_type::update_number(){
    // Get length of list_of_voclanoes
    number_of_volcanoes= (int) list_of_volcanoes.size();

};

int mountain_type::get_number(){
    return number_of_volcanoes;
};

string mountain_type::get_name(){
    return name;
};

// Print info about each volcano within volcanic range
void mountain_type::get_info(){
    cout << "=======================" <<endl;

    cout << "The number of volcanoes in "<<name<< "is "<<number_of_volcanoes<< endl;
    // Use iteration to loop through list

    cout << "========================" << endl;
    cout << "The volcanoes contained in "<< name << " are:" << endl;

    for (int i{0}; i < (int) list_of_volcanoes.size(); i++){
        // Print information
        cout << "========================" << endl;
        list_of_volcanoes[i].getinfo();
        cout << "========================" << endl;
    };
    cout <<" The total height for all volcanoes in " << name
        << " is " << height_combined(list_of_volcanoes) << "m" << endl;
};

double mountain_type::height_combined(vector<volcano> list_of_volcanoes){
    double total_height = 0;
    for (int i{0}; i< (int) list_of_volcanoes.size(); i++){
        total_height+=list_of_volcanoes[i].get_height();
    };
    return total_height;
};

