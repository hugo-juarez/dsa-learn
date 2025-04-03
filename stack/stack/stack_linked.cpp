//
//  stack_linked.cpp
//  stack
//
//  Created by Hugo Juarez on 4/2/25.
//

#include "stack_linked.h"
#include <memory>
#include <iostream>

StackLinked::StackLinked(){
    top = nullptr;
}

void StackLinked::push(int x){
    if(isFull()){
        throw std::runtime_error("Wasn't able to create a new element");
        return;
    }
    
    std::shared_ptr<Node> t = std::make_shared<Node>();
    
    t->data = x;
    t->next = top;
    top = t;
}

int StackLinked::pop(void){
    if(isEmpty())
        return -1;
    
    int x;
    
    x = top->data;
    top = top->next;
    return x;
    
}

int StackLinked::peek(int pos){
    
    int i = 1;
    std::shared_ptr<Node> p = top;
    
    while (p) {
        if(i==pos)
            return p->data;
        i++;
        p = p->next;
    }
    
    return -1;
}

int StackLinked::stackTop(void){
    if(isEmpty())
        return -1;
    
    return top->data;
}

bool StackLinked::isEmpty(){
    if(!top)
        return 1;
    else
        return 0;
}

bool StackLinked::isFull(){
    std::shared_ptr<Node> t = std::make_shared<Node>();
    
    if(!t)
        return 1;
    else
        return 0;
}

std::ostream & operator<<(std::ostream &os, StackLinked &s){
    
    if(!s.top){
        os << "[ ]";
        return os;
    }
    
    int count = 0;
    std::shared_ptr<StackLinked::Node> p = s.top;
    
    while(p){
        p = p->next;
        count++;
    }
    
    std::unique_ptr<int[]> A = std::make_unique<int[]>(count);
    
    int i = 0;
    p = s.top;
    
    
    while(p){
        A[i++] = p->data;
        p = p->next;
    }
    
    os << "[ ";
    
    for(int j=count - 1 ; j>=0; j--){
        os << A[j];
        if(j != 0)
            os << ", ";
        else
            os << " ]";
    }
    
    return os;
    
}
