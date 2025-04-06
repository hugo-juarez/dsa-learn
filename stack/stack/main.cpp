//
//  main.cpp
//  stack
//
//  Created by Hugo Juarez on 4/2/25.
//

#include "stack_array.h"
#include "stack_linked.h"
#include "infix_to_post.h"
#include <iostream>
#include <memory>

bool isBalanced(const char *s);

int main(int argc, const char * argv[]) {
    // insert code here...
    StackLinked s = StackLinked();
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
    std::cout << "Checking if the following string is balanced '((a+b)*(c-d))':\n";
    std::cout << (isBalanced("((a+b)*(c-d))") ? "Is Balanced":"Is NOT Balanced")<< std::endl;
    std::cout << "Converting infix to postfix 'a+b*c-d/e':\n";
    std::cout << infixToPostfix("a+b*c-d/e") << std::endl;
    return 0;
}

bool isBalanced(const char *s){
    
    StackLinked stack = StackLinked();
    
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == '(')
            stack.push('(');
        else if (s[i] == ')'){
            
            if(stack.isEmpty())
                return false;
            
            stack.pop();
        }
    }
    
    return stack.isEmpty();
    
}

