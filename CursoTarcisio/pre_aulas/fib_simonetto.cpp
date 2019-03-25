#include <iostream>

using namespace std;

int main()
{

    int n;

    cout << "Which number from the fibonacci sequence do you want?\n"
            "Inputing 0 outputs 1\n"
            "Inputing 1 outputs 1\n"
            "Inputing 2 outputs 2\n"
            "And so on...\n"
            "N: " ;
    cin >> n;

    int counter = 0;
    int output = 1;
    int anteriorNum = 0;
    int swap;

    while(counter < n){
        swap = output;
        output += anteriorNum;
        anteriorNum = swap;
        counter++;
    }

    cout << "\nYour fib num is " << output << endl;
    
}