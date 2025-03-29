//
//  linked_list.h
//  linked-list
//
//  Created by Hugo Juarez on 3/29/25.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <iostream>

class LinkedList {
private:
    struct Node{
        int data;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> first;
    
public:
    LinkedList();
    LinkedList(int A[], int n);
    friend std::ostream & operator<<(std::ostream &os, const LinkedList &l);
    
    
};


#endif
