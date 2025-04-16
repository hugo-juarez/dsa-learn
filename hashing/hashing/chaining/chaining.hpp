//
//  chaining.hpp
//  hashing
//
//  Created by Hugo Juarez on 4/16/25.
//

#ifndef chaining_hpp
#define chaining_hpp

#include "../node/node.hpp"
#include <stdio.h>

class Chain{
private:
    std::shared_ptr<std::shared_ptr<Node>[]> table;
    size_t h(int x); //Hash Function
public:
    Chain(int A[], size_t sz);
    void insert(int x);
    int search(int x);
};

#endif /* chaining_hpp */
