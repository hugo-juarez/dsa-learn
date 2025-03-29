//
//  polynomial.h
//  polynomial
//
//  Created by Hugo Juarez on 3/29/25.
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <memory>

class Term {
public:
    int coef;
    int exp;
};

class Poly {
private:
    int n;
    std::unique_ptr<Term[]> t;
    
public:
    Poly(int n);
    int Evaluate(int x);
    Poly operator+(const Poly &p2) const;
    friend std::istream & operator>>(std::istream &is, Poly &p);
    friend std::ostream & operator<<(std::ostream &os, const Poly &p);
};

#endif
