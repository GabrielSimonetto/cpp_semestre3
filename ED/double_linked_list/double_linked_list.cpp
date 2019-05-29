#include <iostream>
#include "double_linked_list.h"

int main() {
    structures::DoublyLinkedList<int> list{};
    
    for (auto i = 0; i < 10; ++i) {
        list.push_back(i);
    }

    std::cout << list.pop(5);
    std::cout << list.pop(5);
    std::cout << list.size();
    std::cout << list.isheadNull();
    // list.pop(8);
    // ASSERT_THROW(list.pop(8), std::out_of_range);
}