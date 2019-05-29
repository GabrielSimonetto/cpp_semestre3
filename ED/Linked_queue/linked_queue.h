//! Copyright 2019 Gabriel Simonetto
#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <stdexcept>
#include <cstdint>

namespace structures {

//! ...
template<typename T>
class LinkedQueue {
 public:
    LinkedQueue();

    ~LinkedQueue();
    //! ...
    void clear();
    //! ...
    void enqueue(const T& data); // enfilerar
    //! ...
    T dequeue(); // desenfilerar
    //! ...
    T& front() const; // primeiro dado
    //! ...
    T& back() const; // último dado
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

    Node* head;  // nodo-cabeça
    Node* tail;  // nodo-fim
    std::size_t size_;  // tamanho
};

template<typename T>
structures::LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

template<typename T>
structures::LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void structures::LinkedQueue<T>::clear() {
    Node* atual = tail;
    Node* anterior = nullptr;
    while (atual != nullptr) {
        anterior = atual;
        atual = atual->next();
        delete(anterior);
    }
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

template<typename T>
void structures::LinkedQueue<T>::enqueue(const T& data) {
    Node* new_node = new LinkedQueue::Node{data, nullptr};
    if (size_ == 0) {
        tail = new_node;
        head = new_node;
    } else {
        tail->next(new_node);
        tail = new_node;
    }
    size_++;
}

template<typename T>
T structures::LinkedQueue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    T valor = head->data();
    head = head->next();
    size_--;
    if (size_ == 0) {
        tail = nullptr;
    }
    return valor;
}

template<typename T>
T& structures::LinkedQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    return head->data();
}

template<typename T>
T& structures::LinkedQueue<T>::back() const {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    return tail->data();
}

template<typename T>
bool structures::LinkedQueue<T>::empty() const {
    if (size_ == 0) {
        return true;
    }
    return false;
}

template<typename T>
std::size_t structures::LinkedQueue<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
