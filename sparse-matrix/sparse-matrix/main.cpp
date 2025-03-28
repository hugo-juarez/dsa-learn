//
//  main.cpp
//  sparse-matrix
//
//  Created by Hugo Juarez on 3/28/25.
//

#include <iostream>
#include "sparse.h"

int main(int argc, const char * argv[]) {
    
    Sparse s1 = Sparse(5, 5, 5);
    Sparse s2 = Sparse(5, 5, 5);
    
    std::cin >> s1;
    std::cin >> s2;
    
    Sparse sum = s1 + s2;
    
    std::cout << "First Matrix "<<std::endl<<s1;
    std::cout << "Second Matrix "<<std::endl<<s2;
    std::cout << "Sum Matrix "<<std::endl<<sum;
    
    return 0;
}

