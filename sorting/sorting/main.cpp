//
//  main.cpp
//  sorting
//
//  Created by Hugo Juarez on 4/14/25.
//

#include "sort/sort.hpp"
#include <iostream>
#include <vector>

void display(const std::vector<int> &A);

int main(int argc, const char * argv[]) {
    std::vector<int> A = {5,2,3,4,1};
    Sort s;
    
    std::cout<<"Array:\n";
    display(A);
    std::cout<<std::endl;
    
#if false
    s.bubbleSort(A);
    
    std::cout<<"Bubble Sort:\n";
    display(A);
    std::cout<<std::endl;

    
    s.insertionSort(A);
    
    std::cout<<"Insetion Sort:\n";
    display(A);
    std::cout<<std::endl;

    
    s.selectionSort(A);
    
    std::cout<<"Selection Sort:\n";
    display(A);
    std::cout<<std::endl;
    
    s.quickSort(A);
    
    std::cout<<"Quick Sort:\n";
    display(A);
    std::cout<<std::endl;
    
    
    s.mergeSort(A);
    
    std::cout<<"Merge Sort:\n";
    display(A);
    std::cout<<std::endl;
#endif
    
    s.countSort(A);
    
    std::cout<<"Count Sort:\n";
    display(A);
    std::cout<<std::endl;
    
    return 0;
    

}


void display(const std::vector<int> &A){
    std::cout<<"[";
    for(int i=0;i<A.size();i++){
        std::cout<<A[i];
        if(i!=A.size()-1)
            std::cout << ",";
    }
    std::cout<<"]";
}
