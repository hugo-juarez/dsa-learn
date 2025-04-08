//
//  main.cpp
//  queue
//
//  Created by Hugo Juarez on 4/7/25.
//

#include "queue_array/queue_array.hpp"
#include "circular_queue/circular_queue.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    int A[] = {1, 3, 5, 6, 9};
    
    int sz = sizeof(A)/sizeof(A[0]);
    CircularQueue q = CircularQueue(sz);
    
    for(int i=0;i<sz;i++)
        q.enqueue(A[i]);
    
    q.dequeue();
    q.dequeue();
    q.enqueue(10);
    q.enqueue(11);
    
    std::cout << "Queue: " << q << std::endl;
    
    std::cout << "Starting dequeue: "<< std::endl;
    
    for(int i=0; i<sz; i++)
        std::cout << i+1 << ": " << q.dequeue() << std::endl;;
    
    return 0;
}
