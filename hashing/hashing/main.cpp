//
//  main.cpp
//  hashing
//
//  Created by Hugo Juarez on 4/15/25.
//

#include <iostream>
#include "chaining/chaining.hpp"
#include "liner_probing/linear_probing.hpp"
#include "quadratic_probing/quadratic_probing.hpp"

int main(int argc, const char * argv[]) {
    
    int A[] = {1,2,3,4,5,6,11,12,15};
    int size = sizeof(A) / sizeof(int);
    
    Chain c = Chain(A, size);
    std::cout << "Searching 12: " << c.search(12) << std::endl;
    std::cout << "Searching 25: " << c.search(25) << std::endl;
    
    LinearProbing l = LinearProbing(A, size);
    std::cout << "Searching 11: " << l.search(11) << std::endl;
    std::cout << "Searching 25: " << l.search(25) << std::endl;
    
    QuadraticProbing q = QuadraticProbing(A, size);
    std::cout << "Searching 15: " << q.search(15) << std::endl;
    std::cout << "Searching 25: " << q.search(25) << std::endl;
    
    
    return 0;
}
