//
//  stack_array.cpp
//  stack
//
//  Created by Hugo Juarez on 4/2/25.
//

#include "stack_array.h"
#include <memory>
#include <iostream>

StackArray::StackArray(int sz){
    size = sz;
    top = -1;
    A = std::make_unique<int[]>(sz);
}

void StackArray::push(int x){
    if(isFull()){
        throw std::logic_error("Stack Overflow");
        return;
    }
    
    top += 1;
    A[top] = x;
}

int StackArray::pop(void){
    
    if(isEmpty()){
        throw std::logic_error("Stack Underflow");
        return -1;
    }
    
    return A[top--];
}

int StackArray::peek(int pos){
    if(pos < 1 || pos > top + 1){
        throw std::logic_error("Invalid position");
        return -1;
    }
    
    return A[top + 1 - pos];
}

int StackArray::stackTop(void){
    if(isEmpty())
        return -1;
    
    return A[top];
}

bool StackArray::isEmpty(void){
    if(top == -1)
        return 1;
    else
        return 0;
}

bool StackArray::isFull(void){
    if(top == size - 1)
        return 1;
    else
        return 0;
}

std::ostream & operator<<(std::ostream &os, StackArray &s){
    os << "[ ";
    for(int i=0; i<=s.top; i++){
        os << s.A[i];
        if(i != s.top)
            os << ", ";
    }
    os << " ]";
    return os;
}
