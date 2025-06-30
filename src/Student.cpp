#include "../include/Student.h"
#include "../include/Course.h"
#include <iostream>

Student::Student(const std::string& name, const std::string& id, int age, double gpa)
    : Person(name, id, age), gpa(gpa) {}

double Student::getGPA() const { return gpa; }
void Student::updateGPA(double newGpa) { gpa = newGpa; }

void Student::enrollCourse(Course* course) {
    enrolledCourses[course->getCourseCode()] = course;
    course->enrollStudent(this);
}

void Student::dropCourse(const std::string& courseId) {
    enrolledCourses.erase(courseId);
}

const std::map<std::string, Course*>& Student::getEnrolledCourses() const {
    return enrolledCourses;
}

void Student::display() const {
    Person::display();
    std::cout << "GPA: " << gpa << "\nEnrolled Courses: " << enrolledCourses.size() << std::endl;
}