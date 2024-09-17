#include "Combo.h"
#include <iostream>

using namespace std;

int Combo :: custom_Count = 0;

Combo :: Combo(){
    main_course = 1;
    side = 2;
    drink = 2;
    ice = false;
}

Combo :: Combo(int a, int b, int c){
    main_course = a;
    side = b;
    drink = c;
    ice = false;
}

Combo :: Combo(int a,int b, int c, bool d){
    main_course = a;
    side = b;
    drink = c;
    ice = d;
}

void Combo :: Change_main(int a){
    main_course = a;
}

void Combo :: Change_side(int b){
    side = b;
}

void Combo :: Change_drink(int c){
    drink = c;
}

void Combo :: Change_ice(bool d){
    ice = d;
}

int Combo :: TotalPrice(){
    int main_price;
    int side_price;
    int total;
    if (main_course == 1) main_price = 72;
    if (main_course == 2) main_price = 62;
    if (main_course == 3) main_price = 99;
    if (main_course == 4) main_price = 82;
    if (main_course == 5) main_price = 49;
    if (main_course == 6) main_price = 59;
    if (main_course == 7) main_price = 99;
    if (main_course == 8) main_price = 72;
    if (main_course == 9) main_price = 110;
    if (main_course == 10) main_price = 90;
    if (main_course == 11) main_price = 52;
    if (main_course == 12) main_price = 49;
    if (main_course == 13) main_price = 69;
    if (side == 1) side_price = 50;
    if (side == 11) side_price = 55;
    if (side == 2) side_price = 50;
    if (side == 22) side_price = 60;
    if (side == 3 || side == 33 || side == 333) side_price = 65;
    if (side == 4 || side == 44) side_price = 68;

    total = main_price + side_price;

    return total;
}

void Print(Combo &a){
    cout<< "您的套餐內容："<< endl;
    cout<< "主餐：";
    if (a.main_course == 1) cout<< "大當克"<< endl;
    if (a.main_course == 2) cout<< "單層牛肉堡"<< endl;
    if (a.main_course == 3) cout<< "普羅旺斯牛肉堡"<< endl;
    if (a.main_course == 4) cout<< "香香烤雞堡"<< endl;
    if (a.main_course == 5) cout<< "當香雞"<< endl;
    if (a.main_course == 6) cout<< "當克雞塊(六塊)"<< endl;
    if (a.main_course == 7) cout<< "當克雞塊(十塊)"<< endl;
    if (a.main_course == 8) cout<< "火辣雞排堡"<< endl;
    if (a.main_course == 9) cout<< "當脆雞(二塊)"<< endl;
    if (a.main_course == 10) cout<< "當脆雞翅(兩塊)"<< endl;
    if (a.main_course == 11) cout<< "藍帶豬排堡"<< endl;
    if (a.main_course == 12) cout<< "當香魚"<< endl;
    if (a.main_course == 13) cout<< "和風櫻花蝦堡"<< endl;
    cout<< "配餐：";
    if (a.side == 1) cout<< "經典配餐-中薯";
    if (a.side == 11) cout<< "經典配餐-大薯";
    if (a.side == 2) cout<< "清爽配餐-夏季沙拉";
    if (a.side == 22) cout<< "清爽配餐-大份夏季沙拉";
    if (a.side == 3) cout<< "酷炫配餐-巧克力口味冰炫風";
    if (a.side == 33) cout<< "酷炫配餐-野莓口味冰炫風";
    if (a.side == 333) cout<< "酷炫配餐-咖啡口味冰炫風";
    if (a.side == 4) cout<< "勁脆配餐-原味當脆雞";
    if (a.side == 44) cout<< "勁脆配餐-辣味當脆雞";
    cout<< endl<< "飲料：";
    if (a.drink == 1) cout<< "中杯可樂";
    if (a.drink == 2) cout<< "中杯纖多多";
    if (a.drink == 3) cout<< "中杯紅茶";
    if (a.drink == 4) cout<< "中杯綠茶";
    if (a.drink == 5) cout<< "中杯柳橙汁";

    if (a.ice == true) cout<< "(正常冰)";
    if (a.ice == false) cout<< "(去冰)";
    
    Combo :: custom_Count++;
}

int Combo :: GetCustomCount(){
    return custom_Count;
}