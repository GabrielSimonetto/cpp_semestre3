/* Copyright 2019 Gabriel Simonetto */

#ifndef STRUCTURES_AVL_TREE_H
#define STRUCTURES_AVL_TREE_H

#include <cstdint>
#include <stdexcept>  // C++ exception
#include "array_list.h"

template<typename T>
class ArrayList;

namespace structures {

template<typename T>
//! Classe AVLTree
class AVLTree {
 public:
    //! Construtor Default
    AVLTree() = default();

    //! Destrutor
    ~AVLTree() {size_ = 0;}

    //! Inserir
    void insert(const T& data) {
        if (empty()) {
            root = new Node{data};
        } else {
            root = root->insert(data);
        }
        size_++;
    }

    //! remover
    void remove(const T& data) {
        bool check;
        if (empty()) {
            return;
        } else {
            check = root->remove(data);
            if (check) {
                --size_;
            }
        }
    }

    //! contem
    bool contains(const T& data) const {
    if (empty())
            return false;
    else
        return root->contains(data);
    }

    //! vazio
    bool empty() const {
        return (size_ == 0);
    }

    //! size
    std::size_t size() const {
        return size_;
    }

    //! pre order
    ArrayList<T> pre_order() const {
        structures::ArrayList<T> v{};

        if (!empty()) {
            root->pre_order(v);
        }
        return v;
    }

    //! in order
    ArrayList<T> in_order() const {
        structures::ArrayList<T> v{};

        if (!empty()) {
            root->in_order(v);
        }
        return v;
    }

    //! post order
    ArrayList<T> post_order() const {
        structures::ArrayList<T> v{};

        if (!empty()) {
            root->post_order(v);
        }
        return v;
    }

 protected:
    //! Node
    struct Node {
        //! construtor
        explicit Node(const T& data_):
            data{data},
            height = 1;
            left{nullptr},
            right{nullptr}
        {}

        //! data
        T data;
        //! size
        std::size_t height;
        //! left
        Node* left;
        //! right
        Node* right;
            // eh um insert binario com o teste e chamadas
            // Node* arv_rodada;
            // if (arv = nullptr) {
            //     arv = Node(data_);
            // }

            // if (data_ < data) {
            //     // Insert to the left
            //     if (left == nullptr) {
            //         auto new_node = new Node{data_};
            //         left = new_node;
            //     } else {
            //         left->height++;
            //         left->insert(data_);
            //     }
            // } else if (data_ > data) {
            //     // Insert to the right
            //     if (right == nullptr) {
            //         auto new_node = new Node{data_};
            //         right = new_node;
            //     } else {
            //         right->height++;
            //         right->insert(data_);
            //     }
            // }

            // if (is_unbalanced_right) {
            //     //rotate to left
            // }

        //! inserir
        void insert(const T& data_) {
// https://www.sanfoundry.com/cpp-program-implement-avl-trees/
// https://gist.github.com/Harish-R/097688ac7f48bcbadfa5
            if (data_ < data) {
                // Insert to the left
                if (left == nullptr) {
                    auto new_node = new Node{data_};
                    left = new_node;
                } else {
                    left->insert(data_);
                }
            } else if (data_ > data) {
                // Insert to the right
                if (right == nullptr) {
                    auto new_node = new Node{data_};
                    right = new_node;
                } else {
                    right->insert(data_);
                }
            }
            this->right = balance(this->right);
            this->left = balance(this->left);
        }

        //! oi
        Node* balance(Node* temp)
        {
            int height_diff = height_diff(temp);
            if (height_diff > 1)
            {
                if (height_diff (temp->left) > 0)
                    temp = ll_rotation (temp);
                else
                    temp = lr_rotation (temp);

            }
            else if (height_diff < -1)
            {
                if (height_diff (temp->right) > 0)
                    temp = rl_rotation (temp);
                else
                    temp = rr_rotation (temp);
            }
            return temp;
        }

        int height_diff(Node* temp)
        {
            int l_height = height (temp->left);
            int r_height = height (temp->right);
            int diff = l_height - r_height;
            return diff;
        }

        //! remover
        bool remove(const T& data_) {
            if (data_ == data) {
                if (left != nullptr and right != nullptr) {
                    auto aux_node = left_most_node(right);
                    data = aux_node->data;
                    return right->remove(data);
                } else if (right != nullptr) {
                    data = right->data;
                    return right->remove(data);
                } else if (left != nullptr) {
                    data = left->data;
                    return left->remove(data);
                } else {
                    delete this;
                    return true;
                }
            } else {
                if (right != nullptr and data < data_) {
                    return right->remove(data_);
                } else if (left != nullptr and data > data_) {
                    return left->remove(data_);
                }
            }
            return false;
        }

        //! contem
        bool contains(const T& data_) const {
            if (data == data_) {
                return true;
            } else if (left != nullptr and data_ < data) {
                return left->contains(data_);
            } else if (right != nullptr and data_ > data) {
                return right->contains(data_);
            }
            return false;
        }

        //! update height
        void updateHeight() {
            height = std::max(left->height, right->height) + 1;
            // size_t aux = 0;
            // if (left != nullptr) {
            //     aux = std::max(aux, left->updateHeight());
            // }
            // if (right != nullptr) {
            //     aux = std::max(aux, right->updateHeight());
            // } 
            // height = aux+1;
            // return height
        }

        //! simple left
        Node* simpleLeft() {
            Node* k1 = right;
            right = k1->left;
            k1->left = this;

            heigth = updateHeight();
            k1->heigth = updateHeight();
            return k1;
        }

        //! simple right
        Node* simpleRight() {
            Node* k1 = left;
            right = k1->right;
            k1->left = this;

            heigth = updateHeight();
            k1->heigth = updateHeight();
            return k1;
        }

        //! double left
        Node* doubleLeft() {
            Node* temp = this->left;
            this->left = simpleRight(temp);
            return (simpleLeft(this));
        }

        //! double right
        Node* doubleRight() {
            Node* temp = this->right;
            this->right = simpleLeft(temp);
            return (simpleRight(this));
        }

        //! pre_order
        void pre_order(ArrayList<T>& v) const {
            v.push_back(data);  // Root

            if (left != nullptr) {
                left->pre_order(v);
            }
            if (right != nullptr) {
                right->pre_order(v);
            }
        }

        //! in order
        void in_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->in_order(v);
            }

            v.push_back(data);  // Root

            if (right != nullptr) {
                right->in_order(v);
            }
        }

        //! post order
        void post_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->post_order(v);
            }

            if (right != nullptr) {
                right->post_order(v);
            }

            v.push_back(data);  // Root
        }

        //! left most node
        Node* left_most_node(Node* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        //! height
        size_t height(Node* subtree) {
            if (subtree == nullptr) {
                return 0;
            } else {
                return subtree->height;
            }
        }
    };

 private:
    Node* root;
    std::size_t size_;
};

}  // namespace structures
