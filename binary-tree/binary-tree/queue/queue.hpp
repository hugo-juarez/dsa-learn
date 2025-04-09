//
//  queue.hpp
//  binary-tree
//
//  Created by Hugo Juarez on 4/8/25.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include <memory>

template <typename T>
class Queue{
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> front;
    std::shared_ptr<Node> rear;
    
public:
    Queue();
    void enqueue(T x);
    T dequeue();
    bool isEmpty() const;
};

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr){}

template <typename T>
void Queue<T>::enqueue(T x){
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data = x;
    t->next = nullptr;
    
    if(isEmpty())
        front=rear=t;
    else{
        rear->next = t;
        rear = t;
    }
}

template <typename T>
T Queue<T>::dequeue(){
    if(isEmpty())
        throw std::underflow_error("Queue is empty");
    
    T x = front->data;
    
    if(front==rear)
        front=rear=nullptr;
    else{
        front=front->next;
    }
    
    return x;
}

template <typename T>
bool Queue<T>::isEmpty() const{
    return !front;
}

#endif /* queue_hpp */
