//
//  linked_list.cpp
//  linked-list
//
//  Created by Hugo Juarez on 3/29/25.
//

#include "linked_list.h"
#include <memory>

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
