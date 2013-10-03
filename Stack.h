// Name:Steven Zilberberg
// Course: CSC 260-2 
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Exerice 6
// Description: Header file for stack template class
// Filename: Stack.h
// Last modified on: 11/3/11

#ifndef myStackStuff_Stack_h
#define myStackStuff_Stack_h

const int stackSize = 100;

template<class T>
class Stack
{
private:
    T items[stackSize];
    int stackIndex;
public:
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: Stack ()
	//
	//	Parameters:	
	//	Pre-condition:
	//  Post-condition: Constructs a Stack.
	//-----------------------------------------------------------------------------------------
    Stack();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: push ()
    //
    //	Parameters:
    //		input T;	element of the Stack
    //	Pre-condition: Stack has been initialized.
    //  Post-condition: Adds the element to the Stack if it is not full.
    //-----------------------------------------------------------------------------------------
    void push(T);
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: pop ()
    //
    //	Parameters:	
    //	Pre-condition: The Stack has been initialized.
    //  Post-condition: Removes the top element of the Stack.
    //-----------------------------------------------------------------------------------------
    void pop();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: peek ()
    //
    //	Parameters:	
    //		output T;	top element of the Stack
    //	Pre-condition: The Stack has been initialized.
    //  Post-condition: Returns the element on the top of the Stack, if the Stack is not empty.
    //-----------------------------------------------------------------------------------------
    T peek();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: size ()
    //
    //	Parameters:	
    //		output int;	the size of the Stack
    //	Pre-condition: The Stack has been initialized.
    //  Post-condition: Returns the size of the Stack.
    //-----------------------------------------------------------------------------------------
    int size();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: isFull ()
    //
    //	Parameters:
    //		output bool;	indicates whether or not the Stack is full
    //	Pre-condition: The Stack has been initialized.
    //  Post-condition: Returns true if the Stack is full, otherwise it returns false.
    //-----------------------------------------------------------------------------------------
    bool isFull();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: isEmpty ()
    //
    //	Parameters:
    //		output bool;	indicates whether or not the Stack is empty
    //	Pre-condition: The Stack has been initialized.
    //  Post-condition: Returns true if the Stack is empty, otherwise it returns false.
    //-----------------------------------------------------------------------------------------
    bool isEmpty();
};

#endif
