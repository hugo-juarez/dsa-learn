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

void LinkedList::ReverseArray(void){
    
    if(!first) //If list is empty
        return;
    
    std::unique_ptr<int[]> A = std::make_unique<int[]>(Length());
    std::shared_ptr<Node> p = first;
    int i=0;
    
    while (p) {
        A[i++] = p->data;
        p = p->next;
    }
    
    p = first;
    i--;
    
    while (p) {
        p->data = A[i--];
        p = p->next;
    }
    
}

void LinkedList::ReverseSlidingPtr(void){
    if(!first)
        return;
    
    std::shared_ptr<Node> p = first;
    std::shared_ptr<Node> q = nullptr;
    std::shared_ptr<Node> r = nullptr;
    
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    
    last = first;
    first = q;
}

void LinkedList::ReverseRecursively(void){
    if(!first)
        return;
    ReverseRecurs(nullptr, first);
}

void LinkedList::ReverseRecurs(std::shared_ptr<Node> q, std::shared_ptr<Node> p){
    if(!p){
        last = first;
        first = q;
        return;
    }
    ReverseRecurs(p, p->next);
    p->next = q;
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

void LinkedList::Merge(LinkedList &l2){
    if(!isSorted() || !l2.isSorted())
        throw std::logic_error("One or both arrays are not sorted");
    
    if(!first){
        first = l2.first;
        return;
    }
    
    if(!l2.first){
        return;
    }
    
    std::shared_ptr<Node> second = l2.first;
    std::shared_ptr<Node> third;
    std::shared_ptr<Node> Last;
    
    if(first->data < second->data){
        third = Last = first;
        first = first->next;
    }
    else{
        third = Last = second;
        second = second->next;
    }
    
    while(first && second){
        if(first->data < second->data){
            Last->next = first;
            Last = first;
            first = first->next;
        } else {
            Last->next = second;
            Last = second;
            second = second->next;
        }
    }
    
    if(first){
        Last->next=first;
        Last = last;
    }
    
    if(second){
        Last->next=second;
        Last = l2.last;
    }
    
    first = third;
    last = Last;
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

bool LinkedList::isLoop(void){
    if(!first || !first->next) //List is empty
        return false;
    
    std::shared_ptr<Node> p = first;
    std::shared_ptr<Node> q = first->next;
    
    while(q && q->next){
        if(p==q)
            return true;
        
        p = p->next;
        q = q->next->next;
            
    }
    return false;
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

LinkedList LinkedList::createLoop(void){
    int A[] = {1,2,3,4,5};
    LinkedList loopList = LinkedList(A, 5);
    
    loopList.last->next = loopList.first->next; //So it loops back to 2
    
    return loopList;
}

LinkedList LinkedList::operator+(const LinkedList &l2) const{
    LinkedList concat;
    
    std::shared_ptr<Node> p = first;
    
    while(p){
        concat.Append(p->data);
        p = p->next;
    }
    
    p = l2.first;
    
    while(p){
        concat.Append(p->data);
        p = p->next;
    }
    
    return concat;
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
