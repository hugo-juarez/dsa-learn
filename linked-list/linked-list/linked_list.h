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
    std::shared_ptr<Node> last;
    
public:
    LinkedList();
    LinkedList(int A[], int n);
    void Insert(int pos, int x);
    void Append(int x);
    void InsertSorted(int x);
    bool isSorted(void);
    int Length(void);
    int Sum(void);
    int Max(void);
    std::shared_ptr<Node> Search(int x);
    friend std::ostream & operator<<(std::ostream &os, const LinkedList &l);
    
    
};


#endif
