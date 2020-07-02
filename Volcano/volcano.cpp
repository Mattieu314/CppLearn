#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "date.h"
using namespace std;

class volcano {
    string name;
    double height;          // Elevation of top of volcano crater
    int date_last;          // Date of last eruption
    int since_last;         // Time since the last eruption
    /* int get_date(){ */
    /*     /1* Get date of last eruption from user *1/ */
    /*     short day, month, year, date; */
    /*     cout << "\n Please enter the day (dd): "; */
    /*     cin >> day; */
    /*     cout << "\n Please enter the month (mm): "; */
    /*     cin >> month; */
    /*     cout << "\n Please enter the year (yyyy): "; */
    /*     cin >> year; */
    /*     date = calc_date(day, month, year); */
    /*     return date; */
    /* }; */
    
/*     int time_since_last(int date){ */
/*         /1* Calculate time since last eruption *1/ */
/*         int today; // Date when program is ran */
/*         // --- Calculate / get todays date into variable today */ 
/*         int since_last = date - today; */
/*         return since_last; */
/*     }; */

    public:
        volcano();
        volcano(string input_name, double input_height);
        ~volcano ();
        void getinfo();
        string get_name();
        /* bool isdormant(); */
};

// Default consturctor
volcano::volcano(){
    name = "";
    height = 0;
    date_last = 0;
    since_last = 0;
};

// Parameterised Constructor
volcano::volcano(string input_name, double input_height){
    name = input_name;
    height = input_height;
};

// Parameterised constructor
/* volcano::volcano(string name, double height, int date_last) { */
/*     cout << "Creating object of type volcano" << endl; */
/*     cout << "Please enter the following information:"<< endl; */
/*     cout << "Name of volcano: "; */
/*     cin >> name; */
/*     cout << "\n Height of volcano (m above sea level): "; */
/*     cin >> height; */
/*     /1* cout << "\n Date of last eruption"; *1/ */
/*     /1* cin >> date_last; *1/ */
/*     /1* cout << endl; *1/ */
/* }; */

volcano::~volcano (){
    cout << "Destructing object of type volcano: " << name << endl;
};

// Return info about volcano
void volcano::getinfo(){
    cout << "Name:" << name << endl;
    cout << "Height: " << height <<endl;
};


string volcano::get_name(){
    return name;
};

/////////////////////////////////////////////////////////////////////////////
 
// volcanic range class

class volcanic_range{
    string name;
    int number_of_volcanoes;
    vector<volcano> list_of_volcanoes;

    public:
        volcanic_range(); // defualt
        volcanic_range(string input_name); // parameterised
        ~volcanic_range(); // destructor

        // Public member functions
        void add_volcano(volcano input_volcano);
        void update_number();
        int get_number();

        void get_info();
};

// default constructor
volcanic_range::volcanic_range(){
    name ="";
    number_of_volcanoes=0;
    list_of_volcanoes = {};
};

// parameterised constructor
volcanic_range::volcanic_range(string input_name){
    name = input_name;
    number_of_volcanoes = 0;
    list_of_volcanoes = {};
};

volcanic_range::~volcanic_range(){
    cout << "Destructing object of type volcanic_range: " << name << endl;
};


// Adding volcano object to list_of_volcanoes
void volcanic_range::add_volcano(volcano input_volcano){
    cout << "Adding: " << input_volcano.get_name() << endl;

    // pushback input volcano into vector
    list_of_volcanoes.push_back(input_volcano);
    // Update number of volcanoes
    update_number();
};


void volcanic_range::update_number(){
    // Get length of list_of_voclanoes
    number_of_volcanoes= (int) list_of_volcanoes.size();

};

int volcanic_range::get_number(){
    return number_of_volcanoes;
};

// Print info about each volcano within volcanic range
void volcanic_range::get_info(){
    cout << "=======================" <<endl;

    cout << "The number of volcanoes in "<<name<< "is "<<number_of_volcanoes<< endl;

    cout << "=======================" << endl;

    // Use iteration to loop through list

    cout << "========================" << endl;
    cout << "The volcanoes contained in "<< name << ":" << endl;

    for (int i{0}; i < (int) list_of_volcanoes.size(); i++){
        // Print information
        list_of_volcanoes[i].getinfo();
        cout << "========================" <<endl;
    };
};

int main(){
    
    volcano etna("Mt. Etna",2000);
    volcano st_helens("Mount St. Helens", 1000);

    // construct a volcanic_range object
    volcanic_range test("Unreal Volcanic Range");
    
    test.add_volcano(etna);
    cout << "Number of volcanoes: " << test.get_number() <<endl;

    test.add_volcano(st_helens);
    cout << "Number of volcanoes: " << test.get_number() << endl;

    test.get_info();

    return 0;
}
