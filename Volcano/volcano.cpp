#include <iostream>
#include <string>
#include <ctime>
#include "date.h"
using namespace std;

class volcano {
    string name;
    double height;          // Elevation of top of volcano crater
    int date_last;          // Date of last eruption
    int since_last;         // Time since the last eruption
    int get_date(){
        /* Get date of last eruption from user */
        short day, month, year, date;
        cout << "\n Please enter the day (dd): ";
        cin >> day;
        cout << "\n Please enter the month (mm): ";
        cin >> month;
        cout << "\n Please enter the year (yyyy): ";
        cin >> year;
        date = calc_date(day, month, year);
        return date;
    };

    
    int time_since_last(int date){
        /* Calculate time since last eruption */
        int today; // Date when program is ran
        // --- Calculate / get todays date into variable today 
        int since_last = date - today;
        return since_last;
    };

    public:
        volcano(string name, double height, int last_eruption, int date);
        ~volcano ();
        void getinfo();
        bool isdormant();
};


volcano::volcano(string name, double height, int date_last, int since_last){
    cout << "Object of type volcano is being created" << endl;
    name = "";
    height = 0;
    date_last = 0;
    since_last = 0;
};

volcano::~volcano (){
    cout << "Destructing object of type volcano";
};


void volcano::getinfo(){
    int date = get_date();
    
}

int main(){
    
    return 0;
}
