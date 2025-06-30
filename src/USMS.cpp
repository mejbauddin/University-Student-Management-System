#include "../include/USMS.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <algorithm>

USMS::USMS() {
    loadData();
}

USMS::~USMS() {
    saveData();
}

void USMS::run() {
    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            switch (choice) {
                case 1: studentManagement(); break;
                case 2: facultyManagement(); break;
                case 3: courseManagement(); break;
                case 4: gradeManagement(); break;
                case 5: reportGeneration(); break;
                case 6: return;
                default: std::cout << "Invalid choice. Try again.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

void USMS::loadData() {
    // Basic implementation - loads empty data
    std::cout << "System initialized. Data loading not yet implemented.\n";
}

void USMS::saveData() {
    // Basic implementation
    std::cout << "Data saving not yet implemented.\n";
}

void USMS::displayMainMenu() const {
    std::cout << "\nUniversity Student Management System\n";
    std::cout << "1. Student Management\n";
    std::cout << "2. Faculty Management\n";
    std::cout << "3. Course Management\n";
    std::cout << "4. Grade Management\n";
    std::cout << "5. Reports\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

// Student Management
void USMS::studentManagement() {
    while (true) {
        std::cout << "\nStudent Management\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. View Student\n";
        std::cout << "4. List All Students\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Choice: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: removeStudent(); break;
            case 3: viewStudent(); break;
            case 4: listAllStudents(); break;
            case 5: return;
            default: std::cout << "Invalid choice\n";
        }
    }
}

void USMS::addStudent() {
    std::string name, id;
    int age;
    double gpa;
    
    std::cout << "\nAdd New Student\n";
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter student ID: ";
    std::getline(std::cin, id);
    
    if (students.find(id) != students.end()) {
        std::cout << "Error: Student with this ID already exists!\n";
        return;
    }
    
    std::cout << "Enter age: ";
    while (!(std::cin >> age) || age < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter age again: ";
    }
    
    std::cout << "Enter GPA (0.0-4.0): ";
    while (!(std::cin >> gpa) || gpa < 0 || gpa > 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter GPA again (0.0-4.0): ";
    }
    
    students[id] = std::make_unique<Student>(name, id, age, gpa);
    std::cout << "\nStudent added successfully!\n";
}

void USMS::removeStudent() {
    std::string id;
    std::cout << "\nRemove Student\n";
    std::cout << "Enter student ID to remove: ";
    std::getline(std::cin, id);
    
    if (students.erase(id)) {
        std::cout << "Student removed successfully!\n";
    } else {
        std::cout << "Error: Student not found!\n";
    }
}

void USMS::viewStudent() {
    std::string id;
    std::cout << "\nView Student\n";
    std::cout << "Enter student ID: ";
    std::getline(std::cin, id);
    
    auto it = students.find(id);
    if (it != students.end()) {
        std::cout << "\n--- Student Details ---\n";
        it->second->display();
        std::cout << "----------------------\n";
    } else {
        std::cout << "Error: Student not found!\n";
    }
}

void USMS::listAllStudents() {
    if (students.empty()) {
        std::cout << "\nNo students found!\n";
        return;
    }
    
    std::cout << "\n--- All Students (" << students.size() << ") ---\n";
    for (const auto& pair : students) {
        pair.second->display();
        std::cout << "--------------------\n";
    }
}

// Other management sections (basic implementations)
void USMS::facultyManagement() {
    std::cout << "\nFaculty management feature coming soon!\n";
}

void USMS::courseManagement() {
    std::cout << "\nCourse management feature coming soon!\n";
}

void USMS::gradeManagement() {
    std::cout << "\nGrade management feature coming soon!\n";
}

void USMS::reportGeneration() {
    std::cout << "\nReport generation feature coming soon!\n";
}

// Other methods can be implemented similarly