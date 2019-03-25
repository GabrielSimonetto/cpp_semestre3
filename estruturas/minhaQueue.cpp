#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;

    for (int i=0; i< 10; i++) {
        myQueue.push(i);
    }

    cout << "My Q size " << myQueue.size() << endl;
    cout << "My Q back " << myQueue.back() << endl;
    cout << "My Q front " << myQueue.front() << endl;
}