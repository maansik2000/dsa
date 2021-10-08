#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 6

void spiralPrint(int m, int n, int arr[R][C]){
    int i,k = 0, l = 0;

    while(k < m && l < n){
        for(int i = l;i< n;i++){
            cout<<arr[k][i]<<" ";
        }
        k++;

        for(i = k;i<m;i++){
            cout<<arr[i][n-1]<<" ";
        }
        n--;
         if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << arr[m - 1][i] << " ";
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << arr[i][l] << " ";
            }
            l++;
        }
    }
}

int main(){
   int a[R][C] = { { 1, 2, 3, 4, 5, 6 },
                    { 7, 8, 9, 10, 11, 12 },
                    { 13, 14, 15, 16, 17, 18 } };
 
    // Function Call
    spiralPrint(R, C, a);
    return 0;
}