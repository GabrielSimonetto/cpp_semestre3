#include <algorithm>
#include <vector>

#include "student.h"
#include "functions.h"


namespace school {
    std::vector<Student> approved(const std::vector<Student>& students)
    {
        std::vector<Student> approved;

        std::copy_if(
            std::begin(students),
            std::end(students),
            std::back_inserter(approved),
            [](const Student& s) { return s.average() > 6.0; }
        );

        return approved;
    }

    std::vector<Student> dismissed_by_time(
        const std::vector<Student>& students,
        int year
    )
    {
        std::vector<Student> dismissed;

        std::copy_if(
            std::begin(students),
            std::end(students),
            std::back_inserter(dismissed),
            [year](const Student& s) { return s.years_enrolled(year) > 7; }
        );

        return dismissed;
    }
}

