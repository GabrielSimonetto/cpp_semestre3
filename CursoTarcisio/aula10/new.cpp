# include <iostream>

class C {

public:
    C(): C(0) {}

    C(int n): n{n} {
        std::cout << "C(" << n << ")\n";
    }

    ~C() {
        std::cout << "~C(" << n << ")\n";
    }

private:
    int n;
};

template <typename T>
void show_type(T t) {
    t.thisdoesnotexist();
} 

template <typename T>
struct VectorStorage {
public:
    VectorStorage(int n):
        contents{new T[10]},
        current_end{contents},
        storage_end{contents + 10}
    {}

    ~Vector() {
        delete[] contents;
    }

    VectorStorage(VectorStorage&& v):
        contents{v.contents},
        current_end{v.current_end},
        storage_end{v.storage_end}
    {
        v.contents = nullptr;
    }

    VectorStorage& operator=(VectorStorage&& v) {
        auto aux = std::move(v);
        this->swap(*this, aux);
    }

    void swap(VectorStorage& v) {
        std::swap(contents, v.contents);
        std::swap(current_end, v.current_end);
        std::swap(storage_end, v.storage_end);
    }

    T* contents;
    T* current_end;
    T* storage_end;
};

template <typename T>
class Vector {
public:
    using iterator_type = T*;

    Vector():
        contents{new T[10]},
        current_end{contents},
        storage_end{contents + 10}
    {}

    ~Vector() {
        delete[] contents;
    }

    void push_back(T value) {
        if (current_end == storage_end) {
            regrow();
        }

        *current_end = std::move(value);
        ++current_end;
    }

    iterator_type begin() {
        return contents;
    }

    iterator_type end() {
        return current_end;
    }

    long int size() const {
        return current_end - contents;
    }

private:
    void regrow() {
        auto size = storage_end - contents;

        T* = new T[(storage_end - contents) * 2];
        for (auto i = 0; i < size; i++) {
            storage[i] = std::move(contents[i]);
        }

        delete[] contents;
        contents = storage;
        current_end = contents + size;
        storage_end = contents + (size * 2);
    }

    // T* contents;
    // T* current_end;
    // T* storage_end;
};

int main() {
    // auto x = new C{0};
    auto x = new C[10]; // alocando varios C's

    std::cout << sizeof(x) << "\n";
    std::cout << sizeof(*x) << "\n";

    delete[] x;
}