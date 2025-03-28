//
//  sparse.h
//  sparse-matrix
//
//  Created by Hugo Juarez on 3/28/25.
//
#ifndef SPARSE_H
#define SPARSE_H

#include <memory>

class Element {
public:
    int i;
    int j;
    int x;
};

class Sparse {
private:
    int m;
    int n;
    int num;
    std::unique_ptr<Element[]> e;
    
public:
    Sparse(int m, int n, int num);
    Sparse operator+(const Sparse &s) const;
    friend std::istream & operator>>(std::istream &is, Sparse &s);
    friend std::ostream & operator<<(std::ostream &os, Sparse &s);
};


#endif
