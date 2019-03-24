#include <iostream>
#include <string>
#include <vector>

bool balanced(const std::string &s) {
    // Implement the balance check algorithm.
    // Use an std::vector<char> as a stack internally.
}

int main(void)
{
    using namespace std::string_literals;

    auto cases = std::vector{
        "()"s,
        ")"s,
        "([[]]{[]}{()})"s,
        "([)()(])({}{)(})"s,
        "[[](){](()"s,
    };

    for (auto c: cases) {
        std::cout << "Case " << c << " is "
                  << (balanced(c) ? "balanced" : "not balanced")
                  << '\n';

    }
}
