//
//  main.cpp
//  matrices
//
//  Created by Hugo Juarez on 3/26/25.
//

#include <iostream>
#include "matrices_types/diagonal.h"
#include "matrices_types/lower_triangle.h"
#include "matrices_types/upper_triangle.h"
#include "matrices_types/tridiagonal.h"

int main(int argc, const char * argv[]) {
    
    /*
    Diagonal diag = Diagonal(5);
    diag.Create();
    std::cout << "Value in Diag 2,2: "<< diag.Get(2, 2) << std::endl;
    diag.Display();
    */
    
    TriDiagonal utri = TriDiagonal(5);
    utri.Create();
    utri.Set(3, 1, 20);
    utri.Display();
    std::cout << "Element at (4,5): " << utri.Get(4, 2) << std::endl;
    
    
    return 0;
    
}

