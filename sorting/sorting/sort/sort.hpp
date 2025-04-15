//
//  sort.hpp
//  sorting
//
//  Created by Hugo Juarez on 4/14/25.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
#include <vector>

class Sort {
private:
    void _quickSort(std::vector<int> &A, std::size_t l, std::size_t h);
    void _medianOfThree(std::vector<int> &A, std::size_t l, std::size_t h);
public:
    void bubbleSort(std::vector<int> &A);
    void insertionSort(std::vector<int> &A);
    void selectionSort(std::vector<int> &A);
    void quickSort(std::vector<int> &A);
};

#endif /* sort_hpp */
