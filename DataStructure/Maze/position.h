#ifndef POSITION_H
#define POSITION_H

#include<iostream>

using namespace std;

class Position
{
public:
int x_pos;
int y_pos;
Position(){}
Position(int x,int y){
x_pos = x;
y_pos = y;
}
};

class route
{
public:
int x_pos;
int y_pos;
route():x_pos(0),y_pos(0){}
};

ostream& operator << (ostream& os,const Position pos)
{
os << "("<<pos.x_pos<<" ,"<<pos.y_pos<<")";
return os;
}
#endif