//
//  stack_array.h
//  stack
//
//  Created by Hugo Juarez on 4/2/25.
//
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <memory>
#include <iostream>

class StackArray {
private:
    int size;
    int top;
    std::unique_ptr<int[]> A;
public:
    StackArray(int sz);
    void push(int x);
    int pop(void);
    int peek(int pos);
    int stackTop(void);
    bool isEmpty(void);
    bool isFull(void);
    friend std::ostream & operator<<(std::ostream &os, StackArray &s);
};

#endif
