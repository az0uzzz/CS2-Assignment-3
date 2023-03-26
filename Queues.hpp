//
//  Queue.hpp
//  CS2 Asn 3
//
//  Created by Mohamed Azouz on 25/03/2023.
//

#ifndef Queues_hpp
#define Queues_hpp

#include <stdio.h>
#include <iostream>

#endif /* Queue_hpp */

using namespace std;

template <class T> // template class which accepts a class as a parameter to determine the type
class Queues
{
private:
    T queue[100]; // createes an array of size 100 for the queue to operate on
    int front; // creates a variable to point at the front of the queue
public:
    Queues() // default constructor sets the front to -1 as there is no elements in the array
    {
        front = -1;
    }
    void Push(T x) // push function adds an object of type t to the queue
    {
        front++;
        queue[front]=x;
    }
    T Pop() // pop function returns the front object of the queue
    {
        front--;
        return queue[front+1];
    }
    bool isEmpty() // isempty function checks whether the queue is empty
    {
        if(front==-1)
            return true;
        return false;
    }
};
