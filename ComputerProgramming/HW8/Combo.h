#ifndef COMBO_H
#define COMBO_H

class Combo
{
private:
   int main_course;
   int side;
   int drink;
   bool ice;
   static int custom_Count;

public:
   Combo();
   Combo(int, int, int);
   Combo(int, int, int, bool);
   void Change_main(int);
   void Change_side(int);
   void Change_drink(int);
   void Change_ice(bool);
   int TotalPrice();
   friend void Print(Combo&);
   static int GetCustomCount();
};

#endif