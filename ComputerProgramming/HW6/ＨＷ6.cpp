#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
void create_int(int *&arr,int k);
void create_short(short *&arr,int k);
void create_float(float *&arr,int k);
void create_double(double *&arr,int k);

template<class T>
double Mean(const T* arr,int num);
T Max(const T* arr,int num);
T MIN(const T* arr,int num);
double Mid(const T* arr,int num);
double SD(const T*arr,int num);


int main(){
    srand(unsigned time(NULL));
    return 0;
}

void create_int(int *&arr,int k){
    int max = 50;
    int min = -50;
    for(int i = 0; i < k; i++){
        arr[i] = rand()%(max-min+1)+min;
    }
}
void create_short(short *&arr,int k){
    short max = 50;
    short min = -50;
    for(int i = 0; i < k; i++){
        arr[i] = rand()%(max-min+1)+min;
    }
}
void create_float(float *&arr,int k){
    float max = 50;
    float min = -50;
    for(int i = 0; i < k; i++){
        arr[i] = rand()%(max-min+1)+min;
    }
}
void create_double(double *&arr,int k){
    double max = 50;
    double min = -50;
    for(int i = 0; i < k; i++){
        arr[i] = rand()%(max-min+1)+min;
    }
}

double Mean(const T* arr,int num){
    double total;
    for(int i = 0; i < num; i++){
        total = arr[i] + total;
    }
    
}