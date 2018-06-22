#include <iostream>
#include <vector>

void getUser(std::vector<int>& list) {
    int userInput;
    std::cout << "Enter a number: ";
    std::cin >> userInput;
    while (userInput != 99) { // Mistake? I had to do something to get out.
        std::cout << "Enter a number: ";
        list.push_back(userInput); // Add the number to the vector list
        std::cin >> userInput; // User input
    }
}

int main() {

    int menuInput = 0; // menu options
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

        std::cin >> menuInput;
        switch (menuInput) {
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
        //system("pause");
    }
    return 0;
}
