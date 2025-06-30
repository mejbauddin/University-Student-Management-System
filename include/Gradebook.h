#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <map>
#include <string>
#include "Student.h"
#include "Course.h"

enum class Grade { A, B, C, D, F };

class Gradebook {
private:
    std::map<std::string, std::map<std::string, Grade>> grades;
    
    static double gradeToPoints(Grade grade);

public:
    void addGrade(const std::string& studentId, const std::string& courseId, Grade grade);
    void updateGrade(const std::string& studentId, const std::string& courseId, Grade grade);
    void removeGrade(const std::string& studentId, const std::string& courseId);
    
    double calculateGPA(const std::string& studentId) const;
    
    const std::map<std::string, Grade>& getStudentGrades(const std::string& studentId) const;
    
    bool hasGrade(const std::string& studentId, const std::string& courseId) const;
};

#endif // GRADEBOOK_H