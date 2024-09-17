#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<time.h>

using namespace std;
double* CreateArray1(double preset);


int main(){
    //double *a = CreateArray1(3);
    //cout<<a<<endl<<*a<<endl;
    return 0;    
}

double* CreateArray1(double preset){
    double arr[10];
    for(int i = 0;i<10; i++){
        arr[i] = preset;
    }
    return arr;
}