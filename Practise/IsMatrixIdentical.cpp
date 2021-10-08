#include<bits/stdc++.h>
using namespace std;
#define N 4

int areSame(int arr[][N], int b[][N]){

    int i,j;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] == b[i][j]){
                return 1;
            }
        }
    }

    return 0;
} 

int main(){
    int A[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
 
    int B[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
 
    if (areSame(A, B))
        cout << "Matrices are identical";
    else
        cout << "Matrices are not identical";
    return 0;
}