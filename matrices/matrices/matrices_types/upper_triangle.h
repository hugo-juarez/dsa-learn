//
//  upper_triangle.h
//  matrices
//
//  Created by Hugo Juarez on 3/27/25.
//

#ifndef UPPER_TRIAG_H
#define UPPER_TRIAG_H

#include "matrices.h"

class UpperTriangle : public Matrices {
private:
    int getIndex(int i, int j);
public:
    UpperTriangle(int n);
    void Create(void) override;
    void Set(int i, int j, int x) override;
    int Get(int i, int j) override;
    void Display() override;
};

#endif
