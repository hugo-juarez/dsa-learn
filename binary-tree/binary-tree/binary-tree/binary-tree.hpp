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
    void _preorder(std::shared_ptr<Node> p) const;
    void _inorder(std::shared_ptr<Node> p) const;
    void _postorder(std::shared_ptr<Node> p) const;
    
public:
    BinaryTree();
    void preorder() const;
    void inorder() const;
    void postorder() const;
    
};

#endif /* binary_tree_hpp */
