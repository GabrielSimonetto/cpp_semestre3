#include <iostream>
#include <string>
#include <vector>

#include "student.h"
#include "functions.h"

int main()
{
    using namespace std::string_literals;
    using school::Student;

    auto students = std::vector<Student>{
        Student{
            "José",
            2016,
            4.0, 7.0, 8.0
        },
        Student{
            "João",
            2012,
            4.0, 6.0, 6.5
        },
        Student{
            "Jorge",
            2009,
            1.0, 2.0, 3.0
        },
        Student{
            "Maria",
            2013,
            5.0, 10.0, 9.0
        }
    };

    for (auto s: school::approved(students)) {
        std::cout << s.name()
                  << " is approved by grade with average "
                  << s.average() << ".\n";
    }

    for (auto s: school::dismissed_by_time(students, 2019)) {
        std::cout << s.name()
                  << " was dismissed for being in the course for too long: "
                  << s.years_enrolled(2019) << " years.\n";
    }
}
