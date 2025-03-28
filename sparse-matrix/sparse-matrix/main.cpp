//
//  main.cpp
//  sparse-matrix
//
//  Created by Hugo Juarez on 3/28/25.
//

#include <iostream>
#include "sparse.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Sparse s = Sparse(3, 4, 2);
    std::cin >> s;
    std::cout << s;
    
    return 0;
}

