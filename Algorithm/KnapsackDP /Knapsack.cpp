#include<cstdio>
#include<iostream>

using namespace std;

void knapSack(int val[], int wt[], int n, int W);
int Max(int x, int y);

int main() {

  //the first element is set to 0 and storing item from index 1 in val[] and wt[] array
  int val[] = {0, 130, 50, 60, 30, 80};  //assume the value of the items by myself
  int wt[] = {0, 5, 2, 3, 1, 3};        //assume the weight of the items by myself
  
  int n = 5;  //total items
  int W = 7;  //capacity of knapsack
  
  knapSack(val,wt,n,W);

  return 0;
}

// return max function
int Max(int x, int y) {
  if(x > y) return x;
  else return y;
}

void knapSack(int val[], int wt[], int n, int W) {
  int i, w;

  //value table having n+1 rows and W+1 columns
  int V[n+1][W+1];

  //fill the row i=0 with value 0
  for(w = 0; w <= W; w++) {
    V[0][w] = 0;
  }

  //fill the column w=0 with value 0
  for(i = 0; i <= n; i++) {   
    V[i][0] = 0;   
  }

  //fill the value table
  for(i = 1; i <= n; i++) {
    for(w = 1; w <= W; w++) {
      if(wt[i] <= w) {
        V[i][w] = Max(V[i-1][w], val[i] + V[i-1][w - wt[i]]);
      } 
      else {
        V[i][w] = V[i-1][w];
      }
    }
  }
  //max value that can be put inside the knapsack
  cout<< "Max Value: "<< V[n][W]<< endl;
}