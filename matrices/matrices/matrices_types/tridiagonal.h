//
//  tridiagonal.h
//  matrices
//
//  Created by Hugo Juarez on 3/28/25.
//

#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H

#include "matrices.h"

class TriDiagonal : public Matrices {
private:
    int getIndex(int i, int j);
public:
    TriDiagonal(int n);
    void Create(void) override;
    void Set(int i, int j, int x) override;
    int Get(int i, int j) override;
    void Display() override;
};

#endif
