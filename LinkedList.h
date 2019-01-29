/*
	Anthony Hanna
	Header file for Linked List

*/

#ifndef MYLIST_H
#define MYLIST_H
#include<iostream>

class MyList
{
    struct Node			// private Node as a nested struct with memebers value and *next
    {
        int value;
        Node* next;
    };
    
    Node* head;

    public: 				// public class
    
    MyList();
    ~MyList();
    bool isFull() const;
    bool isEmpty() const;
    bool find( int ) const;
    int remove ( int );
    int append( int );
    void clear();
    void print();

};

MyList::MyList()
{
    head = nullptr; // beginning of list
}

MyList::~MyList()
{
    clear(); // delete list
}

bool MyList::isFull() const		// check if list is full
{
    try 
        {
        Node* n = new Node;
        delete n;
        return false;
        }
    catch( std::bad_alloc )
        {
        return true;
        }
}
bool MyList::isEmpty() const // check if list is empty
{
    if ( head == 0 ) 
    {
    return true;
    }
    else 
    { 
    return false;
    }
}

bool MyList::find( int k ) const // search the list
{
    Node* p = head;
    while( p!=0 )
    {
        if ( p->value == k )
        
           return true;
           
            p = p->next;
    }
    return false;
}

int MyList::remove( int k ) // remove value from list
{
    int status = -1;
    
    Node* p = head;
    Node* q = nullptr;
    while( p != 0 && p->value != k )
    {
        q = p;
        p = p->next;
    }
    if( p != 0 )
    {
        if( q == 0 )
            head = head->next;
        else
            q->next = p->next;
            delete p;
            status = 0;
    }
    return status;
}

int MyList::append( int k ) // append ner value to list
{
    if( isFull() )
    return -1;

    Node* n = new Node{ k, 0 };

    if( isEmpty() )
        head = n;
    else 
    {
        Node* p = head;
        
        while( p->next != 0 )
       
        p = p->next;
        p->next = n;
    }
    return 0;
}

void MyList::clear() // clear the list
{
    while( head != 0 )
    {
    Node* p = head;
    head = head->next;
    delete p;
    }
}

void MyList::print()			//displays contents of list to screen
{
    Node* p = head;
    while( p )
    {
        std::cout << p->value << std::endl;
        p = p->next;
    }
}

#endif
