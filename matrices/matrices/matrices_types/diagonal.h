//
//  diagonal.h
//  matrices
//
//  Created by Hugo Juarez on 3/26/25.
//
#ifndef DIAGONAL_H
#define DIAGONAL_H

#include "matrices.h"

class Diagonal : public Matrices
{
public:
    
    Diagonal(int n);
    void Create(void) override;
    void Set(int i, int j, int x) override;
    int Get(int i, int j) override;
    void Display() override;
    
    
};

#endif
