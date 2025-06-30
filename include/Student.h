#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
#include <map>

class Course;

class Student : public Person {
private:
    double gpa;
    std::map<std::string, Course*> enrolledCourses;

public:
    Student(const std::string& name, const std::string& id, int age, double gpa = 0.0);
    
    double getGPA() const;
    void updateGPA(double newGpa);
    
    void enrollCourse(Course* course);
    void dropCourse(const std::string& courseId);
    const std::map<std::string, Course*>& getEnrolledCourses() const;
    
    void display() const override;
};

#endif // STUDENT_H