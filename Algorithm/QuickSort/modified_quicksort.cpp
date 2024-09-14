#include<iostream>
#include<fstream>

using namespace std;

#define K 550

int partition(int[], int, int);
void limited_quicksort(int[], int, int, int);
void insertion_sort(int[], int, int);
void modified_quicksort(int A[], int p, int r);

int main(){
    ifstream file_r; // declare an input object(.txt)
    ofstream file_w; // declare an output object(.txt)
    int counter;
    int number; // the total number of the keys to be sorted
    file_r.open("nearly sorted random data.txt"); // input file name
    file_w.open("number_sorted_modified_quicksort.txt"); // output file name
    file_r >> number;
    int *array = new int[number]; // declare an array to store the keys
    for(counter = 0; counter < number; counter++){
        file_r >> array[counter];  // read the key
    }
    
    modified_quicksort(array,0,number-1); // run the modified_quicksort algorithm

    file_w << number << endl;
    for(counter = 0; counter < number; counter++){
        file_w << array[counter] << endl; //  the sorted key to the output file
    }
    delete [] array;
    return 0;
}


void modified_quicksort(int A[], int p, int r) {
    limited_quicksort(A, p, r, K);
    insertion_sort(A, p, r+1);
}

void limited_quicksort(int A[], int p, int r, int treshold) {
    if (r - p > treshold) {
        int q = partition(A, p, r);
        limited_quicksort(A, p, q, treshold);
        limited_quicksort(A, q + 1, r, treshold);
    }
}

int partition(int A[], int p, int r) {
    int x, i, j, tmp;

    x = A[r - 1];
    i = p;

    for (j = p; j < r - 1; j++) {
        if (A[j] <= x) {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }

    tmp = A[i];
    A[i] = A[r - 1];
    A[r - 1] = tmp;

    return i;
}

void insertion_sort(int A[], int p, int r) {
    int i, j, key;

    for (j = p + 1; j < r; j++) {
        key = A[j];
        for (i = j - 1; i >= p && A[i] > key; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1] = key;
    }
}