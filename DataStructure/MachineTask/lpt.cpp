#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
int choosemachine(int *,int);
void insertionsort(int *,int);
int main()
{
  int numofmachines,i,count;
  i=0;
  count=0;
  int *jobs=(int*)calloc(1000,sizeof(char));
  printf("please input the jobs:");
  while(scanf("%d",&jobs[count])!='0'&&getchar() != '\n')   //read the input
   {
     count++;
   }
   printf("please enter the numbers of machine:");
   scanf("%d",&numofmachines);
   int *trace=(int*)calloc(numofmachines,sizeof(int));
   insertionsort(jobs,count+1);     //sorting(insertion),then "jobs" become a priority queue
   for(i=0;i<=count;i++)  //put the jobs into the machines(scheduling)
   {
      int k;
      k=choosemachine(trace,numofmachines);
      trace[k]+=jobs[i];
      printf("(%d,%d)\n",k+1,jobs[i]);
   }
}
void insertionsort(int jobs[],int n)
{
   int i,key,j;
   for(i=1;i<n;i++)
  {
    key=jobs[i];
    j=i-1;
    while(j>=0&&jobs[j]<key)
   {
     jobs[j+1]=jobs[j];
     j--;
   }
   jobs[j+1]=key;  
  }
}
int choosemachine(int trace[],int numofmachines)
{
    int i,index=0;
    int min=trace[0];
     for(i=0;i<numofmachines;i++)
     {
       if(min>trace[i])
        {
           min=trace[i];
           index=i;
        }
     }
     return index;
}
/*
   時間複雜度估算:
    n 個jobs 
    m 個machines 
    insertionsort O(n)
    choose machines O(m)
    每個job一次choose
    =>O(n)+nO(m) 
*/
