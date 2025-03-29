//
//  main.cpp
//  polynomial
//
//  Created by Hugo Juarez on 3/29/25.
//

#include <iostream>
#include "polynomial.h"

int main(int argc, const char * argv[]) {
    int n;
    std::unique_ptr<Poly> p1;
    std::unique_ptr<Poly> p2;
    
    std::cout << "Enter size of first polynomial: ";
    std::cin >> n;
    
    p1 = std::make_unique<Poly>(n);
    std::cin >> *p1;
    
    std::cout << *p1;
    
    std::cout << "Enter size of second polynomial: ";
    std::cin >> n;
    p2 = std::make_unique<Poly>(n);
    
    std::cin >> *p2;
    std::cout << *p2;
    
    std::cout << "Sum of Polynomials: " << std::endl;
    std::cout << *p1 + *p2;
    
    return 0;
}
