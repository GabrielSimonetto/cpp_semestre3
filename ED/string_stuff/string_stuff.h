//! Copyright [2018] <Gabriel Frank Simonetto>


#ifndef STRUCTURES_STRING_LIST_H
#define STRUCTURES_STRING_LIST_H

#include <cstdint>
#include <stdexcept>  // C++ exceptions
#include <cstring>



namespace structures {


//! ...
template<typename T>
class ArrayList {
 public:
    //! ...
    ArrayList();
    //! ...
    explicit ArrayList(std::size_t max_size);
    //! ...
    ~ArrayList();

    //! ...
    void clear();
    //! ...
    void push_back(const T& data);
    //! ...
    void push_front(const T& data);
    //! ...
    void insert(const T& data, std::size_t index);
    //! ...
    void insert_sorted(const T& data);
    //! ...
    T pop(std::size_t index);
    //! ...
    T pop_back();
    //! ...
    T pop_front();
    //! ...
    void remove(const T& data);
    //! ...
    bool full() const;
    //! ...
    bool empty() const;
    //! ...
    bool contains(const T& data) const;
    //! ...
    std::size_t find(const T& data) const;
    //! ...
    std::size_t size() const;
    //! ...
    std::size_t max_size() const;
    //! ...
    T& at(std::size_t index);
    //! ...
    T& operator[](std::size_t index);
    //! ...
    const T& at(std::size_t index) const;
    //! ...
    const T& operator[](std::size_t index) const;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};


template<typename T>
structures::ArrayList<T>::ArrayList() {
    max_size_ = DEFAULT_MAX;
    contents = new T[max_size_];
    size_ = 0;
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
    max_size_ = max_size;
    contents = new T[max_size_];
    size_ = 0;
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
    delete [] contents;
}

template<typename T>
void structures::ArrayList<T>::clear() {
    size_ = 0
}

template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    if (full()) {
        throw std::out_of_range("lista cheia");
    } else {
        contents[size_] = data;
        size_++;   
    }
}

template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    insert(data ,0)
}

template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full()) {
        throw std::out_of_range("lista cheia");        
    } else {
        size_++;
        for (int i = size_; i >= index; i--) {
            contents[i] = contents[i-1];
        }
    }
}

template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    if (full()) {
        throw std::out_of_range("lista cheia");        
    } else {
        int i = 0;
        while (contents[i] < data) {
            i++;
        }
        insert(i);
    }
}

template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        for (int i = index+1; i < size_; i++) {
            contents[i-1] = contents[i];
        }        
    }
}

template<typename T>
T structures::ArrayList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        size_--;  
    }
}

template<typename T>
T structures::ArrayList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        pop(0);
    }
}

template<typename T>
void structures::ArrayList<T>::remove(const T& data) {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        for (int i = 0; i < size_; i++) {
            if (contents[i] == data) {
                pop(i)
                i--;
            }
        }
    }
}

template<typename T>
bool structures::ArrayList<T>::full() const{
    return size_ >= max_size_;
}

template<typename T>
bool structures::ArrayList<T>::empty() const{
    return size_ == 0;
}

template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data) {
            return true;
        }
    }
    return false;
}

template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_;
}

template<typename T>
std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}

template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data) {
            return i;
        }
    }
    return size_;
}

template<typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("esse elemento nao existe");
    } else {
        return contents[index];
    }
}

template<typename T>
T& structures::ArrayList<T>::operator [](std::size_t index) {
    return contents[index];
}

template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("esse elemento nao existe");
    } else {
        return contents[index];
    }
}

template<typename T>
const T& structures::ArrayList<T>::operator [](std::size_t index) const {
    return contents[index];
}

//! ...
//! ArrayListString e' uma especializacao da classe ArrayList
class ArrayListString : public ArrayList<char *> {
 public:
    //! ...
    ArrayListString() : ArrayList() {}
    //! ...
    explicit ArrayListString(std::size_t max_size) : ArrayList(max_size) {}
    //! ...
    ~ArrayListString();

    //! ...
    void clear();
    //! ...
    void push_back(const char *data);
    //! ...
    void push_front(const char *data);
    //! ...
    void insert(const char *data, std::size_t index);
    //! ...
    void insert_sorted(const char *data);
    //! ...
    char *pop(std::size_t index);
    //! ...
    char *pop_back();
    //! ...
    char *pop_front();
    //! ...
    void remove(const char *data);
    //! ...
    bool contains(const char *data);
    //! ...
    std::size_t find(const char *data);
};

structures::ArrayListString::~ArrayListString() {
    for (size_t i = 0; i < size_; i++) {
        delete [] contents[i];
    }
}

void structures::ArrayListString::clear() {
    size_ = 0;
}

void structures::ArrayListString::push_back(const char *data) {
    ArrayList::push_back(data);
}

void structures::ArrayListString::push_front(const char *data) {
    ArrayList::push_front(data);
}

// Rever daqui pra baixo

void structures::ArrayListString::insert(const char *data, std::size_t index) {
    char * datanew = new char[strlen(data)];
    snprintf(datanew, strlen(data)+1, "%s", data);
    ArrayList<char*>::insert(datanew, index);
}

void structures::ArrayListString::insert_sorted(const char *data) {
    if (full()) {
        throw std::out_of_range("lista cheia");
    } else {
        std::size_t i;
        // salvo na ultima posicao caso ele nao encontre nenhum maior
        std::size_t posicao = size_;
        // percorro o array
        for (i = 0; i < size_; i++) {
            if (strcmp(data, contents[i]) < 0) {
                posicao = i;
                break;
            }
        }
        insert(data, posicao);
    }
}

char* structures::ArrayListString::pop(std::size_t index) {
    return ArrayList<char*>::pop(index);
}

char* structures::ArrayListString::pop_back() {
    return ArrayList<char*>::pop_back();
}

char* structures::ArrayListString::pop_front() {
    return ArrayList<char*>::pop_front();
}

void structures::ArrayListString::remove(const char *data) {
    std::size_t posicao = find(data);
    pop(posicao);
}

bool structures::ArrayListString::contains(const char *data) {
    for (std::size_t i =0; i <size_; i++) {
        if (strcmp(contents[i], data) == 0) {
            return true;
        }
    }
    return false;
}

std::size_t structures::ArrayListString::find(const char *data) {
    for (std::size_t i =0; i <size_; i++) {
        if (strcmp(contents[i], data) == 0) {
            return i;
        }
    }
    return size_;
}

}  // namespace structures

#endif
