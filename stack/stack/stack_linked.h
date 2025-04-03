//
//  stack_linked.h
//  stack
//
//  Created by Hugo Juarez on 4/2/25.
//

#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include <memory>

class StackLinked {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> top;
public:
    StackLinked();
    void push(int x);
    int pop(void);
    int peek(int pos);
    int stackTop(void);
    bool isEmpty(void);
    bool isFull(void);
    friend std::ostream & operator<<(std::ostream &os, StackLinked &s);
};

#endif
