//
//  binary-tree.cpp
//  binary-tree
//
//  Created by Hugo Juarez on 4/8/25.
//

#include "binary-tree.hpp"
#include "../queue/queue.hpp"
#include "../stack/stack.hpp"
#include <memory>
#include <iostream>

BinaryTree::BinaryTree(){
    int root;
    std::cout << "Please enter root element: ";
    std::cin >> root;
    
    if(!root){
        this->root = nullptr;
        return;
    }
    
    Queue<std::shared_ptr<Node>> q;
    std::shared_ptr<Node> t = std::make_shared<Node>();
    
    t->data = root;
    this->root = t;
    
    q.enqueue(t);
    
    while(!q.isEmpty()){
        int x;
        std::shared_ptr<Node> p = q.dequeue();
        std::cout<<"Enter left element for node " << p->data << ": ";
        std::cin >> x;
        
        if(x!=-1){
            auto t = std::make_shared<Node>();
            t->data = x;
            p->left = t;
            q.enqueue(t);
        }
        
        std::cout<<"Enter right element for node " << p->data << ": ";
        std::cin >> x;
        
        if(x!=-1){
            auto t = std::make_shared<Node>();
            t->data = x;
            p->right = t;
            q.enqueue(t);
        }
    }
    
}

void BinaryTree::preorder() const{
    if(!root)
        return;
    
    //_preorder(root);
    _preorderIter();
}

void BinaryTree::_preorder(std::shared_ptr<Node> p) const{
    if(!p)
        return;
    
    std::cout << p->data << ", ";
    _preorder(p->left);
    _preorder(p->right);
}

void BinaryTree::_preorderIter() const {
    std::shared_ptr<Node> p =root;
    Stack<std::shared_ptr<Node>> s;
    
    while(p || !s.isEmpty()){
        if(p){
            std::cout << p->data << ", ";
            s.push(p);
            p = p->left;
        } else {
            p = s.pop()->right;
        }
    }
}


void BinaryTree::inorder() const{
    if(!root)
        return;
    
    _inorder(root);
}

void BinaryTree::_inorder(std::shared_ptr<Node> p) const{
    if(!p)
        return;
    
    _inorder(p->left);
    std::cout << p->data << ", ";
    _inorder(p->right);
}

void BinaryTree::_inorderIter() const {
    std::shared_ptr<Node> p =root;
    Stack<std::shared_ptr<Node>> s;
    
    while(p || !s.isEmpty()){
        if(p){
            s.push(p);
            p=p->left;
        } else{
            p = s.pop();
            std::cout << p->data << ", ";
            p = p->right;
        }
    }
}



void BinaryTree::postorder() const{
    if(!root)
        return;
    
    _postorder(root);
}

void BinaryTree::_postorder(std::shared_ptr<Node> p) const{
    if(!p)
        return;
    
    _postorder(p->left);
    _postorder(p->right);
    std::cout << p->data << ", ";
}

void BinaryTree::_postorderIter() const {
    
    Stack<std::shared_ptr<Node>> s1, s2;
    s1.push(root);
    
    while(!s1.isEmpty()){
        std::shared_ptr<Node> t = s1.pop();
        s2.push(t);
        
        if(t->left) s1.push(t->left);
        if(t->right) s1.push(t->right);
    }
    
    while(!s2.isEmpty())
        std::cout << s2.pop()->data << ", ";
}

void BinaryTree::levelorder() const {
    if(!root)
        return;
    
    Queue<std::shared_ptr<Node>> q;
    std::shared_ptr<Node> p;
    q.enqueue(root);
    
    while (!q.isEmpty()) {
        p = q.dequeue();
        std::cout << p->data << ", ";
        
        if(p->left) q.enqueue(p->left);
        if(p->right) q.enqueue(p->right);
    }
}

int BinaryTree::count() const{
    return _count(root);
}

int BinaryTree::_count(std::shared_ptr<const Node> p) const{
    if(!p)
        return 0;
    
    int x = _count(p->left);
    int y = _count(p->right);
    
    return x+y+1;
    
}

int BinaryTree::sum() const{
    return _sum(root);
}

int BinaryTree::_sum(std::shared_ptr<const Node> p) const{
    if(!p)
        return 0;
    
    int x = _sum(p->left);
    int y = _sum(p->right);
    
    return x+y+p->data;
    
}

int BinaryTree::height() const{
    return _height(root);
}

int BinaryTree::_height(std::shared_ptr<const Node> p) const{
    if(!p)
        return 0;
    
    int x = _height(p->left);
    int y = _height(p->right);
    
    if(x>y)
        return x+1;
    else
        return y+1;
    
}


int BinaryTree::leafNodes() const{
    return _leafNodes(root);
}

int BinaryTree::_leafNodes(std::shared_ptr<const Node> p) const{
    if(!p)
        return 0;
    
    int x = _leafNodes(p->left);
    int y = _leafNodes(p->right);
    
    if(!p->left && !p->right)
        return x+y+1;
    else
        return x+y;
    
}
