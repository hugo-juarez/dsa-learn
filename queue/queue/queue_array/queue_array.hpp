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
    bool isEmpty() const;
    bool isFull() const;
    int first() const;
    int last() const;
    friend std::ostream & operator<<(std::ostream &os, const QueueArray &q);
};


#endif /* queue_array_hpp */
