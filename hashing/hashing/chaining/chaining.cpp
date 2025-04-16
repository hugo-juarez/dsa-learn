//
//  chaining.cpp
//  hashing
//
//  Created by Hugo Juarez on 4/16/25.
//

#include "chaining.hpp"
#include "../node/node.hpp"

Chain::Chain(int A[], size_t sz){
    //Using hash function h(x) = x%10;
    table = std::make_unique<std::shared_ptr<Node>[]>(10);
    
    for(size_t j=0; j<sz; j++){
        insert(A[j]);
    }
    
}

size_t Chain::h(int x){
    return x%10;
}

void Chain::insert(int x){
    size_t index = h(x);
    
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data  = x;
    
    if(!table[index] || table[index]->data > x){
        t->next = table[index];
        table[index] = t;
        return;
    }
    
    std::shared_ptr<Node> p = table[index];
    
    while(p->next && p->next->data < t->data){
        p = p->next;
    }
    
    if(p->next && p->next->data == x)
        return;
    
    t->next = p->next;
    p->next = t;
    
}

int Chain::search(int x){
    size_t id = h(x);
    
    if(!table[id])
        return -1;
    
    std::shared_ptr<Node> p = table[id];
    
    while(p && p->data < x)
        p = p->next;
    
    if(p && p->data == x)
        return p->data;
    else
        return -1;
    
}
