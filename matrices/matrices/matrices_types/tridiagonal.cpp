//
//  tridiagonal.cpp
//  matrices
//
//  Created by Hugo Juarez on 3/28/25.
//

#include "tridiagonal.h"
#include <memory>
#include <iostream>

TriDiagonal::TriDiagonal(int n){
    this->n = n;
    A = std::make_unique<int[]>(3*n-2);
}

int TriDiagonal::getIndex(int i, int j){
    switch (i-j) {
        case 1:
            return j-1;
        case 0:
            return n-1+j-1;
        case -1:
            return 2*n-1+i-1;
        default:
            return 0;
    }
}

void TriDiagonal::Create(){
    int k=0;
    std::cout << "Enter lower diagonal: " << std::endl;
    for (int i=0; i<n-1; i++) {
        std::cin >> A[k++];
    }
    std::cout << "Enter main diagonal: " << std::endl;
    for (int i=0; i<n; i++) {
        std::cin >> A[k++];
    }
    std::cout << "Enter upper diagonal: " << std::endl;
    for (int i=0; i<n-1; i++) {
        std::cin >> A[k++];
    }
}

void TriDiagonal::Set(int i, int j, int x){
    if(i-j<= 1 && i-j>=-1)
        A[getIndex(i, j)] = x;
}

int TriDiagonal::Get(int i, int j){
    if(i-j<= 1 && i-j>=-1)
        return A[getIndex(i, j)];
    else
        return 0;
}

void TriDiagonal::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-j<= 1 && i-j>=-1)
                std::cout << A[getIndex(i, j)] << "\t";
            else
                std::cout << 0 << "\t";
        }
        std::cout << std::endl;
    }
}

