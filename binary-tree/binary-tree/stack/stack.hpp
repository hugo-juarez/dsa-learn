//
//  stack.hpp
//  binary-tree
//
//  Created by Hugo Juarez on 4/9/25.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <memory>

template <typename T>
class Stack{
private:
    struct Node{
        T data;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> top;
public:
    Stack();
    void push(T x);
    T pop();
    bool isEmpty();
};


template <typename T>
Stack<T>::Stack() : top(nullptr){}

template <typename T>
void Stack<T>::push(T x){
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data = x;
    t->next = top;
    
    top = t;
}

template <typename T>
T Stack<T>::pop(){
    if(isEmpty())
        throw std::runtime_error("Stack is empty");
    
    T x = top->data;
    top = top->next;
    return x;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return !top;
}

#endif /* stack_hpp */
