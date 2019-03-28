#include <iostream>
#include <vector>

namespace vectors {

    void zero_all(std::vector<int>& v) {
        for(auto& i: v) {
            i = 0;
        }
    }

}

int main() {
    auto v = std::vector<int>{};
    v = {1,2,3,4};
    auto w = std::vector<int>{4,3,2,1};

    vectors::zero_all(v);

    for (auto i: v) {
        std::cout << i;
    }
}