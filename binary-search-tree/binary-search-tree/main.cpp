//
//  main.cpp
//  binary-search-tree
//
//  Created by Hugo Juarez on 4/9/25.
//

#include "binary-search-tree/binary-search-tree.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    BinarySearchTree bst;
     
    //Insert
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(8);
    bst.insert(30);
 
    // Inorder traversal
    std::cout << "In-Order: " << std::endl;
    bst.inorder();
    std::cout << std::endl;
 
    // Search
    std::cout << "Search for 2: " << (bst.search(2) ? "Found": "NOT Found") << std::endl;
 
    // Insert
    bst.insert(50);
    bst.insert(70);
    bst.insert(1);
    std::cout << "In-Order: " << std::endl;
    bst.inorder();
    std::cout << std::endl;
 
    // Inorder predecessor and inorder successor
    BinarySearchTree bs;
    bs.insert(5);
    bs.insert(2);
    bs.insert(8);
    bs.insert(7);
    bs.insert(9);
    bs.insert(1);
 

    std::cout << "In-Order: " << std::endl;
    bs.inorder();
    std::cout << std::endl;
 
    // Delete
    bs.remove(7);
    
    std::cout << "In-Order: " << std::endl;
    bs.inorder();
    std::cout << std::endl;
    
    return 0;
}
