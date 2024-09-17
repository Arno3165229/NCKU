#include "Queue.h"
#include "Element.h"
#include <iostream>

using namespace std;

Queue :: Queue():front(0),rear(0){};

Queue :: Queue(Queue &a)
{
}

Queue :: ~Queue()
{
    while(front != 0){
        Element *d = front->next;
        delete front;
        front = d;
    }
    rear = 0;
}

void Queue :: push_back(int x)
{
    if(is_empty()){
        front = new Element(x);
        rear = front;
        return;
    }
    Element *newelement = new Element(x);
    rear->next = newelement;
    newelement->previous = rear;
    rear = newelement;
}

void Queue :: push_front(int x)
{
    if(is_empty()){
        front = new Element(x);
        rear = front;
        return;
    }
    Element *newelement = new Element(x);
    newelement->next = front;
    front->previous = newelement;
    front = newelement;
}

void Queue :: pop_front()
{
    if(is_empty()){
        cout<< "Queue is empty, so nothing is popped"<< endl;
        return ;
    }
    int m;
    Element *deletenode = front;
    m = deletenode->data;
    front = front->next;
    front->previous = 0;
    delete deletenode;
    deletenode = 0;
    return ;
}

void Queue :: pop_back()
{
    if(is_empty()){
        cout<< "Queue is empty, so nothing is popped"<< endl;
        return ;
    }
    int m;
    Element *deletenode = rear;
    m = deletenode->data;
    rear = rear->previous;
    rear->next = 0;
    delete deletenode;
    deletenode = 0;
    return ;
}


void Queue :: print()
{
    Element *k = front;
    cout<< "Queue:(front)"<< " ";
    while(k != 0){
        cout << k->getdata()<<" ";
        k = k->next;
    }
    if(is_empty()){
        cout<< "NULL"<<" ";
    }
    cout<< "(rear)"<< endl;
}

bool Queue :: is_empty()
{
    //if(front == 0 && rear == 0 ) return true;
    if((front && rear) == 0) return true;
    else return false;
   // return ((front && rear) == 0);

}