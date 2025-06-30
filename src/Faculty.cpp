#include <algorithm>  // Required for std::remove_if
#include "../include/Faculty.h"
#include "../include/Course.h"
#include <iostream>

Faculty::Faculty(const std::string& name, const std::string& id, int age, 
                 const std::string& specialization)
    : Person(name, id, age), specialization(specialization) {}

std::string Faculty::getSpecialization() const { return specialization; }
void Faculty::setSpecialization(const std::string& specialization) { 
    this->specialization = specialization; 
}

void Faculty::assignCourse(Course* course) {
    coursesTeaching.push_back(course);
}

void Faculty::removeCourse(const std::string& courseId) {
    coursesTeaching.erase(
        std::remove_if(coursesTeaching.begin(), coursesTeaching.end(),
            [&courseId](Course* course) { 
                return course && course->getCourseCode() == courseId; 
            }),
        coursesTeaching.end());
}

const std::vector<Course*>& Faculty::getCoursesTeaching() const {
    return coursesTeaching;
}

void Faculty::display() const {
    Person::display();
    std::cout << "Specialization: " << specialization 
              << "\nCourses Teaching: " << coursesTeaching.size() << std::endl;
}