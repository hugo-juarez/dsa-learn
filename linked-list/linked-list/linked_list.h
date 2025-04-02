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
    void ReverseRecurs(std::shared_ptr<Node> q, std::shared_ptr<Node> p);
    
public:
    LinkedList();
    LinkedList(int A[], int n);
    void RemoveDuplicates(void);
    void ReverseArray(void);
    void ReverseSlidingPtr(void);
    void ReverseRecursively(void);
    void Insert(int pos, int x);
    void Append(int x);
    void InsertSorted(int x);
    void Merge(LinkedList &l2);
    bool isSorted(void);
    bool isLoop(void);
    int Delete(int pos);
    int Length(void);
    int Sum(void);
    int Max(void);
    std::shared_ptr<Node> Search(int x);
    LinkedList createLoop(void);
    LinkedList operator+(const LinkedList &l2) const;
    friend std::ostream & operator<<(std::ostream &os, const LinkedList &l);
    
    
};


#endif
