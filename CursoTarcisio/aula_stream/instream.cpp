#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std::string_literals;

class InvalidInput: public std::runtime_error {
    using std::runtime_error::runtime_error;
};

int try_get_int(std::istream& in) {
    auto age = 0;
    auto age_str = ""s;

    std::getline(std::cin, age_str);

    auto ss = std::stringstream{age_str};

    ss >> age;

    std::cin >> age;
    std::cout << std::boolalpha << std::cin.good() << '\n';

    if (ss.fail()) {
        throw InvalidInput("Not a valid integer number.");
    }

    return age;
}

int get_int(const std::string& prompt, std::istream& in) {

    std::cout << prompt;

    while (true) {
        try {
            return try_get_int(in);
        } catch (const InvalidInput& e) {
            std::clog << e.what() << '\n';
        }
    }
}

int _main(std::istream& in) {
    auto name = ""s;

    std::getline(in, name);

    std::cout << std::boolalpha;

    auto age = get_int("Input your age: ", in);

    std::cout << "Hello, " << name
                << "! I see you were born in " << 2019 - age << '\n';

    return 0;
}

int main(int argc, char** argv) {

    if (argc == 1) {
        return _main(std::cin);
    }

    auto file = std::ifstream{argv[1]};

    return _main(file);

}