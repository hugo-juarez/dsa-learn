//
//  array.h
//  array-adt
//
//  Created by Hugo Juarez on 3/20/25.
//

class Array
{
private:
    int *A;
    int size;
    int length;
    
    void swap(int *x, int *y);
    bool isSorted();
    int LinearSearch(int key);
    int BinarySearch(int key);
    void Reverse1();
    void Reverse2();
    
public:
    Array();
    Array(int sz);
    
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    void Insert(int x);
    int Delete(int index);
    int Sort(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    Array* Merge(Array &arr2);
    Array* Union(Array &arr2);
    Array* Diff(Array &arr2);
    Array* Inter(Array &arr2);
    
    ~Array();
};
