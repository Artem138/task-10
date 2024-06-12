#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int grade;
};

bool compareStudents(const Student& a, const Student& b) {
    return a.grade > b.grade; // Сортировка по убыванию оценок
}

int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    std::vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter student's name: ";
        std::cin >> students[i].name;
        std::cout << "Enter student's grade: ";
        std::cin >> students[i].grade;
    }

    std::sort(students.begin(), students.end(), compareStudents);

    std::cout << "\nSorted list:\n";
    for (const auto& student : students) {
        std::cout << student.name << " got a grade of " << student.grade << std::endl;
    }

    return 0;
}
