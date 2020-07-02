#include <iostream>
#include <ctime>
// Defines base year 
#define FIRST 1800
/* 00:00:01 01/01/1800 is first second;
   negative before this date
   positive after this date*/

bool is_leap(short year){
    /* Checks whether a given year is a leap using the definition
       of the Gregorian calender */
    bool leap;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                leap = true;
            else
                leap = false;
        }
        else
            leap = false;
    }
    else
        leap = false;
    return leap;
};

short num_leap(short year) {
    /* works out the number of leap years between base year and 
       input year */
    short temp_year = FIRST;
    short total = 0;
    do {
        total += is_leap(temp_year);
    }
    while (temp_year != year);
    return total;
};

int calc_date(short day, short month, short year){
    int date;
    short leaps = num_leap(year);
    if (year < FIRST)
    {
        day = -day;
        leaps = -leaps;
    }
    
    date =  (year-FIRST)*365 + day * month + leaps;
    
    return date;
};

int sys_time() {
    /* Function to return current system time and convert 
       it to program time */

    // Get current date/time based on current system
    // In seconds since 01/01/1970
    time_t now = time(0);
    std::cout << now << std::endl;



};
