#include "Person.h"

// Конструктор за замовчуванням
Person::Person() : lastName(""), firstName(""), middleName(""), gender('M'), birthYear(0) {}

// Конструктор з параметрами
Person::Person(const std::string& lastName, const std::string& firstName,
    const std::string& middleName, char gender, int birthYear)
    : lastName(lastName), firstName(firstName), middleName(middleName), gender(gender), birthYear(birthYear) {}

// Геттери та сеттери
void Person::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Person::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Person::setMiddleName(const std::string& middleName) {
    this->middleName = middleName;
}

void Person::setGender(char gender) {
    if (gender != 'M' && gender != 'F') {
        throw std::invalid_argument("Invalid gender! Use 'M' or 'F'.");
    }
    this->gender = gender;
}

void Person::setBirthYear(int birthYear) {
    if (birthYear < 1900 || birthYear > 2023) {
        throw std::out_of_range("Invalid birth year! Must be between 1900 and 2023.");
    }
    this->birthYear = birthYear;
}

std::string Person::getLastName() const {
    return lastName;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getMiddleName() const {
    return middleName;
}

char Person::getGender() const {
    return gender;
}

int Person::getBirthYear() const {
    return birthYear;
}

// Перевантаження оператора <<
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Last Name: " << person.lastName << ", First Name: " << person.firstName
        << ", Middle Name: " << person.middleName << ", Gender: " << person.gender
        << ", Birth Year: " << person.birthYear;
    return os;
}

// Перевантаження оператора >>
std::istream& operator>>(std::istream& is, Person& person) {
    std::cout << "Enter Last Name: ";
    is >> person.lastName;
    std::cout << "Enter First Name: ";
    is >> person.firstName;
    std::cout << "Enter Middle Name: ";
    is >> person.middleName;
    std::cout << "Enter Gender (M/F): ";
    is >> person.gender;
    person.setGender(person.gender); // Перевірка коректності статі
    std::cout << "Enter Birth Year: ";
    is >> person.birthYear;
    person.setBirthYear(person.birthYear); // Перевірка коректності року
    return is;
}

// Метод пошуку за критеріями
bool Person::matches(const std::string& criteria, const std::string& value) const {
    if (criteria == "lastName") {
        return lastName == value;
    }
    else if (criteria == "firstName") {
        return firstName == value;
    }
    else if (criteria == "middleName") {
        return middleName == value;
    }
    else if (criteria == "gender") {
        return gender == value[0];
    }
    else if (criteria == "birthYear") {
        return std::to_string(birthYear) == value;
    }
    return false;
}
