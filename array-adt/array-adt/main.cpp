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
    //int arr1[10] = {3,6,8,8,10,12,15,15,15,20};
    int arr2[10] = {8,3,6,4,6,5,6,8,2,2};
    
    Array *pArr1 = new Array(arr2,10,10);
    
    pArr1->Display();
    
    pArr1->FindDuplicateElements2();
    
    cout << "Out Of Missing Elements" << endl;
    
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
    delete pArr1;
    return 0;
}
