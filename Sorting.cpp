#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//selection sort
/* complexity :best = Ω(n^2), average = θ(n^2), worst = O(n^2)*/
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//bubble sort
/* complexity : best = Ω(n), average = θ(n^2), worst = O(n^2) */
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

//insertion sort
/* complexity : best = Ω(n log(n)), average = θ(n log(n)), worst = O(n log(n))	*/
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];

        int j = i - 1;
        while (arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

//merge Sort
/* complexity : best = Ω(n log(n)), average = θ(n log(n)), worst = O(n log(n)) */
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

//quick sort
/*complexity : best: Ω(n log(n)), average: θ(n log(n)), worst: O(n^2)*/

int partition (int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = (l - 1);
 
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

void quickSort(int arr[], int l, int r){
    if (l < r){
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

//count sort
void countSort(int arr[], int n){
    int k = arr[0];
    for (int i = 0; i < n;i++){
        k = max(k, arr[i]);   
    }

    int count[10]={0};
    for (int i = 0; i < n;i++){
        count[arr[i]]++;
    }

    for (int i = 1; i <=k;i++){
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0;i--){
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n;i++){
        arr[i] = output[i];
    }
}

//DNF sort or 0 1 2 sort


//print array
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}


int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //selectionSort(arr,n);
    // bubbleSort(arr,n);

    // insertionSort(arr, n);
    // mergeSort(arr, 0, n-1);
    // quickSort(arr, 0, n-1);
    countSort(arr, n);
    printArray(arr, n);

    return 0;
}