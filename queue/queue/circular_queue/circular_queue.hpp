//
//  circular_queue.hpp
//  queue
//
//  Created by Hugo Juarez on 4/7/25.
//

#ifndef circular_queue_hpp
#define circular_queue_hpp

#include <stdio.h>
#include <memory>

class CircularQueue {
private:
    int size;
    int front;
    int rear;
    std::unique_ptr<int[]> A;
    
public:
    CircularQueue(int sz);
    void enqueue(int x);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const;
    friend std::ostream& operator<<(std::ostream &os, const CircularQueue &q);
};

#endif /* circular_queue_hpp */
