//
//  lower_triangle.cpp
//  matrices
//
//  Created by Hugo Juarez on 3/27/25.
//
#include "lower_triangle.h"
#include <iostream>
#include <memory>

//We saved the values in Row Format

LowerTriangle::LowerTriangle(int n){
    this->n = n;
    A = std::make_unique<int[]>(n*(n+1)/2);
}

int LowerTriangle::getIndex(int i, int j){
    return i*(i-1)/2 +j-1;
}

void LowerTriangle::Create(void){
    int i=1;
    int k=0;
    
    std::cout << "Please enter the following elements: " << std::endl;
    while(i<n+1){
        for(int j=0; j<i; j++){
            std::cout << "(" << i << "," << j+1 << "): ";
            std::cin >> A[k++];
        }
        i++;
    }
}
void LowerTriangle::Set(int i, int j, int x){
    if(i>=j)
        A[getIndex(i, j)] = x;
}
int LowerTriangle::Get(int i, int j){
    if(i>=j)
        return A[getIndex(i, j)];
    else
        return 0;
}
void LowerTriangle::Display(){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i>=j)
                std::cout << A[getIndex(i, j)] << "\t";
            else
                std::cout << 0 << "\t";
        }
        std::cout << std::endl;
    }
            
}
