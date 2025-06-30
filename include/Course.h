#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <map>
#include "Faculty.h"
#include "Student.h"

class Course {
private:
    std::string courseCode;
    std::string title;
    Faculty* facultyInCharge;
    std::map<std::string, Student*> enrolledStudents;

public:
    Course(const std::string& courseCode, const std::string& title, Faculty* faculty);
    
    std::string getCourseCode() const;
    std::string getTitle() const;
    Faculty* getFacultyInCharge() const;
    
    void enrollStudent(Student* student);
    void removeStudent(const std::string& studentId);
    const std::map<std::string, Student*>& getEnrolledStudents() const;
    
    void display() const;
};

#endif // COURSE_H