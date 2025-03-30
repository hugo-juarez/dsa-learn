//
//  main.cpp
//  linked-list
//
//  Created by Hugo Juarez on 3/29/25.
//

#include <iostream>
#include "linked_list.h"

int main(int argc, const char * argv[]) {
    int A[] = {3,5,6,7};
    LinkedList link = LinkedList(A,4);
    //LinkedList link = LinkedList();
    
    std::cout << "My Linked List" << std::endl;
    std::cout << link << std::endl;
    /*
    std::cout << "Length: " << link.Length();
    std::cout << ", Sum: " << link.Sum();
    std::cout << ", Max: " << link.Max();
    std::cout << std::endl;
    std::cout << "Search 2: " << (link.Search(2) ? "Found" : "Not Found");
    std::cout << ", Search 4: " << (link.Search(4) ? "Found" : "Not Found");
    std::cout << ", Search 5: " << (link.Search(5) ? "Found" : "Not Found");
    std::cout << std::endl;
     
    link.Insert(4, 20);
    link.Append(30);
     */
    std::cout <<"Sorted: "<< (link.isSorted() ? "True" : "False") << std::endl;
    link.InsertSorted(8);
    link.Append(20);
    std::cout << "After Insert Linked List" << std::endl;
    std::cout << link << std::endl;
}
