//! Copyright 2019 Gabriel Simonetto
#ifndef STRUCTURES_DOUBLY_LINKED_LIST_H
#define STRUCTURES_DOUBLY_LINKED_LIST_H

#include <stdexcept>
#include <cstdint>

namespace structures {

//! ...
template<typename T>
class DoublyLinkedList {
 public:
    //! ...
    DoublyLinkedList();
    //! ...
    ~DoublyLinkedList();
    //! ...
    void clear();
    //! ...
    void push_back(const T& data);  // insere no fim
    //! ...
    void push_front(const T& data);  // insere no início
    //! ...
    void insert(const T& data, std::size_t index);  // insere na posição
    //! ...
    void insert_sorted(const T& data);  // insere em ordem
    //! ...
    T pop(std::size_t index);  // retira da posição
    //! ...
    T pop_back();  // retira do fim
    //! ...
    T pop_front();  // retira do início
    //! ...
    void remove(const T& data);  // retira específico
    //! ...
    bool empty() const;  // lista vazia
    //! ...
    bool contains(const T& data) const;  // contém
    //! ...
    T& at(std::size_t index);  // acesso a um elemento (checando limites)
    //! ...
    const T& at(std::size_t index) const;  // getter constante a um elemento
    //! ...
    std::size_t find(const T& data) const;  // posição de um dado
    //! ...
    std::size_t size() const;  // tamanho
    //! debug stuff
    bool isheadNull();
    bool istailNull();
    
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

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* prev() {  // getter: próximo
            return prev_;
        }

        const Node* prev() const {  // getter const: próximo
            return prev_;
        }

        void prev(Node* node) {  // setter: próximo
            prev_ = node;
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
        Node* prev_;
        Node* next_;
    };

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head;  // primeiro da lista
    Node* tail;  // ultimo da lista
    std::size_t size_;
};

template<typename T>
structures::DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

template<typename T>
structures::DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
void structures::DoublyLinkedList<T>::clear() {
    Node* atual = head;
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
void structures::DoublyLinkedList<T>::push_back(const T& data) {
    Node* new_node = new DoublyLinkedList::Node{data, tail, nullptr};
    if (tail != nullptr) {
        tail->next(new_node);
    } else {
        head = new_node;
    }
    tail = new_node;
    size_++;
}

template<typename T>
void structures::DoublyLinkedList<T>::push_front(const T& data) {
    Node* new_node = new DoublyLinkedList::Node{data, nullptr, head};
    if (head != nullptr) {
        head->prev(new_node);
    } else {
        tail = new_node;
    }
    head = new_node;
    size_++;
}

template<typename T>
void structures::DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
    if (index == 0) {
        push_front(data);
        return;
    }
    if (index == size_) {
        push_back(data);
        return;
    }
    if (index > size_) {
        throw std::out_of_range("thats not possible");
    }
    // primeiro, va ate o indice
    size_t i = 0;
    Node* anterior = nullptr;
    Node* atual = head;
    while (i < index) {
        anterior = atual;
        atual = atual->next();
        i++;
    }
    Node* new_node = new DoublyLinkedList::Node{data, anterior, atual};
    anterior->next(new_node);
    atual->prev(new_node);
    size_++;
}

template<typename T>
void structures::DoublyLinkedList<T>::insert_sorted(const T& data) {
    if (empty() || data < head->data()) {
        push_front(data);
        return;
    } else if (data > tail->data()) {
        push_back(data);
        return;
    }
    Node* anterior = head;
    Node* atual = head->next();
    while (data > atual->data()) {
        anterior = atual;
        atual = atual->next();
    }
    Node* new_node = new Node(data, anterior, atual);
    anterior->next(new_node);
    atual->prev(new_node);
    size_++;
}

template<typename T>
T structures::DoublyLinkedList<T>::pop(std::size_t index) {
    if (empty() && index >= size_) {
        throw std::out_of_range("lista vazia");
    } else if (index == 0) {
        pop_front();
    } else if (index == size_-1) {
        pop_back();
    }
    Node* anterior = head;
    Node* atual = head->next();
    size_t i = 1;
    while (i < index) {
        anterior = atual;
        atual = atual->next();
        i++;
    }
    T valor = atual->data();
    Node* ahead = atual->next();
    anterior->next(ahead);
    ahead->prev(anterior);
    size_--;
    return valor;
}

template<typename T>
T structures::DoublyLinkedList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    T valor = tail->data();
    tail = tail->prev();
    if (size_ == 1) {
        head = nullptr;
    }
    size_--;
    return valor;
}

template<typename T>
T structures::DoublyLinkedList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    T valor = head->data();
    head = head->next();
    if (size_ == 1) {
        tail = nullptr;
    }
    size_--;
    return valor;
}

template<typename T>
void structures::DoublyLinkedList<T>::remove(const T& data) {
    if (data == head->data()) {
        pop_front();
        return;
    } else if (data == tail->data()) {
        pop_back();
        return;
    }
    Node* atual = head->next();
    size_t i = 1;
    while (atual->data() != data && atual != nullptr) {
        atual = atual->next();
        i++;
    }
    if (atual != nullptr) {
        pop(i);
    }
}

template<typename T>
bool structures::DoublyLinkedList<T>::empty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

template<typename T>
bool structures::DoublyLinkedList<T>::contains(const T& data) const {
    Node* atual = head;
    while (atual != nullptr) {
        if (atual->data() == data) {
            return true;
        }
        atual = atual->next();
    }
    return false;
}

template<typename T>
T& structures::DoublyLinkedList<T>::at(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("thats not possible");
    }
    Node* atual = head;
    size_t i = 0;
    while (i < index) {
        atual = atual->next();
        i++;
    }
    return atual->data();
}

template<typename T>
const T& structures::DoublyLinkedList<T>::at(std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("thats not possible");
    }
    Node* atual = head;
    size_t i = 0;
    while (i < index) {
        atual = atual->next();
        i++;
    }
    return atual->data();
}


template<typename T>
std::size_t structures::DoublyLinkedList<T>::find(const T& data) const {
    Node* atual = head;
    size_t pos = 0;
    while (atual != nullptr) {
        if (atual->data() == data) {
            return pos;
        }
        pos++;
        atual = atual->next();
    }
    return size_;
}

template<typename T>
std::size_t structures::DoublyLinkedList<T>::size() const {
    return size_;
}

template<typename T>
bool structures::DoublyLinkedList<T>::isheadNull() {
    return (empty() || 8 >= size_);
}

template<typename T>
bool structures::DoublyLinkedList<T>::istailNull() {
    return tail==nullptr;
}

}  // namespace structures

#endif
