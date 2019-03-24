#include <iostream>
#include <cmath>

double sqrt(double x) {
    auto guess = 1.0;
    auto old = 0.0; // soh precisa ser diferente do chute a inicializacao

    while (old != guess) {
        old = guess;
        guess = (guess + x/guess)/2;
    }
}

int main() {
    std::cout << sqrt(17.0) << std::endl;
    std::cout << std::sqrt(17.0) << std::endl;
}