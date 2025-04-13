//
//  main.cpp
//  heap
//
//  Created by Hugo Juarez on 4/12/25.
//

#include "heap/heap.hpp"
#include <vector>
#include <iostream>

int main(int argc, const char * argv[]) {
    std::vector<int> vec = {1,5,6,7,8,20};
    
    std::cout << "Vector: " << std::endl;
    std::cout << "[";
    for(int x: vec){
        std::cout << x << ",";
    }
    std::cout << "]" << std::endl;
    
    Heap h = Heap(vec);
    std::cout << "Heap: " << std::endl;
    std::cout << h << std::endl;
    
    std::cout << "Vector: " << std::endl;
    std::cout << "[";
    for(int x: vec){
        std::cout << x << ",";
    }
    std::cout << "]" << std::endl;
    
    h.sort();
    
    std::cout << "Vector Sorted: " << std::endl;
    std::cout << "[";
    for(int x: vec){
        std::cout << x << ",";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}
