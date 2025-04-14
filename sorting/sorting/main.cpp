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
    
    s.bubbleSort(A);
    
    std::cout<<"Bubble Sort:\n";
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
