//
//  diagonal.cpp
//  matrices
//
//  Created by Hugo Juarez on 3/26/25.
//
#include "diagonal.h"
#include <iostream>
#include <memory>

Diagonal::Diagonal(int n) {
    this->n = n;
    A = std::make_unique<int[]>(n);
}

void Diagonal::Create(void){
    std::cout << "Enter elements of the diagonal: " << std::endl;
    for(int i=0; i<n; i++)
        std::cin >> A[i];
}

void Diagonal::Set(int i, int j, int x){
    if(i==j)
        A[i-1] = x;
}

int Diagonal::Get(int i, int j){
    if(i!=j)
        return 0;
        
    return A[i-1];
}

void Diagonal::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                std::cout << A[i] << "\t";
            else
                std::cout << 0 << "\t";
        }
        std::cout << std::endl;
    }
    
}

