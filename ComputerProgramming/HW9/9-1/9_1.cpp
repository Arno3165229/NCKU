#include <iostream>
#include "Queue.h"


using namespace std;

int main(){
    Queue queue;
    int del;
    del = queue.pop_front();
    queue.print();
    queue.push_back(0);
    queue.print();
    queue.push_back(62);
    queue.print();
    del = queue.pop_front();
    queue.print();
    queue.push_back(50);
    queue.print();
    del = queue.pop_front();
    queue.print();
    del = queue.pop_front();
    queue.print();
    del = queue.pop_front();
    queue.print();
    queue.push_back(70);
    queue.print();

    return 0;
}