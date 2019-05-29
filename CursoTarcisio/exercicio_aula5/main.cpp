#include<iostream>
#include "student.h"
#include "functions.h"

int _main(std::ostream& in)
{
    auto students = school::read_students(in);

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

    return 0;
}

int main(int argc, char** argv)
{
    if (argc == 1) {
        return _main(std::cin);
    }

    auto file = std::ifstream{argv[1]};

    return _main(file);
}
