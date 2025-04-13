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

int Heap::remove(){
    if(isEmpty())
        throw std::runtime_error("Underflow of heap");
    
    int x = A[0];
    int i = 0;
    int j = 2*i+1; //Left Child
    std::swap(A[0], A[end--]);
    
    
    while(j <= end){
        if(j+1 <= end && A[j]<A[j+1])
            j += 1;
        
        if(A[i] < A[j]){
            std::swap(A[i], A[j]);
            i = j;
            j = 2*i+1;
        } else{
            break;
        }
    }
    
    return x;
    
}

void Heap::sort(){
    int n=end;
    for(int i=0; i<=n; i++){
        remove();
    }
}

bool Heap::isFull(){
    return A.size() == end+1;
}

bool Heap::isEmpty(){
    return end == -1;
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

