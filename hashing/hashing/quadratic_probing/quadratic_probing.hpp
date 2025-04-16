//
//  quadratic_probing.hpp
//  hashing
//
//  Created by Hugo Juarez on 4/16/25.
//

#ifndef quadratic_probing_hpp
#define quadratic_probing_hpp

#include <stdio.h>
#include <memory>

class QuadraticProbing{
private:
    std::unique_ptr<int[]> table;
    size_t size;
    size_t h(int x, int i); //Hashing function
public:
    QuadraticProbing(int A[], size_t sz);
    void insert(int x);
    int search(int x);
};

#endif /* quadratic_probing_hpp */
