#include<stdio.h>
#include<stdlib.h>


void merge_sort(int arr[], int head, int tail); // mergesort function
void merge(int arr[], int head, int mid, int tail); // merge function
 
int main()
{
    FILE *fp_r, *fp_w;
    fp_r=fopen("number_input.txt","r"); // read input file
    fp_w=fopen("number_sorted.txt","w");  //output file

    int i;
    int count; //the number of keys to be sorted

    fscanf(fp_r,"%d",&count); //read the first line in input file
    int list[count]; // build up an array to save the numbers in second line which will be sorted

    printf("%d",count);
    printf("  ");
    printf("Numbers to be sorted: ");

    for(int j=1;j<2;j++){  // read the number from second line of input file
     for(i = 0; i<count; i++){
       fscanf(fp_r,"%d",&list[i]);
       printf("%d ", list[i]);
     }
    }
    printf("\n");
 
    merge_sort(list, 0, count-1); // rnu merge sort algorithm
 
    printf("Numbers Sorted: ");
    fprintf(fp_w,"%d\n",count); // show the total number is be sorted in first line of output file
    for(i = 0; i<count; i++){
       fprintf(fp_w,"%d ",list[i]); // show the numbers which are sorted in second line of output file
       printf("%d ", list[i]);
     }
    printf("\n");
    fclose(fp_r);
    fclose(fp_w);
    return 0;
}

void merge_sort(int arr[], int head, int tail){
  if(head < tail){
    int mid = (head + tail) / 2;
    merge_sort(arr, head, mid);
    merge_sort(arr, mid+1, tail);
    merge(arr, head, mid, tail);
  }
}

// Merge two sub-arrays of list[].

void merge(int arr[], int head, int mid, int tail){
  int lenA = mid - head + 1;
  int lenB = tail - (mid + 1) + 1;
  int A[lenA];  // First sub-array is arr[head..mid]
  int B[lenB];  // Second sub-array is arr[mid+1..tail]
 
  // copy values to temp arrays A[] and B[]
  int i, j, k;
  for(i = 0; i < lenA; i++){
    A[i] = arr[head + i];
  }
  for(j = 0; j < lenB; j++){
    B[j] = arr[mid + 1 + j];
  }
 
  // Merge two temp arrays back into arr[head..tail]
  i = 0;
  j = 0;
  k = head;
  //while array A and B haven't finished scanning
  while(i < lenA && j < lenB){
    if(A[i] < B[j]){
      arr[k] = A[i];
      i++;
    }
    else{
      arr[k] = B[j];
      j++;
    }
    k++;
  }
 
  //Copy the remaing elements into arr[], if A[] haven't finished scanning but B[] have finished
  while(i < lenA){
    arr[k] = A[i];
    i++;
    k++;
  }
  //Copy the remaing elements into arr[], if B[] haven't finished scanning but A[] have finished
  while(j < lenB){
    arr[k] = B[j];
    j++;
    k++;
  }
}