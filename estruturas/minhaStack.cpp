#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;

    myStack.push(5);
    myStack.push(3);
    myStack.push(2);

    // cout << "pop once " << myStack.pop() << endl;
    cout << "top once " << myStack.top() << endl;
    // cout << "pop once " << myStack.pop() << endl;
}