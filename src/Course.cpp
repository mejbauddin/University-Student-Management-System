#include "../include/Course.h"
#include "../include/Student.h"
#include <iostream>

Course::Course(const std::string& courseCode, const std::string& title, Faculty* faculty)
    : courseCode(courseCode), title(title), facultyInCharge(faculty) {}

std::string Course::getCourseCode() const { return courseCode; }
std::string Course::getTitle() const { return title; }
Faculty* Course::getFacultyInCharge() const { return facultyInCharge; }

void Course::enrollStudent(Student* student) {
    enrolledStudents[student->getId()] = student;
}

void Course::removeStudent(const std::string& studentId) {
    enrolledStudents.erase(studentId);
}

const std::map<std::string, Student*>& Course::getEnrolledStudents() const {
    return enrolledStudents;
}

void Course::display() const {
    std::cout << "Course Code: " << courseCode << "\nTitle: " << title
              << "\nFaculty: " << (facultyInCharge ? facultyInCharge->getName() : "None")
              << "\nEnrolled Students: " << enrolledStudents.size() << std::endl;
}