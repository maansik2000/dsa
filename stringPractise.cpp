#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


// make it uppercase
void upperCase(string str){

    for(int i=0;i<str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str;
}


//form biggest number
void formBiggestNum(string str){
    
    //sorting in decreasing order
    sort(str.begin(), str.end(), greater<int>());
    cout<<str<<endl;
}


//maximum times a number is occuring
void multipleCharacterOccur(string str){
    int frequency[26];

    for(int i=0;i<26;i++){
        frequency[i] = 0;
    }

    for(int i=0;i<str.length();i++){
        frequency[str[i]-'a']++;
    }

    char ans = 'a';
    int max_F = INT_MIN;

    for(int i=0;i<26;i++){
        if(frequency[i] > max_F){
            max_F = max(max_F, frequency[i]);
            ans = i + 'a';
        }
        
    }

    cout<<max_F<<" "<<ans<<endl;
}


int main(){
    string str;
    cin>>str;

    // string str1 = "46823465";
    
    // upperCase(str);
    // formBiggestNum(str1);
    multipleCharacterOccur(str);
    return 0;
}

