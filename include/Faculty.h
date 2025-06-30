#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <vector>
#include <string>

class Course;

class Faculty : public Person {
private:
    std::string specialization;
    std::vector<Course*> coursesTeaching;

public:
    Faculty(const std::string& name, const std::string& id, int age, 
            const std::string& specialization);
    
    std::string getSpecialization() const;
    void setSpecialization(const std::string& specialization);
    
    void assignCourse(Course* course);
    void removeCourse(const std::string& courseId);
    const std::vector<Course*>& getCoursesTeaching() const;
    
    void display() const override;
};

#endif // FACULTY_H