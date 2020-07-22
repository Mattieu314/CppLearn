#include <iostream>
using namespace std;
class volcano {
    private:
        string name;
        double height;          // Elevation of top of volcano crater

    public:
        volcano(); // Default constructor
        volcano(string input_name, double input_height); // Parameterised constructor
        ~volcano (); // Destructor
        string get_name();
        double get_height(){
            return height;
        };
        void getinfo();
};
