#include <iostream>
#include <string>
#include <vector>
#include "date.hpp"

using namespace std;

class volcano {
    private:
        string name;
        double height;          // Elevation of top of volcano crater
        int date_last;          // Date of last eruption
        int since_last;         // Time since the last eruption

    public:
        volcano(); // Default constructor
        volcano(string input_name, double input_height); // Parameterised constructor
        ~volcano (); // Destructor
        void getinfo();
        string get_name();
        /* bool isdormant(); */
        double get_height(){
            return height;
        };
};

// Default constructor
volcano::volcano(){
    cout << "Constructing object of type volcano" << endl;
    name = "";
    height = 0;
    date_last = 0;
    since_last = 0;
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

/////////////////////////////////////////////////////////////////////////////
 
// volcanic range class
class mountain_type{
    private:
        string name;
        int number_of_volcanoes;
        vector<volcano> list_of_volcanoes;

    public:
        mountain_type(); // defualt constructor
        mountain_type(string input_name); // parameterised constructor
        ~mountain_type(); // destructor

        // Public member functions
        void add_volcano(volcano input_volcano);
        void update_number();
        int get_number();
        void get_info();
        double height_combined(vector<volcano> list_of_volcanoes);
};

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

// Print info about each volcano within volcanic range
void mountain_type::get_info(){
    cout << "=======================" <<endl;

    cout << "The number of volcanoes in "<<name<< "is "<<number_of_volcanoes<< endl;

    cout << "=======================" << endl;

    // Use iteration to loop through list

    cout << "========================" << endl;
    cout << "The volcanoes contained in "<< name << ":" << endl;

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

int main(){
    
    volcano etna("Mt. Etna",3326);
    volcano st_helens("Mount St. Helens", 2549);

    // construct a mountain_type object
    mountain_type strato("Stratovolcano");

    strato.add_volcano(etna);
    cout << "Number of volcanoes: " << strato.get_number() << endl;

    strato.add_volcano(st_helens);
    cout << "Number of volcanoes: " << strato.get_number() << endl;

    strato.get_info();



    return 0;
};
