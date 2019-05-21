#ifndef TREE_H
#define TREE_H
#include <container.h>
#include <iostream>

template<typename T>
class Tree : public Container<T>{
public:
    T valuevo;
    Tree<T>* right;
    Tree<T>* left;
    Tree<T>* parent;
    Tree(T value = 0){
        valuevo = value;
        right = nullptr;
        left = nullptr;
        parent = nullptr;
    }
    void insert(T value) override{
        if(value > valuevo){
            if(right == nullptr){
                Tree<T>* buf = new Tree<T>(value);
                right = buf;
                right->parent = this;
            } else
                right->insert(value);
        } else {
            if(left == nullptr){
                Tree<T>* buf = new Tree<T>(value);
                left = buf;
                left->parent = this;
            } else
                left->insert(value);
        }
    }
    bool exists(T value) override{
        bool flag;
        if(value == valuevo)
            flag = true;
        if(value > valuevo){
            if(right == nullptr)
                return false;
            else
                flag = right->exists(value);
        }
        if(value < valuevo){
            if(left == nullptr)
                return false;
            else
                flag = left->exists(value);
        }
        return flag;
    }

    void remove(T value) override{
        if(exists(value)){
            if(value != valuevo){
                if(value > valuevo)
                    right->remove(value);
                else
                    left->remove(value);
            } else {
                if(right == nullptr){
                    if(left == nullptr){
                        if(parent->right == this){
                            delete parent->right;
                            parent->right = nullptr;
                        }
                        else {
                            delete parent->left;
                            parent->left = nullptr;
                        }
                    } else {
                        Tree<T>* buf = left;
                        Tree<T>* buf2 = this;
                        left->parent = parent;
                        left = nullptr;
                        if(parent->right == this){
                            parent->right = buf;
                            delete buf2;
                        } else {
                            parent->left = buf;
                            delete buf2;
                        }
                    }
                } else {
                    Tree<T>* buf = right;
                    while(buf->left != nullptr)
                        buf = buf->left;
                    valuevo = buf->valuevo;
                    buf->valuevo = value;
                    buf->remove(value);
                }
            }
        }
    }

    void print() override{
        std::cout << valuevo << std::endl;
        if(right != nullptr)
            right->print();
        if(left != nullptr)
            left->print();
    }
    ~Tree() override{
        delete right;
        delete left;
    }
};

#endif // TREE_H
