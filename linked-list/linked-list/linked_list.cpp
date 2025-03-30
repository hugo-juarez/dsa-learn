//
//  linked_list.cpp
//  linked-list
//
//  Created by Hugo Juarez on 3/29/25.
//

#include "linked_list.h"
#include <memory>

LinkedList::LinkedList(){
    first = nullptr;
    last = nullptr;
}

LinkedList::LinkedList(int A[], int n){
    
    if(n==0)
        return;
    
    first = std::make_shared<Node>();
    first->data = A[0];
    
    std::shared_ptr<Node> temp = first;
    
    for(int i=1;i<n;i++){
        temp->next = std::make_shared<Node>();
        temp = temp->next;
        temp->data = A[i];
    }
    
    last = temp;
    
}

void LinkedList::RemoveDuplicates(void){
    if(!isSorted()){
        throw std::logic_error("List is not sorted!");
    }
    std::shared_ptr<Node> p = first;
    std::shared_ptr<Node> q = nullptr;
    
    while (p) {
        if(q && q->data == p->data){
            q->next = p->next;
        }
        else
            q = p;
        p = p->next;
    }
    
    last = q;
}

void LinkedList::Insert(int pos, int x){
    if(pos < 0 || pos > Length()){
        throw std::runtime_error("Invalid index");
        return;
    }
    
    std::shared_ptr<Node> t = std::make_shared<Node>();
    std::shared_ptr<Node> p = first;
    
    t->data = x;
    
    if(pos == 0){
        t->next = first;
        first = t;
    } else{
        
        for(int i=1; i<pos;i++){
            p = p->next;
        }
        
        t->next = p->next;
        p->next = t;
    }
    
    if(!t->next)
        last = t;
    
}

void LinkedList::Append(int x){
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data = x;
    if(!first){ //If the pointer is empty
        first = t;
        last = t;
    }else{
        last->next = t;
        last = t;
    }
}

void LinkedList::InsertSorted(int x){
    if(!isSorted())
        throw std::runtime_error("Linked List is not Sorted!");
    
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data = x;
    
    if(!first){ // If list is empty append new element
        first = last = t;
        return;
    }
    
    std::shared_ptr<Node> p = first;
    std::shared_ptr<Node> q = nullptr;
    
    while (p && p->data < x) {
        q = p;
        p = p->next;
    }
    
    t->next = p;
    if(q){ //Check if we are adding at the start
        q->next = t;
    } else {
        first = t;
    }
    
    if(!p) { //Inserting at the last value
        last = t;
    }
    
}

bool LinkedList::isSorted(void){
    std::shared_ptr<Node> p = first;
    
    while (p && p->next) { // While p->next  or p is not a null ptr, meaning it reached the last element
        if(p->data > p->next->data)
            return false;
        p = p->next;
    }
    
    return true;
}

int LinkedList::Delete(int pos){
    if(!first)
        throw std::logic_error("Array is empty!");
    
    if(pos < 0 || pos >= Length())
        throw std::out_of_range("Position is out of bounds!");
    
    std::shared_ptr<Node> p = first;
    std::shared_ptr<Node> q = nullptr;
    int x;
    
    if(pos==0){
        x = first->data;
        if(first == last)
            first = last = nullptr;
        else
            first = first->next;
        return x;
    }
    
    for(int i=0; i<pos; i++){
        q = p;
        p = p->next;
    }
    
    x = p->data;
    q->next = p->next;
    
    if(p == last)
        last = q;
    
    return x;
}

int LinkedList::Length(void){
    int count = 0;
    std::shared_ptr<Node> temp = first;
    
    while(temp){
        count++;
        temp = temp->next;
    }
    
    return count;
}

int LinkedList::Sum(void){
    int sum = 0;
    std::shared_ptr<Node> temp = first;
    
    while(temp){
        sum += temp->data;
        temp = temp->next;
    }
    
    return sum;
}

int LinkedList::Max(void){
    if(!first)
        throw std::runtime_error("Linked List is empty can't find max");
    int max = first->data;
    std::shared_ptr<Node> temp = first->next; //We already assigned the value of first
    
    while(temp){
        if(temp->data > max){
            max = temp->data;
        }
        temp=temp->next;
    }
    
    return max;
}

std::shared_ptr<LinkedList::Node> LinkedList::Search(int x){
    std::shared_ptr<Node> q = nullptr;
    std::shared_ptr<Node> p = first;
    
    while(p){
        if(p->data == x){
            if(q){ // Element is not at the start of the list hence why q would be null
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p=p->next;
    }
    
    return nullptr;
}

std::ostream & operator<<(std::ostream &os, const LinkedList &l){
    
    std::shared_ptr<LinkedList::Node> temp = l.first;
    
    os << "[ ";
    
    while(temp){
        os << temp->data;
        temp = temp->next;
        if(temp){
            os << ", ";
        }
    }
    
    os << " ]";
    
    return os;
}
