#include <iostream>
#include <string>

unsigned long* myfunc(unsigned long* output) {
    output[0] = 2;
    output[1] = 2;
    output[2] = 2;
    return output;
}

unsigned long* find(unsigned long* output) {
    std::cout << "c\n";
    return myfunc(output);
} 

int main() {
    unsigned long* output = new unsigned long[3];
    output = find(output);
    std::cout << output[0] << "\n";
    std::cout << output[1] << "\n";
    std::cout << output[2] << "\n";
}