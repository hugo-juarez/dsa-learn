//
//  polynomial.cpp
//  polynomial
//
//  Created by Hugo Juarez on 3/29/25.
//

#include "polynomial.h"
#include <memory>
#include <iostream>
#include <cmath>

Poly::Poly(int n){
    this->n = n;
    t = std::make_unique<Term[]>(n);
}

int Poly::Evaluate(int x){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += t[i].coef * pow(x, t[i].exp);
    
    return sum;
}

Poly Poly::operator+(const Poly &p2)const{
    int i,j,k;
    i=j=k=0;
    Poly sumP = Poly(n+p2.n);
    
    while (i<n && j<p2.n) {
        if(t[i].exp > p2.t[j].exp)
            sumP.t[k++] = t[i++];
        else if(t[i].exp < p2.t[j].exp)
            sumP.t[k++] = p2.t[j++];
        else{
            sumP.t[k] = t[i++];
            sumP.t[k++].coef += p2.t[j++].coef;
        }
    }
    
    for(;i<n;i++) sumP.t[k++] = t[i];
    for(;j<p2.n;j++) sumP.t[k++] = t[j];
    
    sumP.n = k;
    
    return sumP;
}

std::istream & operator>>(std::istream &is, Poly &p){
    std::cout << "Enter the following terms: " << std::endl;
    for(int i=0;i<p.n;i++){
        std::cout << "Term "<< i+1 << "(coeff exp): ";
        std::cin >> p.t[i].coef >> p.t[i].exp;
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, const Poly &p){
    std::cout << "Polynomial: "<<std::endl;
    for(int i=0; i<p.n; i++){
        std::cout << p.t[i].coef << "x^" << p.t[i].exp;
        if(i<p.n - 1)
            std::cout << " + ";
    }
    std::cout << std::endl;
    return os;
}
