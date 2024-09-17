#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<time.h>

using namespace std;

inline int Random(const int lower, const int upper);
double** Create(const int rows, const int columns);
void CreateElements(double **&matrix, const int rows, const int columns);
void Convolution(double **result, const double *const*const matrix,const int rows, const int columns,const double *const*const mask);
double Maximum(const double *const*const matrix, const int rows,const int columns, int *index_row, int *index_col);
void Release(double **&matrix, const int rows);

struct MyImage{
    double **Data;
    unsigned int rows;
    unsigned int columns;
};


int main(){
    srand(unsigned(time(NULL))); //亂數種子
    int m = Random(2,5); // 隨機產生row(m)
    int n = Random(2,5); // 隨機家生column(n)
    //cout << m<< endl<< n <<endl;
    cout<< "image data"<< endl;
    double **matrix = Create(m,n); //動態宣告原始matrix
    double **result = Create(m,n); //動態宣告卷積後的matrix

    double **maska = Create(3,3); // 動態宣告遮罩a
    double **maskb = Create(3,3); // 動態宣告遮罩b
    // 遮罩a 賦值
    maska[0][0] = 0; maska[0][1] = -0.5; maska[0][2] = 0;
    maska[1][0] = -0.5; maska[1][1] = 0; maska[1][2] = 0.5;
    maska[2][0] = 0; maska[2][1] = -0.5; maska[2][2] = 0;
    // 遮罩b 賦值
    maskb[0][0] = 0.5; maskb[0][1] = 0.25; maskb[0][2] = 0.5;
    maskb[1][0] = 0.25; maskb[1][1] = 1; maskb[1][2] = 0.25;
    maskb[2][0] = 0.5; maskb[2][1] = -0.5; maskb[2][2] = 0.5;

    CreateElements(matrix,m,n); // 原始matrix 亂數賦值

    // cout出來
    for(int i = 0;i < m; i++){
        for(int j = 0;j < n; j++){
            cout<< std::left<< setw(10)<< matrix[i][j];
        }
        cout<<endl;
    }
    cout<< endl<< "image convolution with mask a"<< endl;

    Convolution(result,matrix,m,n,maska); // 原始matrix與maska做卷積 得到 result matrix

    // cout 出來
    for(int i = 0;i < m; i++){
        for(int j = 0;j < n; j++){
            cout<< std::left<< setw(10)<< result[i][j];
        }
        cout<<endl;
    }
    
    int a; // 拿來記錄最大值之位置
    int b; // 拿來記錄最大值之位置
    double value_a; // 拿來記錄與maska卷積後結果之最大值
    
    value_a = Maximum(result, m, n, &a, &b); // return maximum
    cout << "the max value " << value_a << " is at(" << a <<"," << b <<")"<<endl;

    cout<<"------------------------------------"<<endl;

    cout<< "image convolution with mask b"<< endl;

    Convolution(result,matrix,m,n,maskb); // 原始matrix與maskb做卷積 得到 result matrix

    //cout 出來
    for(int i = 0;i < m; i++){
        for(int j = 0;j < n; j++){
            cout<< std::left<< setw(10)<< result[i][j];
        }
        cout<<endl;
    }

    double value_b; // 拿來記錄與maskb卷積後結果之最大值
    value_b = Maximum(result, m, n, &a, &b); // return maximum
    cout << "the max value " << value_b << " is at(" << a <<"," << b <<")"<<endl;

    // 釋放動態宣告之空間
    Release(matrix,m);
    Release(result,m);
    Release(maska,3);
    Release(maskb,3);

    return 0;
}

// random function
inline int Random(const int lower, const int upper){ 
    int x = rand() % (upper - lower + 1) + lower;
    return x;
}

double** Create(const int rows, const int columns){
    double **array = new double*[rows]; // 動態宣告原始二維陣列
    for(int i = 0; i < rows; i++){
        array[i] = new double[columns]; 
    }
    return array;
}

void CreateElements(double **&matrix, const int rows, const int columns){
    for(int i = 0; i < rows; i++){      // 亂數產生原始陣列之隨機值
        for(int j = 0; j < columns; j++){
            matrix[i][j] = Random(0,255); 
        }
    }
}

void Convolution(double **result, const double *const*const matrix, 
const int rows, const int columns, const double *const*const mask)
{
    for(int i = 0;i < columns; i++){
        result[0][i] = matrix[0][i]; // 第1 row值與原矩陣一樣
    }
 
    for(int i = 1; i < rows-1; i++){ // 從第2row開始
        result[i][0] = matrix[i][0]; // 每一個row的第一個值會與原矩陣一樣
    
        for(int j = 1; j < columns-1; j++){ // 其中之值 依照convolution 定義賦值
            result[i][j]=
            matrix[i-1][j-1]*mask[0][0]+matrix[i-1][j]*mask[0][1]+matrix[i-1][j+1]*mask[0][2]+
            matrix[i][j-1]*mask[1][0]+matrix[i][j]*mask[1][1]+matrix[i][j+1]*mask[1][2]+
            matrix[i+1][j-1]*mask[2][0]+matrix[i+1][j]*mask[2][1]+matrix[i+1][j+1]*mask[2][2];
        }
        result[i][columns-1] = matrix[i][columns-1]; // 每一個row的第(n-1)之值(最後一個數字)會與原矩陣一樣
    }

    for(int i = 0;i < columns; i++){  // 第m row 之值會與原矩陣一樣
        result[rows-1][i] = matrix[rows-1][i];  // 倘若此時之值大於原本value 則更新value大小 並記錄座標
    }
    
}
double Maximum(const double *const*const matrix, const int rows,
 const int columns, int *index_row, int *index_col){
     double value = 0;
     for(int i = 0;i < rows; i++){
         for(int j = 0;j < columns; j++){
             if( matrix[i][j] > value){
                 value = matrix[i][j];
                 *index_row = i;
                 *index_col = j;
             }
         }
     }
     return value;
 }

 void Release(double **&matrix, const int rows){
    for(int i = 0; i < rows; i++){  
       delete []matrix[i];
    }
    delete []matrix;
 }
