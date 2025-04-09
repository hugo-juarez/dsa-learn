//
//  binary-tree.hpp
//  binary-tree
//
//  Created by Hugo Juarez on 4/8/25.
//

#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <stdio.h>
#include <memory>

class BinaryTree{
private:
    struct Node{
        std::shared_ptr<Node> left;
        int data;
        std::shared_ptr<Node> right;
    };
    std::shared_ptr<Node> root;
public:
    BinaryTree();
};

#endif /* binary_tree_hpp */
