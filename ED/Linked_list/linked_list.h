//! Copyright 2019 Gabriel Simonetto
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <stdexcept>
#include <cstdint>


namespace structures {

//! ...
template<typename T>
class LinkedList {
 public:
    //! ...
    LinkedList();  // construtor padrão
    //! ...
    ~LinkedList();  // destrutor
    //! ...
    void clear();  // limpar lista
    //! ...
    void push_back(const T& data);  // inserir no fim
    //! ...
    void push_front(const T& data);  // inserir no início
    //! ...
    void insert(const T& data, std::size_t index);  // inserir na posição
    //! ...
    void insert_sorted(const T& data);  // inserir em ordem
    //! ...
    T& at(std::size_t index);  // acessar um elemento na posição index
    //! ...
    T pop(std::size_t index);  // retirar da posição
    //! ...
    T pop_back();  // retirar do fim
    //! ...
    T pop_front();  // retirar do início
    //! ...
    void remove(const T& data);  // remover específico
    //! ...
    bool empty() const;  // lista vazia
    //! ...
    bool contains(const T& data) const;  // contém
    //! ...
    std::size_t find(const T& data) const;  // posição do dado
    //! ...
    std::size_t size() const;  // tamanho da lista

 private:
    class Node {  // Elemento
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
        Node* next_{nullptr};
    };

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};

template<typename T>
structures::LinkedList<T>::LinkedList() {
    head = nullptr;
    size_ = 0;
}

template<typename T>
structures::LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void structures::LinkedList<T>::clear() {
    Node* atual = head;
    Node* anterior = nullptr;
    while (atual != nullptr) {
        anterior = atual;
        atual = atual->next();
        delete(anterior);
    }
    head = nullptr;
    size_ = 0;
}

template<typename T>
void structures::LinkedList<T>::push_back(const T& data) {
    insert(data, size_);
}

template<typename T>
void structures::LinkedList<T>::push_front(const T& data) {
    Node* new_node = new LinkedList::Node{data, head};
    head = new_node;
    size_++;
}

template<typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index) {
    if (index == 0) {
        push_front(data);
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
    Node* new_node = new Node(data, atual);
    anterior->next(new_node);
    size_++;
}

template<typename T>
void structures::LinkedList<T>::insert_sorted(const T& data) {
    if (empty() || data < head->data()) {
        push_front(data);
        return;
    }
    Node* anterior = head;
    Node* atual = head->next();
    while (atual != nullptr && data > atual->data()) {
        anterior = atual;
        atual = atual->next();
    }
    Node* new_node = new Node(data, atual);
    anterior->next(new_node);
    size_++;
}

template<typename T>
T& structures::LinkedList<T>::at(std::size_t index) {
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
T structures::LinkedList<T>::pop(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("thats not possible");
    } else if (index == 0) {
        return pop_front();
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
    anterior->next(atual->next());
    size_--;
    return valor;
}

template<typename T>
T structures::LinkedList<T>::pop_back() {
    return pop(size_-1);
}

template<typename T>
T structures::LinkedList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    T valor = head->data();
    head = head->next();
    size_--;
    return valor;
}

template<typename T>
void structures::LinkedList<T>::remove(const T& data) {
    Node* atual = head;
    size_t i = 0;
    while (atual->data() != data && atual != nullptr) {
        atual = atual->next();
        i++;
    }
    if (atual != nullptr) {
        pop(i);
    }
}

template<typename T>
bool structures::LinkedList<T>::empty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

template<typename T>
bool structures::LinkedList<T>::contains(const T& data) const {
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
std::size_t structures::LinkedList<T>::find(const T& data) const {
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
std::size_t structures::LinkedList<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
