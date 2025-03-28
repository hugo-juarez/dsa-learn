//
//  sparse.cpp
//  sparse-matrix
//
//  Created by Hugo Juarez on 3/28/25.
//

#include "sparse.h"
#include <iostream>
#include <memory>

Sparse::Sparse(int m, int n, int num){
    this->m = m;
    this->n = n;
    this->num = num;
    e = std::make_unique<Element[]>(num);
}

Sparse Sparse::operator+(const Sparse &s) const{
    if(m != s.m || n!= s.n)
    {
        throw std::invalid_argument("Cannot add, matrices are different sizes.");
    }
    
    Sparse result = Sparse(m,n,num+s.num);
    int i,j,k;
    i=j=k=0;
    
    while (i<num && j<s.num) {
        if(e[i].i < s.e[j].i)
            result.e[k++] = e[i++];
        else if(e[i].i > s.e[j].i)
            result.e[k++] = s.e[j++];
        else{
            if(e[i].j<s.e[j].j)
                result.e[k++] = e[i++];
            else if(e[i].j>s.e[j].j)
                result.e[k++] = s.e[j++];
            else if(e[i].j==s.e[j].j){
                result.e[k] = e[i];
                result.e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
            
    }
    
    for(;i<num;i++) result.e[k++]=e[i];
    for(;j<s.num;j++) result.e[k++]=s.e[j];
    
    result.num = k;
    
    return result;
}

std::istream & operator>>(std::istream &is, Sparse &s){
    std::cout << "Enter non-zero elements in order of row/col appearence: " <<std::endl;
    for (int i=0; i<s.num; i++) {
        std::cout << "Enter element " << i <<" (row col num): ";
        std::cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, Sparse &s){
    int k=0;
    
    for(int i=0; i<s.m; i++){
        for(int j=0; j<s.n; j++){
            if(i==s.e[k].i && j==s.e[k].j)
                std::cout << s.e[k++].x << "\t";
            else
                std::cout << 0 << "\t";
        }
        std::cout << std::endl;
    }
    
    return os;
}


