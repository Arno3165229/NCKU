#include "Combo.h"
#include <iostream>
#include <iomanip>

using namespace std;
void Exchange(int, int);

int main(){
    int main, side, drink;
    bool ice;
    int money;
    char frice;
    char salad;
    int flavor;
    int spicy;
    char ice_;

    cout<<"--------------------第一位客人-----------------"<< endl;
    cout<< "請選擇主餐："<< endl;
    cout<< std::left<< setw(10) << "1.大當克"<< endl;
    cout<< std::left<< setw(10) << "2.單層牛肉堡"<< endl;
    cout<< std::left<< setw(10) << "3.普羅旺斯牛肉堡"<< endl;
    cout<< std::left<< setw(10) << "4.香香烤雞堡"<< endl;
    cout<< std::left<< setw(10) << "5.當香雞"<< endl;
    cout<< std::left<< setw(10) << "6.當克雞塊(六塊)"<< endl;
    cout<< std::left<< setw(10) << "7.當克雞塊(十塊)"<< endl;
    cout<< std::left<< setw(10) << "8.火辣雞排堡"<< endl;
    cout<< std::left<< setw(10) << "9.當脆雞(二塊)"<< endl;
    cout<< std::left<< setw(10) << "10.當脆雞翅(兩塊)"<< endl;
    cout<< std::left<< setw(10) << "11.藍帶豬排堡"<< endl;
    cout<< std::left<< setw(10) << "12.當香魚"<< endl;
    cout<< std::left<< setw(10) << "13.和風櫻花蝦堡"<< endl;
    while(1){
    cin>> main;
    if(main>=1 && main<=13) break;
    else cout<<"輸入錯誤，請重新輸入"<<endl;
    }
    cout<< "請選擇配餐："<< endl;
    cout<< std::left<< setw(10) << "1.經典配餐-中薯+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "2.清爽配餐-夏季沙拉+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "3.酷炫配餐-冰颱風+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "4.勁脆配餐-當脆雞+中杯飲料"<< endl;
    while(1){
    cin>> side;
    if(side>=1 && side<=4) break;
    else cout<<"輸入錯誤，請重新輸入"<<endl;
    }
    if (side == 1){
        cout<< "是否需要+5元升級大薯(y/n)"<< endl;
        while(1){
        cin>> frice;
        if(frice == 'y' || frice == 'Y') {side = 11; break;}
        else if(frice == 'n' || frice == 'N') {side = 1; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 2){
        cout<< "是否需要+10元升級大份夏季沙拉(y/n)"<< endl;
        while(1){
        cin>> salad;
        if(salad == 'y' || salad == 'Y') {side = 22; break;}
        else if(salad == 'n' || salad == 'N') {side = 2; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 3){
        cout<< "請選擇冰炫風口位：" <<endl;
        cout<< "1.巧克力口味  2.野莓口味  3.咖啡口味"<< endl;
        while(1){
        cin>> flavor;
        if(flavor == 1) {side = 3; break;}
        else if(flavor == 2) {side = 33; break;}
        else if(flavor == 3) {side = 333; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 4){
        cout<< "請選擇： 1.原味炸雞  2.辣味炸雞"<< endl;
        while(1){
        cin>> spicy;
        if(spicy == 1) {side = 4; break;}
        else if(spicy == 2) {side = 44; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    cout<< "請選擇飲料"<< endl;
    cout<< std::left<< setw(10) << "1.可樂"<< endl;
    cout<< std::left<< setw(10) << "2.纖多多"<< endl;
    cout<< std::left<< setw(10) << "3.紅茶"<< endl;
    cout<< std::left<< setw(10) << "4.綠茶"<< endl;
    cout<< std::left<< setw(10) << "5.柳橙汁"<< endl;
    while(1){
    cin>> drink;
    if(drink>=1 && drink <=5) break;
    else cout<< "輸入錯誤，請重新輸入"<< endl; 
    }
    Combo a(main,side,drink);
    cout<< "請問飲料是否去冰(y/n)"<< endl;
    while(1){
    cin>> ice_;
    if(ice_ == 'y' || ice_ == 'Y') {ice = false; break;}
    else if(ice_ == 'n' || ice_ == 'N') {ice = true; break;}
    else cout<< "輸入錯誤，請重新輸入"<< endl;
    }
    a.Change_ice(ice);
    Print(a);
    cout<< endl<< "價格為：" << a.TotalPrice()<< endl;
    cout<< "請輸入付費金額：";
    cin>> money;
    Exchange(money, a.TotalPrice());
    cout<< "今日累積客人:"<< Combo::GetCustomCount()<< "位"<< endl;

    cout<<"--------------------第二位客人-----------------"<< endl;
    cout<< "請選擇主餐："<< endl;
    cout<< std::left<< setw(10) << "1.大當克"<< endl;
    cout<< std::left<< setw(10) << "2.單層牛肉堡"<< endl;
    cout<< std::left<< setw(10) << "3.普羅旺斯牛肉堡"<< endl;
    cout<< std::left<< setw(10) << "4.香香烤雞堡"<< endl;
    cout<< std::left<< setw(10) << "5.當香雞"<< endl;
    cout<< std::left<< setw(10) << "6.當克雞塊(六塊)"<< endl;
    cout<< std::left<< setw(10) << "7.當克雞塊(十塊)"<< endl;
    cout<< std::left<< setw(10) << "8.火辣雞排堡"<< endl;
    cout<< std::left<< setw(10) << "9.當脆雞(二塊)"<< endl;
    cout<< std::left<< setw(10) << "10.當脆雞翅(兩塊)"<< endl;
    cout<< std::left<< setw(10) << "11.藍帶豬排堡"<< endl;
    cout<< std::left<< setw(10) << "12.當香魚"<< endl;
    cout<< std::left<< setw(10) << "13.和風櫻花蝦堡"<< endl;
    while(1){
    cin>> main;
    if(main>=1 && main<=13) break;
    else cout<<"輸入錯誤，請重新輸入"<<endl;
    }
    cout<< "請選擇配餐："<< endl;
    cout<< std::left<< setw(10) << "1.經典配餐-中薯+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "2.清爽配餐-夏季沙拉+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "3.酷炫配餐-冰颱風+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "4.勁脆配餐-當脆雞+中杯飲料"<< endl;
    while(1){
    cin>> side;
    if(side>=1 && side<=4) break;
    else cout<<"輸入錯誤，請重新輸入"<<endl;
    }
    if (side == 1){
        cout<< "是否需要+5元升級大薯(y/n)"<< endl;
        while(1){
        cin>> frice;
        if(frice == 'y' || frice == 'Y') {side = 11; break;}
        else if(frice == 'n' || frice == 'N') {side = 1; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 2){
        cout<< "是否需要+10元升級大份夏季沙拉(y/n)"<< endl;
        while(1){
        cin>> salad;
        if(salad == 'y' || salad == 'Y') {side = 22; break;}
        else if(salad == 'n' || salad == 'N') {side = 2; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 3){
        cout<< "請選擇冰炫風口位：" <<endl;
        cout<< "1.巧克力口味  2.野莓口味  3.咖啡口味"<< endl;
        while(1){
        cin>> flavor;
        if(flavor == 1) {side = 3; break;}
        else if(flavor == 2) {side = 33; break;}
        else if(flavor == 3) {side = 333; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 4){
        cout<< "請選擇： 1.原味炸雞  2.辣味炸雞"<< endl;
        while(1){
        cin>> spicy;
        if(spicy == 1) {side = 4; break;}
        else if(spicy == 2) {side = 44; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    cout<< "請選擇飲料"<< endl;
    cout<< std::left<< setw(10) << "1.可樂"<< endl;
    cout<< std::left<< setw(10) << "2.纖多多"<< endl;
    cout<< std::left<< setw(10) << "3.紅茶"<< endl;
    cout<< std::left<< setw(10) << "4.綠茶"<< endl;
    cout<< std::left<< setw(10) << "5.柳橙汁"<< endl;
    while(1){
    cin>> drink;
    if(drink>=1 && drink <=5) break;
    else cout<< "輸入錯誤，請重新輸入"<< endl; 
    }
    cout<< "請問飲料是否去冰(y/n)"<< endl;
    while(1){
    cin>> ice_;
    if(ice_ == 'y' || ice_ == 'Y') {ice = false; break;}
    else if(ice_ == 'n' || ice_ == 'N') {ice = true; break;}
    else cout<< "輸入錯誤，請重新輸入"<< endl;
    }
    Combo b(main, side, drink, ice);
    Print(b);
    cout<< endl<< "價格為：" << b.TotalPrice()<< endl;
    cout<< "請輸入付費金額：";
    cin>> money;
    Exchange(money, b.TotalPrice());
    cout<< "今日累積客人:"<< Combo::GetCustomCount()<< "位"<< endl;

    Combo c;
    cout<<"--------------------第三位客人-----------------"<< endl;
    cout<< "請選擇主餐："<< endl;
    cout<< std::left<< setw(10) << "1.大當克"<< endl;
    cout<< std::left<< setw(10) << "2.單層牛肉堡"<< endl;
    cout<< std::left<< setw(10) << "3.普羅旺斯牛肉堡"<< endl;
    cout<< std::left<< setw(10) << "4.香香烤雞堡"<< endl;
    cout<< std::left<< setw(10) << "5.當香雞"<< endl;
    cout<< std::left<< setw(10) << "6.當克雞塊(六塊)"<< endl;
    cout<< std::left<< setw(10) << "7.當克雞塊(十塊)"<< endl;
    cout<< std::left<< setw(10) << "8.火辣雞排堡"<< endl;
    cout<< std::left<< setw(10) << "9.當脆雞(二塊)"<< endl;
    cout<< std::left<< setw(10) << "10.當脆雞翅(兩塊)"<< endl;
    cout<< std::left<< setw(10) << "11.藍帶豬排堡"<< endl;
    cout<< std::left<< setw(10) << "12.當香魚"<< endl;
    cout<< std::left<< setw(10) << "13.和風櫻花蝦堡"<< endl;
    while(1){
    cin>> main;
    if(main>=1 && main<=13) break;
    else cout<<"輸入錯誤，請重新輸入"<<endl;
    }
    cout<< "請選擇配餐："<< endl;
    cout<< std::left<< setw(10) << "1.經典配餐-中薯+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "2.清爽配餐-夏季沙拉+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "3.酷炫配餐-冰颱風+中杯飲料"<< endl;
    cout<< std::left<< setw(10) << "4.勁脆配餐-當脆雞+中杯飲料"<< endl;
    while(1){
    cin>> side;
    if(side>=1 && side<=4) break;
    else cout<<"輸入錯誤，請重新輸入"<<endl;
    }
    if (side == 1){
        cout<< "是否需要+5元升級大薯(y/n)"<< endl;
        while(1){
        cin>> frice;
        if(frice == 'y' || frice == 'Y') {side = 11; break;}
        else if(frice == 'n' || frice == 'N') {side = 1; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 2){
        cout<< "是否需要+10元升級大份夏季沙拉(y/n)"<< endl;
        while(1){
        cin>> salad;
        if(salad == 'y' || salad == 'Y') {side = 22; break;}
        else if(salad == 'n' || salad == 'N') {side = 2; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 3){
        cout<< "請選擇冰炫風口位：" <<endl;
        cout<< "1.巧克力口味  2.野莓口味  3.咖啡口味"<< endl;
        while(1){
        cin>> flavor;
        if(flavor == 1) {side = 3; break;}
        else if(flavor == 2) {side = 33; break;}
        else if(flavor == 3) {side = 333; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    if (side == 4){
        cout<< "請選擇： 1.原味炸雞  2.辣味炸雞"<< endl;
        while(1){
        cin>> spicy;
        if(spicy == 1) {side = 4; break;}
        else if(spicy == 2) {side = 44; break;}
        else {
            cout<< "輸入錯誤，請重新輸入"<< endl;
         }
        }
    }
    cout<< "請選擇飲料"<< endl;
    cout<< std::left<< setw(10) << "1.可樂"<< endl;
    cout<< std::left<< setw(10) << "2.纖多多"<< endl;
    cout<< std::left<< setw(10) << "3.紅茶"<< endl;
    cout<< std::left<< setw(10) << "4.綠茶"<< endl;
    cout<< std::left<< setw(10) << "5.柳橙汁"<< endl;
    while(1){
    cin>> drink;
    if(drink>=1 && drink <=5) break;
    else cout<< "輸入錯誤，請重新輸入"<< endl; 
    }
    cout<< "請問飲料是否去冰(y/n)"<< endl;
    while(1){
    cin>> ice_;
    if(ice_ == 'y' || ice_ == 'Y') {ice = false; break;}
    else if(ice_ == 'n' || ice_ == 'N') {ice = true; break;}
    else cout<< "輸入錯誤，請重新輸入"<< endl;
    }
    c.Change_main(main);
    c.Change_side(side);
    c.Change_drink(drink);
    c.Change_ice(ice);
    Print(c);
    cout<< endl<< "價格為：" << c.TotalPrice()<< endl;
    cout<< "請輸入付費金額：";
    cin>> money;
    Exchange(money, c.TotalPrice());
    cout<< "今日累積客人:"<< Combo::GetCustomCount()<< "位"<< endl;

    return 0;
}

void Exchange(int money, int price){
    int a = money - price;
    if(a < 0) cout<< "金額不足"<< endl;
    else{
    int a_100 = a/100;
    int a_50 = (a-100*a_100)/50;
    int a_10 = ((a-100*a_100)-50*a_50)/10;
    int a_5 = (((a-100*a_100)-50*a_50)-10*a_10)/5;
    int a_1 = ((((a-100*a_100)-50*a_50)-10*a_10)-5*a_5)/1;
    cout<< "找零："<< a<< "元"<< endl<< "百元鈔："<< a_100<< endl<< "50元"<< a_50<< endl<<
    "10元"<< a_10<< endl<< "5元："<< a_5<< endl<< "1元："<< a_1<< endl;
    }
}