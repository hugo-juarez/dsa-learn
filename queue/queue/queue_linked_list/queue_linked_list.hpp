//
//  queue_linked_list.hpp
//  queue
//
//  Created by Hugo Juarez on 4/8/25.
//

#ifndef queue_linked_list_hpp
#define queue_linked_list_hpp

#include <stdio.h>
#include <memory>

class QueueLinked {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> front;
    std::shared_ptr<Node> rear;
public:
    QueueLinked();
    void enqueue(int x);
    int dequeue(void);
    bool isEmpty() const;
    friend std::ostream & operator<<(std::ostream &os, const QueueLinked &q);
};

#endif /* queue_linked_list_hpp */
