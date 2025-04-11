//
//  avl.cpp
//  avl-tree
//
//  Created by Hugo Juarez on 4/10/25.
//

#include "avl.hpp"
#include <algorithm>
#include <iostream>

AVL::AVL() : root(nullptr) {}

int AVL::_height(std::shared_ptr<Node> p){
    if(!p)
        return 0;
    
    int x = _height(p->left);
    int y = _height(p->right);
    
    return std::max(x,y)+1;
    
}

void AVL::inorder(){
    std::cout << "[";
    _inorder(root);
    std::cout << "]";
}

void AVL::_inorder(std::shared_ptr<Node> p){
    if(!p)
        return;
    
    _inorder(p->left);
    std::cout << p->data << ", ";
    _inorder(p->right);
}

void AVL::insert(int x){
    root = _insert(root, x);
}

std::shared_ptr<AVL::Node> AVL::_insert(std::shared_ptr<Node> p, int x){
    if(!p){
        std::shared_ptr<Node> t = std::make_shared<Node>();
        t->data = x;
        return t;
    }
    
    if(p->data > x) {
        p->left = _insert(p->left, x);
    } else if(p->data < x){
        p->right = _insert(p->right, x);
    }
    
    int hL = _height(p->left);
    int hR = _height(p->right);
    int bf = hL - hR;
    
    if( std::abs(bf) > 1 ){
        p = _rotate(p, x, bf);
    }
    
    return p;
    
}

std::shared_ptr<AVL::Node> AVL::_rotate(std::shared_ptr<Node> p, int x, int bf){
    
    if(bf > 1){
        if(x < p->left->data)
            p = _LLRotation(p);
        else
            p = _LRRotation(p);
    }else{
        if(x > p->right->data)
            p = _RRRotation(p);
        else
            p = _RLRotation(p);
    }
    
    return p;
}

std::shared_ptr<AVL::Node> AVL::_LLRotation(std::shared_ptr<Node> p){
    std::shared_ptr<Node> pL = p->left;
    
    p->left = pL->right;
    pL->right = p;
    
    return pL;
}

std::shared_ptr<AVL::Node> AVL::_LRRotation(std::shared_ptr<Node> p){
    std::shared_ptr<Node> pLR = p->left->right;
    std::shared_ptr<Node> pL = p->left;
    
    pL->right = pLR->left;
    p->left = pLR->right;
    pLR->left = pL;
    pLR->right = p;
    
    return pLR;
}

std::shared_ptr<AVL::Node> AVL::_RRRotation(std::shared_ptr<Node> p) {
    std::shared_ptr<Node> pR = p->right;
    
    p->right = pR->left;
    pR->left = p;
    
    return pR;
}

std::shared_ptr<AVL::Node> AVL::_RLRotation(std::shared_ptr<Node> p){
    std::shared_ptr<Node> pRL = p->right->left;
    std::shared_ptr<Node> pR = p->right;
    
    pR->left = pRL->right;
    p->right = pRL->left;
    pRL->right = pR;
    pRL->left = p;
    
    return pRL;
}
