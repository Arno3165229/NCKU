#ifndef QUEUE_H
#define QUEUE_H

#include "Element.h"

class Queue
{
private:
     Element *front; 
     Element *rear;
public:
     Queue();
     Queue(Queue&);
     ~Queue();
     void push_back(int);
     void pop_front();
     void push_front(int);
     void pop_back();
     void print();
     bool is_empty();
};

#endif