#include <iostream>
#include "linked_queue.h"

int main() {
    structures::LinkedQueue<int> list{};
    
    list.enqueue(1);

    std::cout << list.front() << "\n";

    std::cout << list.empty() << "\n";

    list.clear();

    std::cout << list.empty() << "\n";

    std::cout << list.back() << "\n";
    // ASSERT_THROW(queue.back(), std::out_of_range);
    // ASSERT_THROW(queue.dequeue(), std::out_of_range);


    // std::cout << list.pop(5);
    // std::cout << list.pop(5);
    // std::cout << list.size();
    // std::cout << list.isheadNull();
    // list.pop(8);
    // ASSERT_THROW(list.pop(8), std::out_of_range);
}