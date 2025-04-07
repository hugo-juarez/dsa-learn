//
//  queue_array.hpp
//  queue
//
//  Created by Hugo Juarez on 4/7/25.
//

#ifndef queue_array_hpp
#define queue_array_hpp

#include <memory>


class QueueArray {
private:
    int size;
    int front;
    int rear;
    std::unique_ptr<int[]> A;
public:
    QueueArray(int sz);
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int first();
    int last();
};


#endif /* queue_array_hpp */
