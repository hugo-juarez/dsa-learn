//
//  heap.hpp
//  heap
//
//  Created by Hugo Juarez on 4/12/25.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
#include <memory>
#include <vector>

class Heap {
private:
    std::vector<int>& A;
    int end;
public:
    Heap(std::vector<int> &v);
    void insert(int x);
    int remove();
    bool isFull();
    bool isEmpty();
    friend std::ostream & operator<<(std::ostream &os, const Heap &h);
};

#endif /* heap_hpp */
