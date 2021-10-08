#include <bits/stdc++.h>
using namespace std;

void reverseSentance(string s){
    stack<string> st;

    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i] !=' ' && i<s.length()){
            word += s[i];
            i++;
        }

        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
}

//permutation of given string
void permute(string s, string ans){
    if(s.length() == 0){
        cout<<ans;
        return;
    }

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string left_subStr = s.substr(0,i);
        string rightSubstr = s.substr(i+1);
        string rest = left_subStr + rightSubstr;

        permute(rest, ans+ch);
    }
}

//if a stirng is rotated or not
bool isRotated(string str, string str1){
    if(str.length() == str1.length()){
        return false;
    }

    if(str.length() < 2){
        return str.compare(str1);
    }

    string clockRot = " ";
    string antiClock = " ";

    int len = str1.length();

    antiClock = antiClock + str1.substr(len-2,2) + str1.substr(0,2);
    
    clockRot = clockRot + str1.substr(2) + str1.substr(0,2);

    return (str.compare(clockRot) == 0 || str.compare(antiClock) == 0);
}

//anagram
bool areAnagram(string str, string str1){
    int n1 = str.length();
    int n2 = str1.length();

    if(n1 != n2){
        return false;
    }

    sort(str.begin(), str.end());
    sort(str1.begin(), str1.end());

    return (str.compare(str1) == 0);
}

//remove duplicates
char* removeDuplicates(char *s, int n){
    unordered_map<char, int > exists;
    int index = 0;
    for(int i=0;i<n;i++){
        if(exists[s[i]] == 0){
            s[index++] = s[i];
            exists[s[i]]++;
        }
    }

    return s;
}

//other method
char *removeDuplicates2(char str[], int n){
    set<char> s (str, str+n-1);

    int i = 0;
    for(auto x:s){
        str[i++] = x;
        str[i] = '\0';
    }

    return str;
}

//implement atoi
int myAtoi(char* str){
    int res = 0;

    for(int i=0;str[i] != '\0';i++){
        res = res * 10 + str[i] - '0';
    }

    return res;
}

//implement longest common prefix
string commonPrefixUntil(string str1, string str2){
    string result;
    int n1 = str1.length();
    int n2 = str2.length();

    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;
        result.push_back(str1[i]);
    }

    return result;
 
}

string commonPrefix (string arr[], int n)
{
    string prefix =  arr[0];
 
    for (int i=1; i<=n-1; i++)
        prefix = commonPrefixUntil(prefix, arr[i]);
 
    return (prefix);
}
 

int main()
{
    string s;
    getline(cin,s);

    reverseSentance(s);

    return 0;
}