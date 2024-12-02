#include <iostream>
#include "Person.h"

int main() {
    Person person;
    try {
        std::cin >> person;
        std::cout << "Person details: " << person << std::endl;

        // Приклад пошуку
        std::string criteria, value;
        std::cout << "Enter search criteria (lastName, firstName, middleName, gender, birthYear): ";
        std::cin >> criteria;
        std::cout << "Enter value to search: ";
        std::cin >> value;

        if (person.matches(criteria, value)) {
            std::cout << "Person matches the criteria!" << std::endl;
        }
        else {
            std::cout << "Person does not match the criteria!" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
