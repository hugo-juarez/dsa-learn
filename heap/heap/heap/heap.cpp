//
//  heap.cpp
//  heap
//
//  Created by Hugo Juarez on 4/12/25.
//

#include "heap.hpp"
#include <vector>
#include <memory>
#include <iostream>

Heap::Heap(std::vector<int> &v) : end(-1), A(v){
    for(int x: v){
        insert(x);
    }
}

void Heap::insert(int x){
    if(isFull())
        return;
    
    end +=1;
    int i = end;
    
    while(i-1>=0 && A[(i-1)/2] < x){
        A[i] = A[(i-1)/2];
        i=(i-1)/2;
    }
    A[i] = x;
}

bool Heap::isFull(){
    return A.size() == end+1;
}

std::ostream & operator<<(std::ostream &os, const Heap &h){
    os << "[";
    for(int i=0; i<= h.end; i++){
        os << h.A[i];
        if(i != h.end)
            os << ",";
    }
    
    os << "]";
    return os;
}
