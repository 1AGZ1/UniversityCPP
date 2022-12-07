#include <iostream>

using namespace std;

int n;

//
int partition(float arr[], int start, int end){
    // POINTER TO START OF ARR
    int pivot = arr[start];
 
    
    int count = 0;
    for (int i = start + 1; i < end + 1; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 

    int pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

//QUICKSORT
void quickSort(float arr[], int start, int end)-{
 
    if (start >= end)
        return;
 
    int p = partition(arr, start, end);
 
    quickSort(arr, start, p - 1);
 
    quickSort(arr, p + 1, end);
}

//INIT ARR
float* new_arr(){
    cout<<"Enter N as number of elements in array b: "<<endl;
    cin>>n;

    return (new float [n-1]);
}

//PRINT ARR
void ptint_arr(const float* arr){
    cout<<"##############################\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<"\n##############################\n";
}

int main(){
    float* b = new_arr();

    for(int i = 0; i < n; i++){
        cout<<"Enter \""<<i+1<<"\" element of array b:"<<endl;
        cin>>b[i];
    }

    quickSort(b, 0, n - 1);
 
    ptint_arr(b);
 
 	system("pause");
    return 0;
}
