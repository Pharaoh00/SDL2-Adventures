#include <iostream>
#include <vector>

void getUser(std::vector<int>& list) {
    int userInput;
    std::cout << "Enter a number: ";
    std::cin >> userInput;
    while (userInput != 99) {
        std::cout << "Enter a number: ";
        list.push_back(userInput);
        std::cin >> userInput; // User input
    }
}

int main() {

    int menuInput = 0;
    int add = 0;
    bool running = true;
    std::vector<int> numbs;

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
        case 1:
            getUser(numbs);
            for (auto& n : numbs) {
                std::cout << n << "+";
                add += n; // add the numbers
            }
            std::cout << " = " << add << std::endl;
            break;
        case 2:
            getUser(numbs);
            for (auto& n : numbs) {
                std::cout << n << "-";
                add -= n; // add the numbers
            }
            std::cout << " = " << add << std::endl;
            break;
        case 3:
            add = 1;
            getUser(numbs);
            for (auto& n : numbs) {
                std::cout << n << "*";
                add *= n; // add the numbers
            }
            std::cout << " = " << add << std::endl;
            break;
        case 4:
            add = 1;
            getUser(numbs);
            for (auto& n : numbs) {
                std::cout << n << "/";
                n /= add; // add the numbers
            }
            std::cout << " = " << add << std::endl;
            break;
        }
        numbs.clear();
        add = 0;
        //system("pause");
    }
    return 0;
}
