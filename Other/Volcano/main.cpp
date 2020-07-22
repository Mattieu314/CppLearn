#include <iostream>
#include "mountain.hpp"

volcano get_volcano(){
    string input_name;
    double input_height;
    cout << "Please enter the information for the volcano:" << endl;
    cout << "Name of volano: ";
    cin >> input_name;
    cout << "\n Height of volcano (m): ";
    cin >> input_height;
    
    volcano temp_volcano(input_name, input_height);

    
    return temp_volcano;
};

mountain_type get_mountain(){
    string mountain_name;
    cout << "What type of mountain would you like to enter? ";
    cin >> mountain_name;

    mountain_type temp_mountain(mountain_name);
    return temp_mountain;
};

bool do_again(){
    char user_again = 'n';
    while (true){
        cout << "Would you like to enter another volcano? (y/n) ";
        cin >> user_again;
        if ((user_again == 'y') || (user_again == 'Y') )
            return true;
        else if ((user_again == 'n') || (user_again == 'n'))
            return false;
        else{
            cout << "This is an invalid option, please re-enter." << endl;
            continue;
        };
    };
};



int main(){
    bool again = false;
    mountain_type temp_mountain = get_mountain();
    
    do{
        volcano temp_volcano = get_volcano();
        temp_mountain.add_volcano(temp_volcano);
        cout << "You have entered the following volcano:" << endl;
        temp_volcano.getinfo();
        cout << "Which is of type: " << temp_mountain.get_name() << endl;


        cout << "\n\n";
        temp_mountain.get_info();
        again = do_again();
    } while (again == true);
    return 0;
};


/* int main(){ */
/*     volcano etna("Mt. Etna",3326); */
/*     volcano st_helens("Mount St. Helens", 2549); */

/*     // construct a mountain_type object */
/*     mountain_type strato("Stratovolcano"); */

/*     strato.add_volcano(etna); */
/*     cout << "Number of volcanoes: " << strato.get_number() << endl; */

/*     strato.add_volcano(st_helens); */
/*     cout << "Number of volcanoes: " << strato.get_number() << endl; */

/*     strato.get_info(); */

/*     return 0; */
/* }; */


