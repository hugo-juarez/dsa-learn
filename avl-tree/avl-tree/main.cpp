//
//  main.cpp
//  avl-tree
//
//  Created by Hugo Juarez on 4/10/25.
//

#include "avl/avl.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    //LR Rotation
    AVL tlr;
    tlr.insert(50);
    tlr.insert(10);
    tlr.insert(20);
    std::cout << "Inorder:\n";
    tlr.inorder();
    std::cout << std::endl;
    
    //RL Rotation
    AVL tlr2;
    tlr2.insert(20);
    tlr2.insert(50);
    tlr2.insert(30);
    std::cout << "Inorder:\n";
    tlr2.inorder();
    std::cout << std::endl;
    
    //Bigger data
    int A[] = {10,20,30,25,28,27,5};
    AVL tlr3 = AVL(A, 7);
    std::cout << "Inorder:\n";
    tlr3.inorder();
    std::cout << std::endl;
    tlr3.remove(5);
    std::cout << "Inorder:\n";
    tlr3.inorder();
    std::cout << std::endl;
    
    return 0;
}
