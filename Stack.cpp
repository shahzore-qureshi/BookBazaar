// Name:Steven Zilberberg
// Course: CSC 260-2 
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Exerice 6
// Description: .cpp for stack template class
// Filename: Stack.cpp
// Last modified on: 11/3/11

#include <iostream>
#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
    stackIndex = 0;
}

template<class T>
void Stack<T>::push(T item)
{
    if(stackIndex < stackSize)
    {
        items[stackIndex] = item;
        stackIndex++;
    }
}

template<class T>
void Stack<T>::pop()
{
    if(stackIndex > 0)
        stackIndex--;
}

template<class T>
T Stack<T>::peek()
{
    if(stackIndex > 0)
        return items[stackIndex - 1];
    else
        return T();
}

template<class T>
int Stack<T>::size()
{
    return stackIndex;
}

template<class T>
bool Stack<T>::isFull()
{
    if(stackIndex == 0)
        return false;
    else
        return true;
}

template<class T>
bool Stack<T>::isEmpty()
{
    if(stackIndex == 0)
        return true;
    else
        return false;
}