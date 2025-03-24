//
//  main.cpp
//  array-adt
//
//  Created by Hugo Juarez on 3/19/25.
//

#include <iostream>
#include "array.h"

using namespace std;

int main() {
    Array *arr;
    Array *uArr;
    int n;
    int x;
    //int index;
    
    cout << "Enter your array size ";
    cin >> n;
    
    arr = new Array(n);
    
    cout << "Appending new value: ";
    cin >> x;
    
    arr->Append(x);
    
    cout << "Appending new value: ";
    cin >> x;
    
    arr->Append(x);
    
    cout << "Appending new value: ";
    cin >> x;
    
    arr->Append(x);
    
    cout << "Array 1" << endl;
    arr->Display();
    
    Array arr2 = Array(x);
    
    arr2.Append(4);
    arr2.Append(6);
    arr2.Append(7);
    
    cout << "Array 2" << endl;
    arr2.Display();
    
    cout << "Inter"<< endl;
    uArr = arr->Inter(arr2);
    
    uArr->Display();
    
    /*
    cout << "Union"<< endl;
    uArr = arr->Union(arr2);
    
    uArr->Display();
    
    
    
    cout << "Merging"<< endl;
    merged = arr->Merge(arr2);
    
    merged->Display();
    
    cout << "Select insert index and value to add: ";
    cin >> index >> x;
    
    arr->Insert(index, x);
    
    arr->Display();
    
    cout << "Search: ";
    cin >> x;
    
    cout << "The value " << x << " is in index: " << arr->Sort(x) << endl;
    
    arr->Display();
    
    cout << "Max: "<< arr->Max() << endl;
    cout << "Min: "<< arr->Min() << endl;
    cout << "Sum: "<< arr->Sum() << endl;
    cout << "Avg: "<< arr->Avg() << endl;
    
    cout << "Reversed the list" << endl;
    arr->Reverse();
    arr->Display();
    
    cout << "Input number that you wanna insert: " << endl;
    cin >> x;
    
    arr->Insert(x);
    arr->Display();
    */
    delete arr;
    delete uArr;
    return 0;
}
