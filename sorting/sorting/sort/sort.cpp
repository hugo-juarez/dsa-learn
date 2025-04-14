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
