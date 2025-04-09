//
//  binary-tree.cpp
//  binary-tree
//
//  Created by Hugo Juarez on 4/8/25.
//

#include "binary-tree.hpp"
#include "../queue/queue.hpp"
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
