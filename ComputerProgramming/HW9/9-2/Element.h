#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
private:
    int data;
    Element *next;
    Element *previous;
public:
    Element(): next(0), previous(0), data(0){};
    Element(int data_):next(0), previous(0), data(data_){};
    //~Element():{};
    int getdata(){return data;}
    //Element* geeeetzz(){return next;}
    friend class Queue;
};

#endif