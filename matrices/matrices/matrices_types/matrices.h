//
//  matrices.h
//  matrices
//
//  Created by Hugo Juarez on 3/27/25.
//
#ifndef MATRICES_H
#define MATRICES_H

#include <memory>

class Matrices
{
protected:
    int n;
    std::unique_ptr<int[]> A;
public:
    virtual void Create(void) = 0;
    virtual void Set(int i, int j, int x) = 0;
    virtual int Get(int i, int j) = 0;
    virtual void Display(void) = 0;
    virtual ~Matrices() {};
};

#endif
