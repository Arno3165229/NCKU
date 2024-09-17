#include <iostream>
#include "Queue.h"

int main(){
    Queue queue;
    queue.pop_front();
    queue.print();
    queue.push_back(0);
    queue.print();
    queue.push_back(62);
    queue.print();
    queue.push_front(3);
    queue.print();
    queue.push_front(50);
    queue.print();
    queue.pop_back();
    queue.print();
    queue.pop_front();
    queue.print();
    queue.pop_back();
    queue.print();
    queue.push_back(70);
    queue.print();
}