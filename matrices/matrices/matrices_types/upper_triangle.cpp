//
//  upper_triangle.cpp
//  matrices
//
//  Created by Hugo Juarez on 3/27/25.
//

#include "upper_triangle.h"
#include <iostream>
#include <memory>

//Applying row major again

UpperTriangle::UpperTriangle(int n){
    this->n = n;
    A = std::make_unique<int[]>(n*(n+1)/2);
}

int UpperTriangle::getIndex(int i, int j){
    return n*(i-1)-(i-1)*(i-2)/2+j-i;
}

void UpperTriangle::Create(void){
    int i=n;
    int k=0;
    
    std::cout << "Please enter the following elements: " << std::endl;
    while(i>0){
        for(int j=n-i;j<n;j++){
            std::cout << "(" << n-i+1 << "," << j+1 << "): ";
            std::cin >> A[k++];
        }
        i--;
    }
}

void UpperTriangle::Set(int i, int j, int x) {
    if(i<=j){
        std::cout << "Element Set" <<std::endl;
        A[getIndex(i, j)] = x;
    }
}

int UpperTriangle::Get(int i, int j) {
    if(i<=j)
        return A[getIndex(i, j)];
    else
        return 0;
}

void UpperTriangle::Display(){
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n;j++){
            if(i<=j)
                std::cout << A[getIndex(i, j)] << "\t";
            else
                std::cout << 0 << "\t";
        }
        std::cout << std::endl;
    }
}


