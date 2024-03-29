/* Copyright 2019 Gabriel Simonetto */

#ifndef STRUCTURES_DOUBLY_CIRCULAR_LIST_H
#define STRUCTURES_DOUBLY_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Doubly Circular list
class DoublyCircularList {
 public:
    DoublyCircularList() = default;

    ~DoublyCircularList() {
        clear();
    }

    //! hey
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    //! hey
    void push_back(const T& data) {
        auto new_node = new Node{data};
        if (empty()) {
            head = new_node;
            head->next(new_node);
        } else {
            auto previous = head;

            for (auto i = 0u; i < size_ - 1; ++i) {
                previous = previous->next();
            }
            previous->next(new_node);
            new_node->next(head);
            new_node->next()->prev(new_node);
        }
        ++size_;
    }

    //! hey
    void push_front(const T& data) {
        auto new_node = new Node{data};
        new_node->next(head);
        head = new_node;
        ++size_;
    }

    //! hey
    void insert(const T& data, std::size_t index) {
        if (index > size_) {
            throw std::out_of_range("Out of range (insert)");
        }

        if (empty() || index == 0) {
            push_front(data);
        }

        if (index == size_) {
            push_back(data);
        } else {
            auto previous = head;

            for (auto i = 0u; i < index - 1; ++i) {
                previous = previous->next();
            }

            auto new_node = new Node{data, previous, previous->next()};
            new_node->next(previous->next());
            previous->next(new_node);
            if (new_node->next() == nullptr) {
                new_node->next()->prev(new_node);
            }
        }
        ++size_;
    }

    //! hey
    void insert_sorted(const T& data) {
        if (empty() || data <= head->data()) {
            push_front(data);
        } else {
            auto previous = head;
            auto current = previous->next();
            for (auto i = 0u; i < size_ - 1; ++i) {
                if (data <= current->data()) {
                    break;
                }
                previous = current;
                current = previous->next();
            }
            auto new_node = new Node{data};
            previous->next(new_node);
            new_node->next(current);
            ++size_;
        }
    }

    //! hey
    T& at(std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Out of range (at)");
        }

        auto current = head;
        for (auto i = 0u; i < index; ++i) {
            current = current->next();
        }
        return current->data();
    }

    //! hey
    const T& at(std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Out of range (at)");
        }

        Node* current = head;
        for (auto i = 0u; i < index; ++i) {
            current = current->next();
        }
        return current->data();
    }

    //! hey
    T pop(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Out of range (pop)");
        }

        if (index >= size_) {
            throw std::out_of_range("Invalid index");
        }

        if (index == 0) {
            return pop_front();
        }


        auto current = head;

        for (auto i = 0u; i < index - 1; ++i) {
            current = current->next();
        }

        auto aux_node = current->next();
        auto temp = aux_node->data();
        current->next(aux_node->next());
        current->prev(aux_node->prev());
        delete aux_node;

        --size_;

        return temp;
    }

    //! hey
    T pop_back() {
        return pop(size_ - 1);
    }

    //! hey
    T pop_front() {
        if (empty()) {
            throw std::out_of_range("Empty (pop_front)");
        }

        auto aux_node = head;
        head = head->next();

        auto aux_data = aux_node->data();
        delete aux_node;

        --size_;
        return aux_data;
    }

    //! hey
    void remove(const T& data) {
        if (find(data) == size_) {
        } else {
            pop(find(data));
        }
    }

    //! hey
    bool empty() const {
        return size_ == 0;
    }

    //! hey
    bool contains(const T& data) const {
        return find(data) < size_;
    }

    //! hey
    std::size_t find(const T& data) const {
        auto current = head;
        auto i = 0u;

        if (empty()) {
            throw std::out_of_range("Out of range (find)");
        }

        while (i < size_) {
            if (current->data() == data) {
                break;
            }
            ++i;
            current = current->next();
        }
        return i;
    }

    //! hey
    std::size_t size() const {
        return size_;
    }

private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        Node(const T& data, Node* prev, Node* next):
            data_{data},
            prev_{prev},
            next_{next}
        {}

        T& data() {
            return data_;
        }

        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }
        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* prev_{nullptr};
        Node* next_{nullptr};
    };

    Node* head{nullptr};
    std::size_t size_{0u};
};

} //  namespace structures

#endif
