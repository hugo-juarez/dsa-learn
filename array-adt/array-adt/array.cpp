//
//  array.cpp
//  array-adt
//
//  Created by Hugo Juarez on 3/20/25.
//

#include "array.h"
#include <iostream>
#include <memory>

using namespace std;

Array::Array() : size(10), length(0) {
    A = new int[size];
}

Array::Array(int sz) : size(sz), length(0) {
    A = new int[size];
}

Array::Array(int* Arr, int sz, int len) {
    size = sz;
    length = len;
    A = new int[size];
    
    for(int i=0;i<length;i++){
        A[i] = Arr[i];
    }
}

void Array::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

bool Array::isSorted(){
    for (int i=0; i<(length-1); ++i) {
        if(A[i] > A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Array::Display(){
    cout << "This are the elements of the array: " << endl;
    for(int i=0; i<length; ++i){
        cout << A[i] << "\t";
    }
    cout << endl;
}

void Array::Append(int x){
    if (length<size) {
        A[length++] = x;
    }
}

void Array::Insert(int index, int x){
    if(index >=0 && index <=length){
        for(int i=length; i>index; --i){
            A[i] = A[i-1];
        }
        A[index] = x;
        if(length < size){
            length++;
        }
    }
}

//Insert if sorted
void Array::Insert(int x){
    
    int i = (length -1);
    
    if(!isSorted()){
        cout << "Array is not sorted try adding an index" << endl;
        return;
    }
    
    if(length >= size){
        return;
    }
    
    while (i>=0 && A[i] > x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
    
}

int Array::Delete(int index){
    int x;
    if(index >= 0 && index <length){
        x= A[index];
        for(int i=index; i<length; ++i){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}

int Array::Sort(int key){
    if(isSorted()){
        cout << "Using Binary Search: " << endl;
        return BinarySearch(key);
    }
    else {
        cout << "Using Linear Search: " << endl;
        return LinearSearch(key);
    }
}

int Array::LinearSearch(int key){
    for(int i=0; i<length; ++i) {
        if(A[i]==key){
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key){
    int l=0;
    int h=length-1;
    int mid;
    
    while(l<=h){
        mid=(l+h)/2;
        if(A[mid] == key){
            return mid;
        }
        if(A[mid] < key){
            l = mid + 1;
        } else if (A[mid] > key){
            h = mid - 1;
        }
    }
    return -1;
    
}

int Array::Get(int index){
    if(index >=0 && index<length){
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x){
    if(index>=0 && index<length){
        A[index] = x;
    }
}

int Array::Max(){
    int max = A[0];
    for(int i=1; i<length; ++i){
        if(max < A[i]){
            max = A[i];
        }
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for(int i=1; i<length; ++i){
        if(min > A[i]){
            min = A[i];
        }
    }
    return min;
}

int Array::Sum(){
    int sum=0;
    for(int i=0; i<length; ++i){
        sum += A[i];
    }
    return sum;
}

float Array::Avg(){
    return (double) Sum()/length;
}

void Array::Reverse(){
    if(isSorted()){
        cout<<"Using Reverse2: "<<endl;
        Reverse2();
    } else {
        cout<<"Using Reverse1: "<<endl;
        Reverse1();
    }
}

void Array::Reverse1(){
    int *temp = new int[length];
    
    for(int i=(length-1), j=0; i>=0; i--, j++){
        temp[j] = A[i];
    }
    
    for(int i=0; i<length; i++){
        A[i] = temp[i];
    }
    
    delete []temp;
    
}

void Array::Reverse2(){
    for(int i=0, j=(length-1); i<j; i++, j--){
        swap(&A[i], &A[j]);
    }
}

Array* Array::Merge(Array &arr2){
    int size = length + arr2.length;
    Array* mergedArr = new Array(size);
    int i,j,k;
    i=j=k=0;
    
    if(!isSorted() || !arr2.isSorted()){
        cout << "Arrays are not sorted";
        return NULL;
    }
    
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            mergedArr->A[k++] = A[i++];
        } else{
            mergedArr->A[k++] = arr2.A[j++];
        }
    }
    
    for(;i<length;i++)
        mergedArr->A[k++]=A[i];
    for(;j<arr2.length; j++)
        mergedArr->A[k++]=arr2.A[j];
    
    mergedArr->length = length + arr2.length;
    
    return mergedArr;
}

Array* Array::Union(Array &arr2){
    
    if(!isSorted() || !arr2.isSorted())
        return NULL;
    
    int size = length + arr2.length;
    Array* uArray = new Array(size);
    int i,j,k;
    i=j=k=0;
    
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j])
            uArray->A[k++]=A[i++];
        else if (A[i]>arr2.A[j])
            uArray->A[k++]=arr2.A[j++];
        else{
            i++;
            j++;
        }
    }
    
    for(;i<length;i++)uArray->A[k++]=A[i];
    for(;j<arr2.length;j++)uArray->A[k++]=arr2.A[j];
    
    uArray->length = k;
    return uArray;
}

Array* Array::Diff(Array &arr2){
    
    if(!isSorted() || !arr2.isSorted())
        return NULL;
    
    int size = length;
    Array* uArray = new Array(size);
    int i,j,k;
    i=j=k=0;
    
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j])
            uArray->A[k++]=A[i++];
        else if (A[i]>arr2.A[j])
            j++;
        else{
            i++;
            j++;
        }
    }
    
    for(;i<length;i++)uArray->A[k++]=A[i];
    
    uArray->length = k;
    return uArray;
}

Array* Array::Inter(Array &arr2){
    if(!isSorted() || !arr2.isSorted()) {
        cout << "Arrays were not in order. Try again" << endl;
        return NULL;
    }
    
    int size = length + arr2.length;
    Array* pArray = new Array(size);
    
    int i,j,k;
    i=j=k=0;
    
    while (i<length && j<arr2.length) {
        if(A[i]<arr2.A[j]){
            i++;
        } else if (A[i]>arr2.A[j]){
            j++;
        } else if (A[i]==arr2.A[j]) {
            pArray->A[k++] = A[i++];
            j++;
        }
    }
    
    pArray->length = k;
    
    return pArray;
    
}

void Array::FindMissingElements1(void){
    if(!isSorted()){
        return;
    }
    int diff = A[0];
    
    for(int i= 0; i<length; i++){
        while(A[i]-i > diff){
            cout << "Missing element: " << diff + i << endl;
            diff++;
        }
    }
}

void Array::FindMissingElements2(void){
    
    int h = Max();
    int l= Min();
    
    unique_ptr<Array> pHash = make_unique<Array>(h+1);
    
    for(int i= 0; i<length; i++){
        pHash->A[A[i]]++;
    }
    
    cout << "This array is missing: " <<endl;
    for(int i=l; i<=h; i++)
        if(pHash->A[i] == 0)
            cout << i <<"\t";
    
    cout << endl;
}

void Array::FindDuplicateElements1(void){
    if(!isSorted()){
        return;
    }
    
    for(int i=0; i<(length-1); i++){
        if(A[i] != A[i+1])
            continue;
        
        int j;
        
        for(j=i+1; j<length && A[i]==A[j];j++);
        cout << "The element " << A[i] << " is repeated " << j-i << " times." <<endl;
        i = j-1;
    }
}

void Array::FindDuplicateElements2(void){
    int sz = Max();
    int l = Min();
    unique_ptr<Array> pH = make_unique<Array>(sz+1);
    pH-> length = sz+1;
    
    for(int i=0;i<length;i++)
        pH->A[A[i]]++;
    
    for(int i=l; i<pH->length; i++)
        if(pH->A[i]>1)
            cout << "Element " << i<< " is repeated "<< pH->A[i] << " times." << endl;
}

Array::~Array() {
    cout << "I am erasing myself" <<endl;
    delete []A;
}

