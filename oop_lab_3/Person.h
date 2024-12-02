#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <stdexcept>

class Person {
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;
    char gender; // 'M' або 'F'
    int birthYear;

public:
    // Конструктор за замовчуванням
    Person();

    // Конструктор з параметрами
    Person(const std::string& lastName, const std::string& firstName,
        const std::string& middleName, char gender, int birthYear);

    // Геттери та сеттери
    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setMiddleName(const std::string& middleName);
    void setGender(char gender);
    void setBirthYear(int birthYear);

    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;
    char getGender() const;
    int getBirthYear() const;

    // Перевантаження операторів
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    friend std::istream& operator>>(std::istream& is, Person& person);

    // Метод пошуку за критеріями
    bool matches(const std::string& criteria, const std::string& value) const;
};

#endif // PERSON_H
