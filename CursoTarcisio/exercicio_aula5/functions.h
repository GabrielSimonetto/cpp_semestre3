#ifndef SCHOOL_FUNCTIONS_H
#define SCHOOL_FUNCTIONS_H

#include <vector>
#include "student.h"


namespace school {
    std::vector<Student> approved(const std::vector<Student>& students);
    std::vector<Student> dismissed_by_time(
        const std::vector<Student>& students,
        int year
    );
}

#endif
