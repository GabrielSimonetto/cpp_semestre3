#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector {5, 6, 7, 8};

    myVector.push_back(2); 
    int size = myVector.size();

    for (int i=0; i < size; i++){
        cout << myVector[i] << endl;
    }
}