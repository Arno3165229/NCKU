#include "MyVector.h"
#include <iostream>

using namespace std;

int main(){
    MyVector m;
    MyVector n;
    MyVector cross_result;
    double mx, my, mz;
    double nx, ny, nz;
    double dot;
    cout << "請輸入m向量之x座標：";
    cin >> mx;
    cout << "請輸入m向量之y座標：";
    cin >> my;
    cout << "請輸入m向量之z座標：";
    cin >> mz;
    cout << "請輸入n向量之x座標：";
    cin >> nx;
    cout << "請輸入n向量之y座標：";
    cin >> ny;
    cout << "請輸入n向量之z座標：";
    cin >> nz;
    m = m.Set(mx,my,mz);
    n = n.Set(nx,ny,nz);
    dot = m.Dot(n);
    cout<< "內積結果："<< dot<< endl;
    cross_result = m.Cross(n);
    cout<< "外積結果：";
    cross_result.Show();
    return 0;
}