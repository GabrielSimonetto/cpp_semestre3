#include <iostream>
#include <string>

using namespace std;

int count_chars(char myChar, string myString) {
    int counter = 0;
    for (char current: myString) {
        if (current == myChar) {
            counter++;
        }
    }
    return counter;
}



int main(){
    string myString = "sorvete";

    cout << count_chars('e', myString);
}