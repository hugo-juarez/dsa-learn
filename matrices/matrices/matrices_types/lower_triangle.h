//
//  lower_triangle.h
//  matrices
//
//  Created by Hugo Juarez on 3/27/25.
//

#ifndef LOWER_TRIAG_H
#define LOWER_TRIAG_H

#include "matrices.h"

class LowerTriangle : public Matrices
{
private:
    int getIndex(int i, int j);
    
public:
    LowerTriangle(int n);
    void Create() override;
    void Set(int i, int j, int x) override;
    int Get(int i, int j) override;
    void Display() override;
    
};


#endif
