//
//  circular_queue.cpp
//  queue
//
//  Created by Hugo Juarez on 4/7/25.
//

#include "circular_queue.hpp"
#include <memory>
#include <iostream>

CircularQueue::CircularQueue(int sz): size(sz+1), front(0), rear(0), A(std::make_unique<int[]>(sz+1)){}

void CircularQueue::enqueue(int x) {
    if(isFull())
        throw std::overflow_error("Queue is full");
    
    rear = (rear + 1) % size;
    A[rear] = x;
}

int CircularQueue::dequeue() {
    
    if(isEmpty())
        throw std::overflow_error("Queue is empty");
    
    front = (front + 1) % size;
    
    return A[front];
}

bool CircularQueue::isEmpty() const{
    return front == rear;
}

bool CircularQueue::isFull() const{
    return (rear+1)%size == front;
}

std::ostream& operator<<(std::ostream &os, const CircularQueue &q){
    if(q.isEmpty()){
        os << "[]";
        return os;
    }
    
    os << "[ ";
    
    int p = (q.front + 1) % q.size;
    
    while(p!= q.rear){
        os << q.A[p] << ", ";
        p = (p + 1) % q.size;
    }
    
    os << q.A[p] << " ]";
    
    return os;
}
