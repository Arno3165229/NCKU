#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<time.h>

using namespace std;
int random(int min, int max);
void matrix(float mask[][3],int **array,float **arr_convolution,int m,int n);


int main(){
    float mask_a[3][3] = {{0, -0.5, 0},  // mask a
                        {-0.5, 0, 0.5},
                        {0, -0.5, 0}};
    float mask_b[3][3] = {{0.5, 0.25, 0.5}, // mask b
                        {0.25, 1, 0.25},
                        {0.5, -0.5, 0.5}};
    srand(unsigned(time(NULL)));
    int m = random(4,10);
    int n = random(4,10);
    //cout << m<< endl<< n <<endl;

    int **array = new int*[m]; // 動態宣告原始二維陣列
    for(int i = 0; i < m; i++){
        array[i] = new int[n]; 
    }

    float **arr_convolution = new float*[m]; // 動態宣告convolution後之二維陣列
    for(int i = 0; i < m; i++){
        arr_convolution[i] = new float[n];
    }

    cout<< "image data"<< endl;

    for(int i = 0; i < m; i++){      // 亂數產生原始陣列之隨機值
        for(int j = 0; j < n; j++){
            array[i][j] = random(0,255); 
            cout<< std::left<< setw(10)<< array[i][j];
        }
        cout<< endl;
    }
    cout<< endl<< "image convolution with mask a"<< endl;
    matrix(mask_a,array,arr_convolution,m,n);
    cout<<"------------------------------------"<<endl;
    cout<< "image convolution with mask b"<< endl;
    matrix(mask_b,array,arr_convolution,m,n);

    // 釋放記憶體空間
    for(int i = 0; i < m; i++){  
       delete []array[i];
    }
    for(int i = 0; i < m; i++){
       delete []arr_convolution[i];
    }
    delete []array;
    delete []arr_convolution;
    return 0;
}

// random function
int random(int min, int max){ 
    int x = rand() % (max - min + 1) + min;
    return x;
}

// convolution function
void matrix(float mask[][3],int **array,float **arr_convolution,int m,int n){
    float value = 0; // 紀錄最大值
    int a; // 紀錄最大值x座標
    int b; // 紀錄最大值y座標
    for(int i = 0;i < n; i++){
        arr_convolution[0][i] = array[0][i]; // 第1 row值與原矩陣一樣
        cout<<std::left<< setw(10)<< arr_convolution[0][i];
        if(arr_convolution[0][i] > value){   // 倘若此時之值大於原本value 則更新value大小 並記錄座標
            value = arr_convolution[0][i];
            a = 0;
            b = i;
        }
    }
    cout <<endl;
    for(int i = 1; i < m-1; i++){ // 從第2row開始
        arr_convolution[i][0] = array[i][0]; // 每一個row的第一個值會與原矩陣一樣
        cout << std::left<< setw(10)<< arr_convolution[i][0];
        if(arr_convolution[i][0] > value){  // 倘若此時之值大於原本value 則更新value大小 並記錄座標
            value = arr_convolution[i][0];
            a = i;
            b = 0;
        }
        for(int j = 1; j < n-1; j++){ // 其中之值 依照convolution 定義賦值
            arr_convolution[i][j]=
            array[i-1][j-1]*mask[0][0]+array[i-1][j]*mask[0][1]+array[i-1][j+1]*mask[0][2]+
            array[i][j-1]*mask[1][0]+array[i][j]*mask[1][1]+array[i][j+1]*mask[1][2]+
            array[i+1][j-1]*mask[2][0]+array[i+1][j]*mask[2][1]+array[i+1][j+1]*mask[2][2];
            cout<< std::left<< setw(10)<< arr_convolution[i][j];
            if(arr_convolution[i][j] > value){ // 倘若此時之值大於原本value 則更新value大小 並記錄座標
                value = arr_convolution[i][j];
                a = i;
                b = j;
            }
        }
        arr_convolution[i][n-1] = array[i][n-1]; // 每一個row的第(n-1)之值(最後一個數字)會與原矩陣一樣
        cout<< std::left<< setw(10)<< arr_convolution[i][n-1];
        cout<< endl;
        if(arr_convolution[i][n-1] > value){ // 倘若此時之值大於原本value 則更新value大小 並記錄座標
                value = arr_convolution[i][n-1];
                a = i;
                b = n-1;
            }
    }
    for(int i = 0;i < n; i++){  // 第m row 之值會與原矩陣一樣
        arr_convolution[m-1][i] = array[m-1][i];  // 倘若此時之值大於原本value 則更新value大小 並記錄座標
        cout << std::left<< setw(10)<< arr_convolution[m-1][i];
        if(arr_convolution[m-1][i] > value){
                value = arr_convolution[m-1][i];
                a = m-1;
                b = i;
            }
    }

    cout<<endl;
    cout << "the max value " << value << " is at(" << a <<"," << b <<")"<<endl;
}
