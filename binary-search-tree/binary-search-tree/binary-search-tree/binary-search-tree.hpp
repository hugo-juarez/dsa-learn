//
//  binary-search-tree.hpp
//  binary-search-tree
//
//  Created by Hugo Juarez on 4/9/25.
//

#ifndef binary_search_tree_hpp
#define binary_search_tree_hpp

#include <stdio.h>
#include <memory>

class BinarySearchTree{
private:
    struct Node{
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        int data;
    };
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> _pre(std::shared_ptr<Node> p);
    std::shared_ptr<Node> _suc(std::shared_ptr<Node> p);
    std::shared_ptr<Node> _insertRec(std::shared_ptr<Node> p,int x);
    std::shared_ptr<Node> _removeRec(std::shared_ptr<Node> p,int x);
    void _inorder(std::shared_ptr<Node> p);
    void _insertIter(int x);
    bool _search(std::shared_ptr<Node> p,int x);
    int _height(std::shared_ptr<Node> p);
    
public:
    BinarySearchTree();
    BinarySearchTree(int A[], int sz);
    void insert(int x);
    void inorder();
    void remove(int x);
    bool search(int x);
};

#endif /* binary_search_tree_hpp */
