#include<iostream>
#include<fstream>

using namespace std;

void quick_sort(int *arr, int head, int tail); // quick_sort function
int partition(int *arr, int head, int tail); // partition function
void exchange(int &a, int &b); // excahnge function 

int main(){
    ifstream file_r; // declare an input object(.txt)
    ofstream file_w; // declare an output object(.txt)
    int counter;
    int number; // the total number of the keys to be sorted
    file_r.open("nearly sorted random data.txt"); // input file name
    file_w.open("number_sorted_quick_sort.txt"); // output file name
    file_r >> number;
    int *array = new int[number]; // declare an array to store the keys
    for(counter = 0; counter < number; counter++){
        file_r >> array[counter]; // read the key
    }

    quick_sort(array, 0, number-1); // run the quick_sort algorithm

    file_w << number << endl;
    for(counter = 0; counter < number; counter++){
        file_w << array[counter] << endl;  //  the sorted key to the output file
    }
    delete [] array;
    return 0;
}

void quick_sort(int *arr, int head, int tail){ // quick_sort algorithm
  if(head < tail){
    int pivot = partition(arr, head, tail);
    quick_sort(arr, head, pivot-1);
    quick_sort(arr, pivot+1, tail);
  }
}

int partition(int *arr, int head, int tail){ // partition function
    int x = arr[tail];                       // distinguish two parts(smaller than pivot or bigger than pivot)
    int i = head - 1;
    for(int j = head; j <= tail-1; j++){
        if(arr[j] <= x){
            i = i + 1;
            exchange(arr[i],arr[j]);
        }
    }
    exchange(arr[i+1],arr[tail]);
    return (i+1);
}

void exchange(int &a, int &b){ // exchange two values by each other
    int temp = a;
    a = b;
    b = temp;
}