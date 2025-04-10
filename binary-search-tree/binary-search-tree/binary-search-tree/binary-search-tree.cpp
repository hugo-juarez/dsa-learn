//
//  binary-search-tree.cpp
//  binary-search-tree
//
//  Created by Hugo Juarez on 4/9/25.
//

#include "binary-search-tree.hpp"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(int A[], int sz) : root(nullptr){
    for(int i=0;i<sz;i++){
        insert(A[i]);
    }
}

void BinarySearchTree::insert(int x){
    
    //_insertRec(root, x);
    _insertIter(x);
}

std::shared_ptr<BinarySearchTree::Node> BinarySearchTree::_insertRec(std::shared_ptr<Node> p, int x){
    
    if(!p){
        std::shared_ptr<Node> t = std::make_shared<Node>();
        t->data = x;
        return t;
    }
    
    if(p->data == x)
        return p;
    
    if(p->data > x)
        p->left = _insertRec(p->left, x);
    else
        p->right = _insertRec(p->right, x);
    
    return p;
}

void BinarySearchTree::_insertIter(int x){
    std::shared_ptr<Node> t = std::make_shared<Node>();
    t->data = x;
    
    if(!root){
        root = t;
        return;
    }
    
    std::shared_ptr<Node> p = root;
    std::shared_ptr<Node> q = nullptr;
    
    while(p){
        q=p;
        if(p->data == x)
            return;
        if(p->data > x)
            p = p->left;
        else
            p = p->right;
    }
    
    if(q->data > x)
        q->left = t;
    else
        q->right = t;
    
}

void BinarySearchTree::remove(int x){
    _removeRec(root, x);
}

std::shared_ptr<BinarySearchTree::Node> BinarySearchTree::_removeRec(std::shared_ptr<Node> p, int x){
    if(!p)
        return nullptr;
    
    if(p->data == x && !p->left && !p->right)
        return nullptr;
    
    if(p->data > x)
        p->left = _removeRec(p->left, x);
    else if(p->data < x)
        p->right = _removeRec(p->right, x);
    else{
        if(_height(p->left) > _height(p->right)){
            std::shared_ptr<Node> q = _pre(p);
            p->data = q->data;
            p->left = _removeRec(p->left, q->data);
        } else{
            std::shared_ptr<Node> q = _suc(p);
            p->data = q->data;
            p->right = _removeRec(p->right, q->data);
        }
    }
    
    return p;
}

std::shared_ptr<BinarySearchTree::Node> BinarySearchTree::_pre(std::shared_ptr<Node> p){
    std::shared_ptr<Node> q=p->left;
    while (q->right) {
        q = q->right;
    }
    
    return q;
}

std::shared_ptr<BinarySearchTree::Node> BinarySearchTree::_suc(std::shared_ptr<Node> p){
    std::shared_ptr<Node> q=p->right;
    while (q->left) {
        q = q->left;
    }
    
    return q;
}


bool BinarySearchTree::search(int x){
    return _search(root, x);
}

bool BinarySearchTree::_search(std::shared_ptr<Node> p, int x){
    if(!p)
        return false;
    
    if(p->data == x)
        return true;
    else if(p->data > x)
        return _search(p->left, x);
    else
        return _search(p->right, x);
}

int BinarySearchTree::_height(std::shared_ptr<Node> p){
    if(!p)
        return 0;
    
    int x = _height(p->left);
    int y = _height(p->right);
    
    if(x>y)
        return x + 1;
    else
        return y+1;
}
