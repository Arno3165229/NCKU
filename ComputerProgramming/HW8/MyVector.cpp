#include "MyVector.h"
#include <iostream>

using namespace std;

MyVector :: MyVector(){}

MyVector :: MyVector(double _x, double _y, double _z){
    x = _x;
    y = _y;
    z = _z;
}

MyVector MyVector :: Set(double _x, double _y, double _z){
    return MyVector(_x,_y,_z);
}

double MyVector :: Dot(MyVector &a ){
    double dot;
    dot = x*a.x + y*a.y + z*a.z;
    return dot;
}

MyVector MyVector :: Cross(MyVector &a){
    return MyVector(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
}

void MyVector :: Show(){
    cout<< "("<< x<< ","<< y<< ","<< z <<")"<< endl;
}