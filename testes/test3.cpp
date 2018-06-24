#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>

enum StringValue {
    exitProgram // For exit the program
};
std::map<std::string, StringValue> string_map; // mapping with the std::string and the enums for switch

void getUser(std::vector<int>& in_list) {
    bool keepInput = true;
    char userInput;
    std::cout << "Enter a number: ";
    std::cin >> userInput;
    while (keepInput) {
        if (isdigit(userInput)) {
            int numb_menu = userInput-48; // tranforming the char menuInput to a integer
            std::cout << "Enter a number: ";
            in_list.push_back(numb_menu); // Add the number to the vector list
            std::cin >> userInput; // User input
        }
        else if (isalpha(userInput)) {
            std::string str_menu(1, userInput);
            if (str_menu == "b") {
                keepInput = false;
            }
        }
    }
}

int main() {

    string_map["a"] = exitProgram;
    char menuInput; // menu options
    int add = 0; // the "buffer" to make operation
    bool running = true;
    std::vector<int> numbs; // the vector with the user input

    std::cout << "Simple Calculator" << std::endl;

    while (running) {

        std::cout <<
            "1. Sum \n"
            "2. Subtract \n"
            "3. Multiply \n"
            "4. divide \n"
            "Choose from the numbers below options: ";

        std::cin >> menuInput; //Menu Input

        if (isdigit(menuInput)) { //Checking if the input from menu is a Number

            int numb_menu = menuInput-48; // tranforming the char menuInput to a integer

            switch (numb_menu) {
            case 1: // Add
                getUser(numbs);
                for (auto& n : numbs) {
                    std::cout << n << "+";
                    add += n; // add the numbers
                }
                std::cout << " = " << add << std::endl;
                break;
            case 2: // Subtract
                getUser(numbs);
                for (auto& n : numbs) {
                    std::cout << n << "-";
                    add -= n; // Subtract the numbers
                }
                std::cout << " = " << add << std::endl;
                break;
            case 3: // Multiply
                add = 1;
                getUser(numbs);
                for (auto& n : numbs) {
                    std::cout << n << "*";
                    add *= n; // Multiply the numbers
                }
                std::cout << " = " << add << std::endl;
                break;
            case 4: // divide
                add = 1;
                getUser(numbs);
                for (auto& n : numbs) {
                    std::cout << n << "/";
                    n /= add; // divide the numbers
                }
                std::cout << " = " << add << std::endl;
                break;
            }
            numbs.clear(); // clear the vector with previous numbers
            add = 0; // set the add to 0 again.
        }
        else if (isalpha(menuInput)) {
            //std::string str_menu(1, menuInput);
            //if (str_menu == "a") {
            //    running = false;
            //}
            std::string str_menu(1, menuInput); // tranforming the char menuInput to a std::string
            switch (string_map[str_menu]) {
            case exitProgram: // exitProgram = "a"
                running = false;

            }
            string_map.clear();
        }
    }
    return 0;
}
