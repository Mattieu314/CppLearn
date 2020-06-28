#include <iostream>
#include <string>
#include <ctime>
#include "date.h"
using namespace std;

class volcano {
    string name;
    double height;
    int last_eruption;
    int date;
    int get_date(){
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


volcano::volcano(string name, double height, int last_eruption, int date){

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
