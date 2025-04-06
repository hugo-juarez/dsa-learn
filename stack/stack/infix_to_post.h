//
//  infix_to_post.h
//  stack
//
//  Created by Hugo Juarez on 4/6/25.
//

#ifndef INFIX_TO_POST_H
#define INFIX_TO_POST_H

#include "linked_list.h"
#include "stack_linked.h"
#include <memory>



bool isOperand(char x){
    return !(x == '+' || x == '*' || x == '-' || x == '/');
}

int precedence(char x){
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            break;
    }
    return 0;
}

std::unique_ptr<char[]> infixToPostfix(const char s[] ) {
    
    if(!s)
        return nullptr;
    
    
    int length = 0;
    LinkedList temp = LinkedList();
    StackLinked stack = StackLinked();
    
    for(int i=0; s[i] != '\0'; i++){
        
        length++;
        
        if(isOperand(s[i]))
            temp.push(s[i]);
        else{
            while(!stack.isEmpty() && precedence((char) stack.stackTop()) >= precedence(s[i])){
                temp.push(stack.pop());
            }
            stack.push(s[i]);
            
        }
    }
    
    while(!stack.isEmpty())
        temp.push(stack.pop());
    
    std::shared_ptr<LinkedList::Node> p = temp.first;
    std::unique_ptr<char []> string = std::make_unique<char []>(length + 1);
    int i = 0;
    
    while(p){
        string[i++] = p->data;
        p=p->next;
    }
    
    string[i] = '\0';
        
    return string;
}

#endif
