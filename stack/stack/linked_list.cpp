//
//  linked_list.cpp
//  stack
//
//  Created by Hugo Juarez on 4/6/25.
//

#include "linked_list.h"

LinkedList::LinkedList(){
    first = nullptr;
}

void LinkedList::push(char x){
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data = x;
    
    if(!first){
        first = t;
        return;
    }
    
    std::shared_ptr<Node> p = first;
    
    while(p->next){
        p=p->next;
    }
    
    p->next = t;
    
}
