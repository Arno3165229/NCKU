#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<ctype.h>

using namespace std;

void Mov(char num1,string num2);
void Add(char num1,string num2);
void Sub(char num1,string num2);
void Mul(char num1,string num2);
void Div(char num1,string num2);
void Inc(char num1);
void Dec(char num1);
int verify(char f);
int verify_2(string l);
void exchange(char f);

int a = 0; //初值皆設為0
int b = 0;
int c = 0;
int d = 0;
int x,y; // 設立變數來暫時計算並儲存其對應之值

int main()
{
    string input;
    cout << "清輸入指令" << endl;

    while(1){
    getline(cin,input);
    if (input == "#") { // 輸入#時 跳出while loop
        break;
    }

    int pos = input.find(",",0); // 找出第一個逗號的位置
    int last = input.size(); // 輸入字串之長度
    string str1 = input.substr(0,pos); // 從第一個逗號前切割第一個子字串 (如mov,add,...等等)
    string str2 = input.substr(pos+1,last); // 第一個逗號後為第二個子字串
    char f = str2[0]; // 因不考慮無效輸入，故第一個逗號後之第一個字必為a,b,c,d其中之字元
    int last2 = str2.size(); // 求出第二個子字串之長度
    string str3; 
    if(last2 > 2) str3 = str2.substr(2,last2); // 倘若第二個子字串之長度大於2，而非只有單一字元(如a,b 或 a,17等等) 
                                 // 再從第二個子字串之逗號後切割成第三個子字串(如a,b之 str3為b; a,17之 str3為17)
    if ((str1[0] == 'M' || str1[0] == 'm')    
        && (str1[1] == 'O' || str1[1] == 'o') 
        && (str1[2] == 'V' || str1[2] == 'v')){   // mov大小寫皆可 變執行 Mov fun.
        Mov(f,str3);
    }
    if ((str1[0] == 'I' || str1[0] == 'i') 
        && (str1[1] == 'N' || str1[1] == 'n') 
        && (str1[2] == 'C' || str1[2] == 'c')){ // inc 大小寫皆可 變執行 Inc fun.
        Inc(f);
    }
    if ((str1[0] == 'A' || str1[0] == 'a') 
        && (str1[1] == 'D' || str1[1] == 'd') 
        && (str1[2] == 'D' || str1[2] == 'd')){ // add 大小寫皆可 變執行 Add fun.
        Add(f,str3);
    }
    if ((str1[0] == 'S' || str1[0] == 's') 
        && (str1[1] == 'U' || str1[1] == 'u') 
        && (str1[2] == 'B' || str1[2] == 'b')){ // sub 大小寫皆可 變執行 Sub fun.
        Sub(f,str3);
    }
    if ((str1[0] == 'M' || str1[0] == 'm') 
        && (str1[1] == 'U' || str1[1] == 'u') 
        && (str1[2] == 'L' || str1[2] == 'l')){ // mul 大小寫皆可 變執行 Mul fun.
        Mul(f,str3);
    }
    if ((str1[0] == 'D' || str1[0] == 'd') 
        && (str1[1] == 'I' || str1[1] == 'i') 
        && (str1[2] == 'V' || str1[2] == 'v')){ // div 大小寫皆可 變執行 Div fun.
        Div(f,str3);
    }
    if ((str1[0] == 'D' || str1[0] == 'd') 
        && (str1[1] == 'E' || str1[1] == 'e') 
        && (str1[2] == 'C' || str1[2] == 'c')){ // dec 大小寫皆可 變執行 Dec fun.
        Dec(f);
    }


    }
    cout << "A:" << a <<endl; // 顯示其最後結果
    cout << "B:" << b <<endl;
    cout << "C:" << c <<endl;
    cout << "D:" << d <<endl;
    
    return 0;
}

int verify(char f){   // 判斷輸入之第一個逗號後第一個字元 使其返回其值 
        if (f == 'a') return a;
        else if (f == 'b') return b;
        else if (f == 'c') return c;
        else if (f == 'd') return d;
        else return 0;
}

int verify_2(string l){ // 判斷輸入之後第二個逗號後之字串
    if (isdigit(l[0])) return stoi(l); // 倘若為數字 進行字串轉整數 返回其值
    else {
        if (l[0] == 'a') return a; // 倘若為英文字母 則返回其對應之值
        else if (l[0] == 'b') return b;
        else if (l[0] == 'c') return c;
        else if (l[0] == 'd') return d;
        else return 0;
    }
}

void exchange (char f){ // 因在計算間 皆藉由變數x來計算 故最後需把值還回其對應到之變數
    if (f == 'a') a = x;
    if (f == 'b') b = x;
    if (f == 'c') c = x;
    if (f == 'd') d = x;
}

void Mov(char num1,string num2){
    x = verify(num1) ; 
    y = verify_2(num2) ;
    x = y;
    exchange(num1); // 把x之值傳給對應到之變數
}
void Add(char num1,string num2){
    x = verify(num1) ;
    y = verify_2(num2) ;
    x = x + y;
    exchange(num1);
}
void Sub(char num1,string num2){
    x = verify(num1) ;
    y = verify_2(num2) ;
    x = x - y;
    exchange(num1);
}
void Mul(char num1,string num2){
    x = verify(num1) ;
    y = verify_2(num2) ;
    x = x * y;
    exchange(num1);
}
void Div(char num1,string num2){
    x = verify(num1) ;
    y = verify_2(num2) ;
    x = x / y;
    exchange(num1);
}
void Inc(char num1){
    x = verify(num1);
    x = x + 1;
    exchange(num1);
}
void Dec(char num1){
    x = verify(num1);
    x = x - 1;
    exchange(num1);
}

// 以上程式依題目建立在不會有語法輸入錯誤之情況，但可容忍指令大小寫差別