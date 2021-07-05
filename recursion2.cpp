#include <bits/stdc++.h>
using namespace std;

//remove duplicates
void moveAtEnd(string s, int i, int l){
    if(i >= l){
        return ;
    }

    char curr = s[i];

    if(curr != 'x'){
        cout<<curr;
    } 

    moveAtEnd(s,i+1, l);

    if(curr == 'x'){
        cout<<curr;
    }

    return ;
}

//move all x to the end
string moveallX(string s){
    if(s.length() == 0){
        return "";
    }

    char ch = s[0];
    string ans = moveallX(s.substr(1));

    if(ch == 'x'){
        return ans + ch;
    }
    return ch+ans;
} 

//print al


int main(){
    string s = "geekxsforgexxeksxx";
    int l = s.length();

    moveAtEnd(s,0 ,l); 
    return 0;
}