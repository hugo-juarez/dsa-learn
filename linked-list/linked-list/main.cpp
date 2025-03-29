//
//  main.cpp
//  linked-list
//
//  Created by Hugo Juarez on 3/29/25.
//

#include <iostream>
#include "linked_list.h"

int main(int argc, const char * argv[]) {
    int A[] = {3,4,5,6};
    LinkedList link = LinkedList(A,4);
    
    std::cout << "My Linked List" << std::endl;
    std::cout << link << std::endl;
}
