#include "../include/Gradebook.h"
#include "../include/Utilities.h"
#include <stdexcept>

double Gradebook::gradeToPoints(Grade grade) {
    switch(grade) {
        case Grade::A: return 4.0;
        case Grade::B: return 3.0;
        case Grade::C: return 2.0;
        case Grade::D: return 1.0;
        case Grade::F: return 0.0;
        default: throw std::invalid_argument("Invalid grade");
    }
}

void Gradebook::addGrade(const std::string& studentId, const std::string& courseId, Grade grade) {
    grades[studentId][courseId] = grade;
}

void Gradebook::updateGrade(const std::string& studentId, const std::string& courseId, Grade grade) {
    if (!hasGrade(studentId, courseId)) {
        throw NotFoundException("Grade not found for student " + studentId + " in course " + courseId);
    }
    grades[studentId][courseId] = grade;
}

void Gradebook::removeGrade(const std::string& studentId, const std::string& courseId) {
    auto studentIt = grades.find(studentId);
    if (studentIt != grades.end()) {
        studentIt->second.erase(courseId);
        if (studentIt->second.empty()) {
            grades.erase(studentIt);
        }
    }
}

double Gradebook::calculateGPA(const std::string& studentId) const {
    auto studentIt = grades.find(studentId);
    if (studentIt == grades.end() || studentIt->second.empty()) {
        return 0.0;
    }

    double totalPoints = 0.0;
    int count = 0;
    
    for (const auto& gradePair : studentIt->second) {
        totalPoints += gradeToPoints(gradePair.second);
        count++;
    }
    
    return count > 0 ? totalPoints / count : 0.0;
}

const std::map<std::string, Grade>& Gradebook::getStudentGrades(const std::string& studentId) const {
    static const std::map<std::string, Grade> empty;
    auto it = grades.find(studentId);
    return it != grades.end() ? it->second : empty;
}

bool Gradebook::hasGrade(const std::string& studentId, const std::string& courseId) const {
    auto studentIt = grades.find(studentId);
    if (studentIt != grades.end()) {
        return studentIt->second.find(courseId) != studentIt->second.end();
    }
    return false;
}