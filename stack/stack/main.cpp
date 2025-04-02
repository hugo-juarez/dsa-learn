//
//  main.cpp
//  stack
//
//  Created by Hugo Juarez on 4/2/25.
//

#include "stack_array.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    StackArray s = StackArray(5);
    s.push(1);s.push(2);s.push(3);s.push(4);s.push(5);
    std::cout << "This is the stack:\n";
    std::cout << s << std::endl;
    std::cout << "Popped " << s.pop() << ", " << s.pop() << std::endl;
    std::cout << "This is the stack:\n";
    std::cout << s << std::endl;
    std::cout << "Peak: ";
    std::cout << s.peek(3);
    std::cout << ", Top: ";
    std::cout << s.stackTop() << std::endl;
    return 0;
}
