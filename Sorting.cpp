#include<iostream>
using namespace std;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


//selection sort
void selectionSort(int arr[], int n){

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }

    }
} 


//bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}


//insertion sort
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int current = arr[i];

        int j = i-1;
        while(arr[j]>current){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }
}

//print array
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //selectionSort(arr,n);
    // bubbleSort(arr,n);

    insertionSort(arr, n);
    printArray( arr, n);

    return 0;
}