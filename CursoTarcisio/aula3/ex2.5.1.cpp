#include <iostream>
#include <string>
#include <vector>

bool balanced(const std::string& s){
    
    auto stack = std::vector<char>{};

    for (auto c: s){
        // se vc estiver lidando com uma abertura, empilha
        if (c == '(') {
            stack.push_back(')');
        }
        else if (c == '[') {
            stack.push_back(')');
        }
        else if (c == '{') {
            stack.push_back(')');
        }
        if (c == ')' or c == ']' or c == '}'){
            if (stack.empty()){
                return false;
            }

            if (c != stack.back()){
                return false;
            }
            stack.pop_back();
        }
    }

    return true;
}

int main()
{
    using namespace std::string_literals;

    auto cases = std::vector<std::string>{
        "int main(int argv, char** argv) { std::cout << argv[0] << '\n'; }"s,
        "([[]]{[]}{()})"s,
        ""s,
        ")"s,
        "([)()(])({}{)(})"s,
        "[[](){](()"s,
    };

    for (auto c: cases) {
        std::cout << "Case " << c << " is "
                  << (balanced(c) ? "balanced" : "not balanced")
                  << '\n';

    }
}