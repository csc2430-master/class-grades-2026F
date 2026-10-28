#include <iostream>
#include <string>
#include <iomanip>


int main() {
    const int STUDENTS = 4;
    const int SUBJECTS = 2;
    std::string students[STUDENTS];
    std::string subjects[SUBJECTS] = {"MATH", "SCIENCE"};
    std::cout << "Input Student\'s Names\n";
    for (size_t i=0; i<STUDENTS; i++) {
        std::cout << "Student " << (i + 1) << ": ";
        std::cin >> students[i];
    }

    double grades[STUDENTS][SUBJECTS];
    double studentAverages[STUDENTS];
    double subjectAverages[SUBJECTS];

    for (size_t student = 0; student < STUDENTS; student++) {
        std::cout << "Grades for " << students[student] << '\n';
        for (size_t subject = 0; subject < SUBJECTS; subject++) {
            std::cout << '\t' << subjects[subject] << ": ";
            std::cin >> grades[student][subject];
        }
    }

    // Calculate Averages
    for (size_t student = 0; student < STUDENTS; ++student) {
        double sum = 0.0;
        for (size_t subject = 0; subject < SUBJECTS; subject++)
            sum += grades[student][subject];
        studentAverages[student] = sum / SUBJECTS;
    }
    for (size_t subject = 0; subject < SUBJECTS; subject++) {
        double sum = 0.0;
        for (size_t student = 0; student < STUDENTS; student++)
            sum += grades[student][subject];
        subjectAverages[subject] = sum / STUDENTS;
    }

    // Print the Grades

    std::cout << std::string(20, '*');
    for (size_t subject = 0; subject < SUBJECTS; subject++) {
        std::cout << std::setw(10) << subjects[subject];
    }
    std::cout << std::setw(10) << "Average";
    std::cout << '\n';
    for (size_t student = 0; student < STUDENTS; student++) {
        std::cout << std::setw(20) << students[student];
        for (size_t subject = 0; subject < SUBJECTS; subject++) {
            std::cout << std::setw(10) << grades[student][subject];
        }
        std::cout << std::setw(10) << studentAverages[student] << '\n';
    }
    std::cout << std::string(20, '*');
    for (size_t subject = 0; subject < SUBJECTS; subject++) {
        std::cout << std::setw(10) << subjectAverages[subject];
    }
    std::cout << '\n';

    return 0;
}