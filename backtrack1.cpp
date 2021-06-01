#include<iostream>
#include<vector>
using namespace std;
int result = 0;

bool isItSafe(int i, int j, int n){
    //we don't go away from the boundary
    return i>=0 and i<n and j>=0 and j<n;
}


void  ratInMaze(vector<vector<int> > &arr, int n, int i,int j,vector<vector<int> > &visited){

    //base case of recursion
    if(arr[n-1][n-1] == 1) return; //destination is block
 
    if(i == n-1 and j == n-1){
        //one possible way
        result++;
        return;
    }

    if(!isItSafe(i,j,n)){
        //out of boundary
        return;
    }

    //self work
    visited[i][j] = 1;

    if(isItSafe(i-1,j,n) && arr[i-1][j] == 0 && visited[i-1][j] == 0){
        //upward
        ratInMaze(arr,n,i-1,j,visited);
    }
    if(isItSafe(i+1,j,n) && arr[i+1][j] == 0 && visited[i+1][j] == 0){
        //down
        ratInMaze(arr,n,i+1,j,visited);
    }
    if(isItSafe(i,j-1,n) && arr[i][j-1] == 0 && visited[i][j-1] == 0){
        //left
        ratInMaze(arr,n,i,j-1,visited);
    }
    if(isItSafe(i,j+1,n) && arr[i][j+1] == 0 && visited[i][j+1] == 0){
        //right
        ratInMaze(arr,n,i,j+1,visited);
    }

    visited[i][j] = 0;
}



int main(){ 
    int n;
    cin>>n;
    vector<vector<int> > arr(n,vector<int>(n,0));
    vector<vector<int> > visited(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    ratInMaze(arr,n,0,0,visited);
    cout<<result<<endl;
    return 0;
}