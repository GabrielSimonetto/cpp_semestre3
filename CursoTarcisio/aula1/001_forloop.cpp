#include <iostream>
#include <vector>

double average(std::vector<double> grades) {
    auto size = grades.size();
    auto sum = 0.0;

    for (auto i = 0; i < size; ++i) {
        sum += grades[i];
    }

    //ou
    sum = 0.0;
    for (auto i: grades) {
        sum += i;
    }

    return sum/size;
}

int main() {

    // {} eh um inicializador , por isso nao eh ()
    auto grades = std::vector<double>{9.0, 8.0, 4.0};
    std::cout << average(grades) << '\n';
}