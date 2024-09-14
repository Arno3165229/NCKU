#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<cstdio>

using namespace std;

int random(int min,int max); // random function
void exchange(int &a, int &b); // exchange function

int main(){
    ofstream data;  // declare an output object(.txt)
    data.open("nearly sorted random data.txt");
    int total = 10000;  // the total key number
    int *a = new int[total];
    for(int i = 0; i < total ;i++){
        a[i] = i + 1; // give the value for all keys
    }
    srand( (unsigned)time(NULL) ); 
    for(int i = 0; i < 10 ; i++){  // run for ten time(it means exchange ten pairs)
        int a1 = random(0,999); 
        int a2 = random(0,999);  // choose two key randomly and exchange each other 
        exchange(a[a1],a[a2]);
    }
    data << total <<endl;
    for(int i = 0; i < total; i++){
        data << a[i] << endl;  // the ouput data(nearly sorted)
    }
    delete []a;
    return 0;
}

int random(int min,int max){
    int x = rand() % (max - min + 1) + min; // generate the random number [min,max]
    return x;
}
void exchange(int &a, int &b){ 
    int temp = a;
    a = b;    // exchange each other
    b = temp;
}