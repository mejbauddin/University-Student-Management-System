#include "../include/Person.h"
#include <iostream>

Person::Person(const std::string& name, const std::string& id, int age) 
    : name(name), id(id), age(age) {}

std::string Person::getName() const { return name; }
std::string Person::getId() const { return id; }
int Person::getAge() const { return age; }

void Person::setName(const std::string& name) { this->name = name; }
void Person::setId(const std::string& id) { this->id = id; }
void Person::setAge(int age) { this->age = age; }

void Person::display() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << std::endl;
}

bool Person::operator==(const Person& other) const {
    return id == other.id;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    person.display();
    return os;
}