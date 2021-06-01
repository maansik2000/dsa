#include<iostream>
using namespace std;

int main(){
    int row ,col;
    cin>>row>>col;

//     1
//    1 2
//   1 2 3
//  1 2 3 4
// 1 2 3 4 5

   for(int i=1;i<=row;i++){
       for(int j=1;j<=row-i;j++){
           cout<<" ";
       }
       for(int j=1;j<=i;j++){
           cout<<j<<" ";
       }
       cout<<endl;
   }

//     *****
//    *****
//   *****
//  *****
// *****

   for(int i=1;i<=row;i++){
       for(int j=1;j<=row-i;j++){
           cout<<" ";
       }
       for(int j=1;j<=row;j++){
           cout<<"*";
       }
       cout<<endl;
   }

    //palindromic pattern

//         1
//       2 1 2       
//     3 2 1 2 3     
//   4 3 2 1 2 3 4   
// 5 4 3 2 1 2 3 4 5 

     for(int i=1;i<=row;i++){
         int j;
         for( j=1;j<=row-i;j++){
             cout<<"  ";
         }

         int k = i;

         for(;j<=row;j++){
             cout<<k--<<" ";
         }

         k=2;
         for(;j<=row+i-1;j++){
             cout<<k++<<" ";
         }
         cout<<endl;
     }
    return 0;
}