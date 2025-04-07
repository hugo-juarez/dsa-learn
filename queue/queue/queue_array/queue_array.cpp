//
//  queue_array.cpp
//  queue
//
//  Created by Hugo Juarez on 4/7/25.
//

#include "queue_array.hpp"
#include <memory>
#include <iostream>


QueueArray::QueueArray(int sz) : A(std::make_unique<int[]>(sz)) , front(-1), rear(-1), size(sz){}

void QueueArray::enqueue(int x){
    if(isFull())
        throw std::out_of_range("Queue is full, can't add another element");
    
    A[++rear] = x;
}

int QueueArray::dequeue(){
    if(isEmpty())
        throw std::out_of_range("Queue is empty, can't dequeue another element");
    
    return A[++front];
}

bool QueueArray::isEmpty() const{
    return rear==front;
}

bool QueueArray::isFull() const{
    return rear==size-1;
}

int QueueArray::first() const{
    if(isEmpty())
        return -1;
    return A[front+1];
}

int QueueArray::last() const{
    if(isEmpty())
        return -1;
    return A[rear];
}

std::ostream & operator<<(std::ostream &os, const QueueArray &q){
    if(q.isEmpty()){
        os << "[]";
        return os;
    }
    
    os << "[ ";
    for(int i=q.front+1; i<q.rear+1; i++ ){
        os << q.A[i];
        if(i!=q.rear)
            os << ", ";
    }
    
    os << " ]";
    
    return os;
}
