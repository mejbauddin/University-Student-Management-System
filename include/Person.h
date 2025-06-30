#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    std::string id;
    int age;

public:
    Person(const std::string& name, const std::string& id, int age);
    virtual ~Person() = default;

    std::string getName() const;
    std::string getId() const;
    int getAge() const;

    void setName(const std::string& name);
    void setId(const std::string& id);
    void setAge(int age);

    virtual void display() const;

    bool operator==(const Person& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

#endif // PERSON_H