#ifndef SCHOOL_STUDENT_H
#define SCHOOL_STUDENT_H

#include <string>


namespace school {

class Student {
public:
    Student(
        std::string name,
        int entry_year,
        double p1,
        double p2,
        double p3
    ):
        name_{std::move(name)},
        entry_year{entry_year},
        p1{p1},
        p2{p2},
        p3{p3}
    {}

    const std::string& name() const
    {
        return name_;
    }

    double average() const
    {
        return (p1 + p2 + p3) / 3;
    }

    int years_enrolled(int current_year) const
    {
        return current_year - entry_year;
    }

private:
    std::string name_;
    int entry_year;
    double p1, p2, p3;
};

}

#endif
