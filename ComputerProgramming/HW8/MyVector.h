#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector
{
private:
  double x;
  double y;
  double z;
public:
    MyVector();
    MyVector(double _x, double _y, double _z);

    MyVector Set(double _x, double _y, double _z);
    double Dot(MyVector &a);
    MyVector Cross(MyVector &a);
    void Show();
};

#endif