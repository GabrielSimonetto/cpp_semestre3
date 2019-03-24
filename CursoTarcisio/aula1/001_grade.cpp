#include <iostream>

int main() {
    
    auto grade = 5.0;
    // double 
    // auto inferiu o tipo da variavel

    if (grade < 5.75) {
        std::cout << "You failed\n";
    } 
    else if (grade < 8.0) {
        std::cout << "You passed\n";
    }
    else {
        std::cout << "Congrats\n";
    }

}