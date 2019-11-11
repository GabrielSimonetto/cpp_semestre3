#include <iostream>
#include <vector>
#include <set>

class Range {
    class EndRangeIterator {};

    class RangeIterator {
    public:
        RangeIterator(int value):
            value{value}
            // origin{origin}
        {}

        RangeIterator& operator++() {
            value++;
            return this*;
        }

        int operator*() {
            return value;
        }

        bool operator!=(const EndRangeIterator& end) {
            return not (value >= end.value);
        }

    private:
        int value;
        // Range& origin;
    };

public:
    Range(int start, int end):
        start{start},
        end_{end}
    {};

    RangeIterator begin() {
        return RangeIterator{start};
    }

    RangeIterator end() {
        return RangeIterator{end_};
    }

private:
    int start;
    int end_;
};

int main() {
    // auto v = std::vector<int>{1, 2, 7, 3, 0, 9};
    auto v = std::set<int>{1, 2, 7, 3, 0, 9};

    auto v = Range(0, 5);

    // for (auto i: v) {
    //     std::cout << i << "\n";
    // }

    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << "\n";
    }

}
