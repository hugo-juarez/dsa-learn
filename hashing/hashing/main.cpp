//
//  main.cpp
//  hashing
//
//  Created by Hugo Juarez on 4/15/25.
//

#include <iostream>
#include "chaining/chaining.hpp"

int main(int argc, const char * argv[]) {
    
    int A[] = {1,2,3,4,5,6,11,12,15};
    int size = sizeof(A) / sizeof(int);
    
    Chain c = Chain(A, size);
    std::cout << "Searching 7: " << c.search(25) << std::endl;
    
    return 0;
}
