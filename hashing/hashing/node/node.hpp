//
//  node.hpp
//  hashing
//
//  Created by Hugo Juarez on 4/16/25.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>
#include <memory>

class Node{
public:
    int data;
    std::shared_ptr<Node> next;
};

#endif /* node_hpp */
