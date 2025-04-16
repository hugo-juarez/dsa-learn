//
//  quadratic_probing.cpp
//  hashing
//
//  Created by Hugo Juarez on 4/16/25.
//

#include "quadratic_probing.hpp"
#include <memory>

QuadraticProbing::QuadraticProbing(int A[], size_t sz){
    table = std::make_unique<int []>(sz*2);
    size = sz*2;
    
    for(int i=0; i< size; i++)
        table[i] = -1;
    
    for(int j=0; j<sz; j++)
        insert(A[j]);
}

size_t QuadraticProbing::h(int x, int i){
    return (x+i*i)%size;
}

void QuadraticProbing::insert(int x){
    size_t id = h(x,0);
    int i=0;
    
    while (table[id] != -1) {
        i++;
        id = h(x,i);
    }
    
    table[id] = x;
}

int QuadraticProbing::search(int x){
    int i=0;
    size_t id = h(x,i);
    
    while (table[id]!= -1) {
        if(table[id] == x)
            return table[id];
        
        i++;
        id = h(x,i);
    }
    
    return -1;
}
