//
//  queue_linked_list.cpp
//  queue
//
//  Created by Hugo Juarez on 4/8/25.
//

#include "queue_linked_list.hpp"
#include <memory>
#include <iostream>

QueueLinked::QueueLinked() : front(nullptr), rear(nullptr) {}

void QueueLinked::enqueue(int x){
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data = x;
    t->next = nullptr;
    
    if(isEmpty()){
        front=rear=t;
    }else{
        rear->next = t;
        rear = t;
    }
}

int QueueLinked::dequeue(void){
    if(isEmpty())
        throw std::underflow_error("Queue is empty");
    
    int x = front->data;
    
    if(front == rear){
        front=rear=nullptr;
    } else{
        front = front->next;
    }
    
    return x;
}

bool QueueLinked::isEmpty() const{
    return !front;
}

std::ostream & operator<<(std::ostream &os, const QueueLinked &q){
    
    if(q.isEmpty()){
        os << "[]";
        return os;
    }
    
    os << "[ ";
    
    std::shared_ptr<QueueLinked::Node> p = q.front;
    
    while(p){
        os << p->data;
        if(p->next)
            os << ", ";
        p = p->next;
    }
    
    os << " ]";
    
    return os;
}
