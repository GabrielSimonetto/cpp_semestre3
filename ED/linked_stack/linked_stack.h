//! Copyright 2019 Gabriel Simonetto
#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include <stdexcept>
#include <cstdint>

namespace structures {

//! ...
template<typename T>
class LinkedStack {
 public:
    LinkedStack();

    ~LinkedStack();
    //! ...
    void clear();
    //! ...
    void push(const T& data);
    //! ...
    T pop();
    //! ...
    T& top() const;
    //! ...
    bool empty() const;
    //! ...
    std::size_t size() const;

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

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_;
    };

    Node* top_;
    std::size_t size_;
};

template<typename T>
structures::LinkedStack<T>::LinkedStack() {
    top_ = nullptr;
    size_ = 0;
}

template<typename T>
structures::LinkedStack<T>::~LinkedStack() {
    clear();
}

template<typename T>
void structures::LinkedStack<T>::clear() {
    Node* atual = top_;
    Node* anterior = nullptr;
    while (atual != nullptr) {
        anterior = atual;
        atual = atual->next();
        delete(anterior);
    }
    top_ = nullptr;
    size_ = 0;
}

template<typename T>
void structures::LinkedStack<T>::push(const T& data) {
    Node* new_node = new LinkedStack::Node{data, top_};
    top_ = new_node;
    size_++;
}

template<typename T>
T structures::LinkedStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    T valor = top_->data();
    top_ = top_->next();
    size_--;
    return valor;
}

template<typename T>
T& structures::LinkedStack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    return top_->data();
}

template<typename T>
bool structures::LinkedStack<T>::empty() const {
    if (size_ == 0) {
        return true;
    }
    return false;
}

template<typename T>
std::size_t structures::LinkedStack<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
