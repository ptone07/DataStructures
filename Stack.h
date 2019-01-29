/*
	Anthony Hanna
	Header file for Stack class
  Stack is a linked list that follows LIFO protocol, Last In First Out
*/

#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack
{
    int *list;
    int top;
    int max;
    
    public:
    MyStack( int );
    ~MyStack();
    int push( int );
    int pop();
    int peek( int& ) const;
};

MyStack::MyStack( int m ) // create the stack
{
    max = m;
    list = new int[max];
    top = -1;
}

MyStack::~MyStack() // delete the stack
{
    delete [] list;
}

int MyStack::push( int a ) // push value on to the top of the stack
{
    int result = -1;
    
    if( top != max - 1 )
    {
        top = top + 1;
        list[top] = a;
        result = 0;
    }
    
    return result;
}

int MyStack::pop() // pop the first value off the stack
{
    int result = -1;
    
    if( top != -1 )
    {
        top = top - 1;
        result = 0;
    }
    
    return result;
}

int MyStack::peek( int& a ) const // display whats on top of the stack stack
{
    int result = -1;
    
    if( top != -1 )
    {
        a = list[top];
        result = 0;
    }
    
    return result;
}

#endif
