//
//  avl.hpp
//  avl-tree
//
//  Created by Hugo Juarez on 4/10/25.
//

#ifndef avl_hpp
#define avl_hpp

#include <stdio.h>
#include <memory>

class AVL {
private:
    struct Node{
        std::shared_ptr<Node> left;
        int data;
        std::shared_ptr<Node> right;
    };
    std::shared_ptr<Node> root;
    
    int _height(std::shared_ptr<Node> p);
    void _inorder(std::shared_ptr<Node> p);
    std::shared_ptr<Node> _insert(std::shared_ptr<Node> p, int x);
    std::shared_ptr<Node> _rotate(std::shared_ptr<Node> p, int x, int bf);
    std::shared_ptr<Node> _LLRotation(std::shared_ptr<Node> p);
    std::shared_ptr<Node> _LRRotation(std::shared_ptr<Node> p);
    std::shared_ptr<Node> _RRRotation(std::shared_ptr<Node> p);
    std::shared_ptr<Node> _RLRotation(std::shared_ptr<Node> p);
    
public:
    AVL();
    void insert(int x);
    void inorder();
};

#endif /* avl_hpp */
