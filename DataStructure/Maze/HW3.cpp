#include"stack.h"
#include"position.h"
#include<iostream>
#include<cstring>

using namespace std;

const int max_row = 16;
const int max_column = 17;

// 額外自己多加兩個row 以及 兩個 column (皆設為1 當原路徑無法走之邊界)
char maze[max_row][max_column] = { 
{ '1','1','1', '1' ,'1' ,'1', '1', '1' ,'1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 0
{ '1','0','0', '0' ,'0' ,'0', '0', '0' ,'0', '0', '0', '1', '0', '0', '0', '0', '1'}, // 1
{ '1','0','1', '0' ,'0' ,'1', '1', '1' ,'1', '1', '1', '0', '0', '0', '0', '0', '1'}, // 2
{ '1','0','1', '0' ,'1' ,'1', '0', '0' ,'0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 3
{ '1','0','1', '1' ,'1' ,'0', '0', '0' ,'0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 4
{ '1','0','0', '0' ,'0' ,'1', '0', '0' ,'0', '1', '1', '1', '1', '1', '0', '0', '1'}, // 5
{ '1','0','1', '1' ,'1' ,'0', '0', '0' ,'0', '0', '0', '0', '0', '1', '0', '0', '1'}, // 6
{ '1','0','1', '1' ,'0' ,'0', '0', '0' ,'0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 7
{ '1','0','1', '1' ,'0' ,'0', '0', '0' ,'1', '0', '1', '0', '1', '0', '1', '1', '1'}, // 8
{ '1','0','0', '0' ,'0' ,'1', '0', '0' ,'0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 9
{ '1','0','1', '1' ,'0' ,'0', '0', '1' ,'0', '0', '0', '0', '0', '0', '0', '0', '1'}, //10
{ '1','0','1', '1' ,'0' ,'0', '1', '1' ,'0', '0', '0', '0', '1', '0', '0', '0', '1'}, //11
{ '1','0','1', '1' ,'0' ,'0', '0', '1' ,'1', '1', '1', '1', '1', '0', '0', '0', '1'}, //12
{ '1','0','1', '1' ,'0' ,'0', '0', '0' ,'0', '0', '0', '0', '1', '0', '0', '0', '1'}, //13
{ '1','0','0', '1' ,'0' ,'0', '0', '0' ,'0', '0', '0', '0', '0', '1', '0', '0', '1'}, //14
{ '1','1','1', '1' ,'1' ,'1', '1', '1' ,'1', '1', '1', '1', '1', '1', '1', '1', '1'}, //15
};

int path[max_row][max_column] = {0}; // 紀錄走過的路

int main()
{
route way[4];

way[0].x_pos=0;
way[0].y_pos=1; // 右

way[1].x_pos=1;
way[1].y_pos=0; // 下

way[2].x_pos=0;
way[2].y_pos=-1; // 左

way[3].x_pos=-1;
way[3].y_pos=0; // 上


Stack<Position> stack1(10);
Position start(1,1); // 起始路徑
stack1.Push(start);
path[1][1] ++; 
int dimention = 0;

while(dimention <= 4 && !stack1.IsEmpty()){
    Position nowPos(stack1.Top().x_pos,stack1.Top().y_pos);
    if(dimention == 4) {  // 四個方向都無法
        dimention = 0;
        stack1.Pop(); // pop 掉
        continue;
     }
    if(nowPos.x_pos == 14 && nowPos.y_pos == 15) break; // 終點

    Position nextPos(nowPos.x_pos + way[dimention].x_pos,nowPos.y_pos + way[dimention].y_pos);

    // maze ！= 1 and path = 0 時才可走
    if(maze[nextPos.x_pos][nextPos.y_pos] != '1' && path[nextPos.x_pos][nextPos.y_pos] == 0){ 
        stack1.Push(nextPos);
        path[nextPos.x_pos][nextPos.y_pos] ++;  // path ++ 表示走過的route
        dimention = 0;
    }
    else{
        dimention++; // 試下一個方向
    }
}

if(stack1.IsEmpty()) {
    cout<<"there's no way out"<<endl; return 0;
}
cout<< endl << "the shortest path is:"<<endl<<"----------------------"<<endl;
stack1.Print();
cout<<"total step are: "<<stack1.getSize()<<endl;

// 把stack 裡面的值全部pop 出來 並 設 ‘X’ 在原maze matrix上 以表示走過之路徑
while(!stack1.IsEmpty()){ 
      int x = stack1.Top().x_pos;
      int y = stack1.Top().y_pos;
      maze[x][y] ='X';
      stack1.Pop();
}
cout<< endl<< "Show the solution path:"<<endl<<"---------------------------"<<endl;

// 一開始矩陣有多設兩欄 columns and rows 當邊界 故實際 print值時 不需print出來
for(int i = 1 ; i<15 ;i++){
    for(int j = 1 ; j < 16 ; j++)
    cout<<maze[i][j]<<' ';
    cout<<endl;
}

return 0;
}
