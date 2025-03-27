//
//  main.cpp
//  matrices
//
//  Created by Hugo Juarez on 3/26/25.
//

#include <iostream>
#include "matrices_types/diagonal.h"
#include "matrices_types/lower_triangle.h"

int main(int argc, const char * argv[]) {
    
    /*
    Diagonal diag = Diagonal(5);
    diag.Create();
    std::cout << "Value in Diag 2,2: "<< diag.Get(2, 2) << std::endl;
    diag.Display();
    */
    
    LowerTriangle ltri = LowerTriangle(5);
    ltri.Create();
    ltri.Set(3, 5, 20);
    ltri.Display();
    std::cout << "Element at (4,5): " << ltri.Get(4, 5) << std::endl;
    
    
    return 0;
    
}

