//
//  sort.cpp
//  sorting
//
//  Created by Hugo Juarez on 4/14/25.
//

#include "sort.hpp"

void Sort::bubbleSort(std::vector<int> &A){
    
    std::size_t n = A.size();
    bool swapped = false;
    
    for(std::size_t i=0;i<n-1;i++){
        swapped = false;
        for(std::size_t j=0; j<n-1-i; j++){
            if(A[j]>A[j+1]){
                std::swap(A[j], A[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void Sort::insertionSort(std::vector<int> &A){
    std::size_t n = A.size();
    
    for(std::size_t i = 1; i<n; i++){
        int key = A[i];
        
        std::size_t j = i;
        
        while(j>0 && A[j-1]>key){
            A[j]=A[j-1];
            j--;
        }
        A[j] = key;
    }
}

void Sort::selectionSort(std::vector<int> &A){
    std::size_t n = A.size();
    
    for(std::size_t i=0; i<n; i++){
        std::size_t min = i;
        for(std::size_t j=i+1; j<n; j++){
            if (A[j]<A[min])
                min = j;
        }
        std::swap(A[min], A[i]);
    }
}

