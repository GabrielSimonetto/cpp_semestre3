//! Copyright 2019 Gabriel Simonetto

#include <iostream>
#include <string>
#include <stddef.h>

const size_t CHILDREN_NUMBER = 26;

 //! Trie class
class Trie {
 public:
    //! Constructor
    Trie() {
        root = new Node();    
    }

    //! Destructor
    virtual ~Trie() {
        delete root;
    }

    //! insert a word calling insert letter from node 
    void insert(std::string word,
                const unsigned long position,
                const unsigned long length) {
        root->insert_letter(word, 0, position, length);
    }

    //! find a word in the trie
    unsigned long* find(std::string word, unsigned long* output) {
        return root->find_letter(word, 0, output);
    } 

 private:
    //! Node class
    class Node {
     public:
        //! Default Constructor
        Node(): 
            children(),
            position_{0},
            length_{0}
        {}

        //! Constructor with args
        Node(const unsigned long position,
             const unsigned long length):
            children(),
            position_{position},
            length_{length}
        {}

        //! Destructor
        ~Node() {
            for (int i = 0; i < CHILDREN_NUMBER; i++) {
                delete children[i];
            }
        }

        //! Get position
        const unsigned long get_position() {  // getter: position
            return position_;
        }

        //! Get length
        const unsigned long get_length() {  // getter: length
            return length_;
        }

        //! Set position
        void set_position(const unsigned long position) {  // setter: position
            position_ = position;
        }

        //! Set length
        void set_length(const unsigned long length) {  // setter: length
            length_ = length;
        }

        //! Set data
        void set_data(const unsigned long position,
                        const unsigned long length) {
            set_position(position);
            set_length(length);
        }

        //! Insert letter
        void insert_letter(std::string word, 
                            std::size_t index,
                            const unsigned long position,
                            const unsigned long length) {
            std::size_t char_pos = word[index] - 'a';
            
            if (children[char_pos] == nullptr) {
                children[char_pos] = new Node();
            }

            Node* next = children[char_pos];

            if (last_letter(word, index)) {
                next->set_data(position, length);
            } else {
                next->insert_letter(word, index+1, position, length);
            }
        }

        /*! return [position, length, status]
            status = (0: success, 1: prefix, 2: notprefix) */
        unsigned long* find_letter(std::string word,
                                    std::size_t index,
                                    unsigned long* output) {

            std::size_t char_pos = word[index] - 'a';
            Node* next = children[char_pos];

            if (next == nullptr) {
                output[2] = 2;
                return output;
            }

            if (last_letter(word, index)) {
                output[0] = next->get_position();
                output[1] = next->get_length();
                if (output[0] == 0 and output[1] == 0) {
                    output[2] = 1;
                } else {
                    output[2] = 0;
                }
                return output;
            }
            
            return next->find_letter(word, index+1, output);
        }

        //! return true for last letter on word
        bool last_letter(std::string word, std::size_t index) {
            return index == word.length()-1;
        }

     private:
        Node* children[CHILDREN_NUMBER];
        unsigned long position_;
        unsigned long length_;
    };

    Node* root;
};
