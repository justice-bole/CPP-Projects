#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
    std::string fname{};
    int grade{};
};

int returnGreater(const Student& a, const Student& b)
{
    return a.grade > b.grade;
}

int main() {
    //get total student
    std::cout << "Enter the amount of total students: ";
    int nstudents{};
    std::cin >> nstudents;

    std::vector<Student> students{static_cast<std::size_t>(nstudents)};

    //get student name and grade
    for(auto& student : students)
    {
        std::cout << "Student first name: ";
        std::cin >> student.fname;
        std::cout << "Student grade: ";
        std::cin >> student.grade;
    }
    //sort based on grade
    std::sort(students.begin(), students.end(), returnGreater);

    for(const auto& student : students)
    {
        std::cout << student.fname << "got a grade of " << student.grade << '\n';

    }

    return 0;
}
