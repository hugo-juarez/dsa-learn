//
//  linked_list.h
//  stack
//
//  Created by Hugo Juarez on 4/6/25.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>

class LinkedList {
public:
    struct Node {
        char data;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> first;
    LinkedList();
    void push(char x);
    
};

#endif
