

#include <iostream>
#include <vector>
#include "volcano.hpp"


class mountain_type{
    private:
        std::string name;
        int number_of_volcanoes;
        std::vector<volcano> list_of_volcanoes;

    public:
        mountain_type(); // defualt constructor
        mountain_type(std::string input_name); // parameterised constructor
        ~mountain_type(); // destructor

        // Public member functions
        void add_volcano(volcano input_volcano);
        void update_number();
        std::string get_name();
        int get_number();
        void get_info();
        double height_combined(std::vector<volcano> list_of_volcanoes);
};
