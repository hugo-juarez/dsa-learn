//
//  main.cpp
//  linked-list
//
//  Created by Hugo Juarez on 3/29/25.
//

#include <iostream>
#include "linked_list.h"

int main(int argc, const char * argv[]) {
    int A[] = {3,5,5,5,5,7,7,7,9};
    int B[] = {4,6,10,11};
    LinkedList link = LinkedList(A,9);
    LinkedList l2 = LinkedList(B, 4);
    LinkedList t;
    
    std::cout << "Linked List A" << std::endl;
    std::cout << link << std::endl;
    std::cout << "Linked List B" << std::endl;
    std::cout << l2 << std::endl;
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
    //std::cout <<"Sorted: "<< (link.isSorted() ? "True" : "False") << std::endl;
    //link.InsertSorted(8);
    std::cout << "Deleting"<<std::endl;
    //link.Delete(2);
    link.RemoveDuplicates();
    link.Append(20);
    link.ReverseArray();
    link.ReverseSlidingPtr();
    link.Append(50);
    link.ReverseRecursively();
    link.Append(1);
    std::cout << "After Insert Linked List" << std::endl;
    std::cout << link << std::endl;
    */
    link.RemoveDuplicates();
    std::cout << "Concat Linked List" << std::endl;
    std::cout << link + l2 << std::endl;
    std::cout << "Merged Linked List" << std::endl;
    link.Merge(l2);
    std::cout << link << std::endl;
    std::cout << "Append Linked List" << std::endl;
    link.Append(12);
    std::cout << link << std::endl;
    t = link.createLoop();
    std::cout << "T is " << (t.isLoop() ? "A" : "NOT A") << " Loop!" << std::endl;
    std::cout << "Link is " << (link.isLoop() ? "A" : "NOT A") << " Loop!" << std::endl;
}
