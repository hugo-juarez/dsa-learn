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

void Sort::quickSort(std::vector<int> &A){
    std::size_t n = A.size();
    
    _quickSort(A, 0, n);
    
}

void Sort::_quickSort(std::vector<int> &A, std::size_t l, std::size_t h){
    
    if(h-l<=1)
        return;
    
    _medianOfThree(A, l, h-1); //Put median element as first for pivot
    
    int pivot = A[l];
    
    std::size_t i = l;
    std::size_t j = h; //Highest value i not inclusive
    
    while(i < j){
        do{i++;}while(A[i] < pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j)
            std::swap(A[j],A[i]);
    }
    
    std::size_t mid = j;
    
    std::swap(A[l], A[j]);
    
    _quickSort(A, l, mid);
    _quickSort(A, mid+1, h);
    
}

void Sort::_medianOfThree(std::vector<int> &A, std::size_t l, std::size_t h){
    std::size_t mid = (l+h)/2;
    
    if(A[h] < A[l]) std::swap(A[l], A[h]);
    if(A[mid] < A[l]) std::swap(A[l], A[mid]);
    if(A[mid] > A[h]) std::swap(A[mid], A[h]);
    
    std::swap(A[mid], A[l]);
    
}

void Sort::mergeSort(std::vector<int> &A){
    std::size_t n = A.size();
    
    _mergeSort(A, 0, n);
}

void Sort::_mergeSort(std::vector<int> &A, size_t l, size_t h){
    
    if(h-l <=1)
        return;
    
    size_t mid = l + (h-l)/2;
    
    _mergeSort(A, l, mid);
    _mergeSort(A, mid, h);
    
    _merge(A, l, h, mid);
    
}

void Sort::_merge(std::vector<int> &A, std::size_t l, std::size_t h, std::size_t mid){
    
    if(h-l <=0)
        return;
    
    std::vector<int> B;
    size_t i = l;
    size_t j = mid;
    
    while(i < mid && j < h){
        if(A[i]<A[j])
            B.push_back(A[i++]);
        else
            B.push_back(A[j++]);
    }
    
    while(i<mid) B.push_back(A[i++]);
    while(j<h) B.push_back(A[j++]);
    
    for(size_t k=0; k<B.size();k++)
        A[l+k] = B[k];
    
}

void Sort::countSort(std::vector<int> &A){
    int max = A[0];
    size_t n = A.size();
    
    //linear search for max
    for(size_t i=1; i<n; i++){
        if(A[i]>max)
            max = A[i];
    }
    
    //Create count array
    std::vector<int> count(max+1);
    
    for(size_t j=0; j<n; j++)
        count[A[j]] +=1;
    
    size_t i=0;
    
    for(int k=0; k<=max; k++){
        while(count[k]>0){
            A[i++] = k;
            count[k] -= 1;
        }
    }
}
