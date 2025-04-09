//
//  main.cpp
//  binary-tree
//
//  Created by Hugo Juarez on 4/8/25.
//

#include "binary-tree/binary-tree.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree bt;
    
    std::cout << "\nPreorder: ";
    bt.preorder();
    
    std::cout << "\nInorder: ";
    bt.inorder();
    
    std::cout << "\nPostorder: ";
    bt.postorder();
    
    return 0;
}
