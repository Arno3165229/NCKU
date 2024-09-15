#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<cstring>
using namespace std;

 
template <class T>
class Stack
{
public:
Stack(const int StackCapacity = 10):capacity(StackCapacity)
{
itemArray = new T[capacity];
memset(itemArray,0,capacity*sizeof(T));
top = -1;
}
~Stack()
{
delete[]itemArray;
}
bool IsEmpty()const
{
return top == -1;
}

T& Top()
{
if(IsEmpty()) throw "Stack is empty";
return itemArray[top];
}

void Push(const T &addItem)
{
if(top == capacity -1)
{
//resize the array
T* tempArray = new T[2*capacity];
memset(tempArray,0,2*capacity*sizeof(T));
memcpy(tempArray,itemArray,capacity*sizeof(T));
delete[] itemArray;
itemArray = tempArray;
capacity *=2;
}
itemArray[++top] = addItem;
}

void Pop()
{
itemArray[top--].~T();
}

void Print()const
{
for(int i = 0 ; i <= top ; i++)
{
cout<< "("<< itemArray[i].x_pos-1<< ","<< itemArray[i].y_pos-1 << ")"<< " ";
}
cout<<endl;
}

int getSize(){
    return top+1;
}

private:
int top;
int capacity;
T* itemArray;
};
#endif