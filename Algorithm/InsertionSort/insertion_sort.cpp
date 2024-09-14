
#include<iostream>
#include<fstream>

using namespace std;

void insertion_sort(int *array, int counter, int number); //insertion_sort function

int main(){
    ifstream file_r; // declare an input object(.txt)
    ofstream file_w; // declare an output object(.txt)
    int counter; 
    int number; // the total number of the keys to be sorted
    file_r.open("nearly sorted random data.txt"); // input file name
    file_w.open("number_sorted_insertion_sort.txt"); // output file name
    file_r >> number;
    int *array = new int[number]; // declare an array to store the keys
    for(counter = 0; counter < number; counter++){
        file_r >> array[counter];   // read the key
    }
    
    insertion_sort(array,counter,number); // run the insertion_sort algorithm

    file_w << number << endl;
    for(counter = 0; counter < number; counter++){
        file_w << array[counter] << endl;  //  the sorted key to the output file
    }
    delete [] array;
    return 0;
}
void insertion_sort(int *array, int counter, int number){
     for(counter = 1; counter < number; counter++){  // run for index 1 to the (number-1)
            int key = array[counter];
            int i = counter - 1;
            while(i >= 0 && array[i] > key){  // compare the value
                  array[i+1] = array[i];
                  i = i - 1;
             }
        array[i+1] = key;
    }
}