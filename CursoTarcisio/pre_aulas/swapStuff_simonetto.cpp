#include <iostream>

using namespace std;

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 2;
    int y = 7;

    swap(x,y);

    cout << "X = " << x << " ;; Y = " << y << endl;
}