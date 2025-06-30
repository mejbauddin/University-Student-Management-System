#ifndef USMS_H
#define USMS_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Student.h"
#include "Faculty.h"
#include "Course.h"
#include "Gradebook.h"

class USMS {
private:
    std::map<std::string, std::unique_ptr<Student>> students;
    std::map<std::string, std::unique_ptr<Faculty>> faculty;
    std::map<std::string, std::unique_ptr<Course>> courses;
    Gradebook gradebook;
    
    const std::string STUDENT_FILE = "data/students.txt";
    const std::string FACULTY_FILE = "data/faculty.txt";
    const std::string COURSE_FILE = "data/courses.txt";
    
    void loadData();
    void saveData();
    
    void displayMainMenu() const;
    void studentManagement();
    void facultyManagement();
    void courseManagement();
    void gradeManagement();
    void reportGeneration();
    
public:
    USMS();
    ~USMS();
    
    void run();
    
    // Student operations
    void addStudent();
    void removeStudent();
    void viewStudent();
    void listAllStudents();
    
    // Faculty operations
    void addFaculty();
    void removeFaculty();
    void viewFaculty();
    
    // Course operations
    void addCourse();
    void removeCourse();
    void viewCourse();
    
    // Enrollment
    void enrollStudentToCourse();
    void assignFacultyToCourse();
    
    // Grade operations
    void addGrade();
    void updateGrade();
    void removeGrade();
    void viewStudentGrades();
    
    // Reports
    void viewStudentsInCourse();
    void viewCoursesForStudent();
    void viewGPAReport();
};

#endif // USMS_H