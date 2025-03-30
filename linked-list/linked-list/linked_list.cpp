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
