#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    while(1){
    string input; // 運算式字串
    char a; // 作為是否繼續執行while迴圈之判斷字元
    int wrong = 0; // 兩個子字串含有非0~9且非小數點之數目(預設先為0)
    int point = 0; // 第一個子字串之小數點數目(預設先為0)
    int point_2 = 0; // 第二個子字串之小數點數目(預設先為0)
    bool error = 0; 
    cout << "請輸入一個簡單的數學運算式"<<endl;
    getline(cin,input); // 輸入運算式
    int last = input.size(); // 求出字串長度
    int pos = input.find_first_of("+-*/",0); // 求出子字串分界位置
    if (pos == -1) {
        cout <<"輸入錯誤(未發現'+''-''*''/'四則運算符號)"<<endl; // 未發現運算符號 error值返回true
        error = 1;
    }

    string str1 = input.substr(0,pos); // 拆成兩個子字串 (從運算符號之位置去分割)
    string str2 = input.substr(pos+1,last);

    for (int i = 0; i < pos ; i++){
        if (str1[i] < '0' || str1[i] > '9'){ //判斷是否子字串含有非0~9之數字
            if (str1[i] == '.'){  
                point = point + 1;  // 倘若為非0~9之數字 判斷是否為小數點
            }
            else{
                wrong = wrong + 1; // 若非0~9也非小數點 則計入一次錯誤輸入
            } 
        }
    }

     for (int i = 0 ; i < last-pos-1 ; i++){
        if (str2[i] < '0' || str2[i] > '9'){ //判斷是否子字串含有非0~9之數字
            if (str2[i] == '.'){
             point_2 = point_2 + 1; // 倘若為非0~9之數字 判斷是否為小數點
             }
             else{
                 wrong = wrong + 1; // 若非0~9也非小數點 則計入一次錯誤輸入
             }
         }
    }

    if (wrong > 0 || point > 1 || point_2 > 1){  // 倘若擁有非0~9之數字且不是小數點 或是第一個子字串/第二個子字串擁有大於1個小數點
        cout << "輸入錯誤"<<endl;                 // 皆記錄為輸入錯誤 且error 返回true
        error = 1;
    }

    if(error == false){ // 倘若error為 false 才進入計算
     char symbol = input[pos]; 
     float num1 = stof(str1); // 字串轉浮點數
     float num2 = stof(str2); // 字串轉浮點數
     float total;
     if (symbol == '+') {  // 相加
         total = num1 + num2;
         cout << total <<endl;
     }
     else if (symbol == '-') { // 相減
         total = num1 - num2;
         cout << total <<endl;
     }
     else if (symbol == '*') { // 相乘
         total = num1 * num2;
         cout << total <<endl;
     }
     else if (symbol == '/') { // 相除
         if ( num2 == 0) {
            cout << "計算無效(除法不能除0)" <<endl; // 分母為0 計算無效
         }
         else
         {
            total = num1 / num2;  
            cout << total <<endl; 
         }
     }
    }
    cout<< "請問是否再次輸入運算式(輸入y/n)" <<endl;
    cin >> a;
    cin.get();
    if(a == 'y' || a == 'Y') continue;  // a=y 時 繼續執行while loop
    else if(a == 'n' || a == 'N') break; // a=n 時 跳出while loop
    }
    return 0;
} 

