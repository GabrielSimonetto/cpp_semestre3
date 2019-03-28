#include <iostream>
#include <string>

const std::string check_palindrome(const std::string& s) {
    using namespace std::string_literals;

    int size = s.size();
    for (int i = 0; i < size; i++){
        if(s[i] != s[size-1-i]){
            return ("not a palindrome"s);
        }
    }
    return ("palindrome"s);
}

int main()
{
    using namespace std::string_literals;

    std::cout << "arara is "s << check_palindrome("arara"s) << std::endl;
    std::cout << "banana is "s << check_palindrome("banana"s) << std::endl;
}
