#include<iostream>
#include<climits>

using namespace std;

int partition(int arr[], int l, int r, int k);
void insertion_sort(int *array, int counter, int number);
void swap(int *a, int *b);
int partition(int arr[], int l, int r, int x);
int findMedian(int arr[], int n);
int kthSmallest(int arr[], int l, int r, int k);



// main program, test it
int main()
{
    int arr[] = {12, 3, 8, 7, 4, 19, 26,9,77,68,10,55,23,47};  // test data, you can change by yourself
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "the element in the array : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    int k;
    cout << endl;
    cout << "which 'K' the smallest element do you want to find?"<<endl;
    cin >> k;
    if(k > n) cout << "over the total number of the key"<<endl;
    else if ( k<=0 ) cout <<"wrong input"<<endl;
    else cout << "K'th smallest element is "<< kthSmallest(arr, 0, n-1, k)<< endl;
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

void swap(int *a, int *b) // exchange the key
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// searches for x in arr[l..r], and partitions the array

int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);
    
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// Function to find median of arr[]. 
int findMedian(int arr[], int n)
{
    insertion_sort(arr,0,n);
    return arr[n/2];   // Return middle element
}

// Returns k'th smallest element in arr[l..r] in worst case linear time

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1; // the total keys in array
        
        // Divide arr[] in groups of size 5 and calculate median of every group and store it in median[] array.
        int i;
        int median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }
        
        // using recursive to find median of all medians
        // If median[] has only one element, then no need of recursive call
        int Med;
        
        if(i == 1){
            Med = median[i-1];
        }
        else{
            Med = kthSmallest(median, 0, i-1, i/2);
        }
        
        // Partition the array around a random element and get position of pivot element in sorted array
        int pos = partition(arr, l, r, Med);
        
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    return 0;
}