#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
    
        node(int val){
            data = val;
            next = NULL;
        }
};

class tree{
    public:
    int data;
    tree* left;
    tree* right;

    tree(int val){
        data = val;
        left = right = NULL;
    }
};

//palindrome
bool palindrome(string s){
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    bool flag = false;

    for(int i=0;i<s.length();i++){
        if(s1[i] != s2[i]){
            flag = false;
            break;
        }

        flag = true;
    }

    return flag;
}

//remove character
string removeCharacter(string s, string character){
    int n = s.length();

    string ans = "";

    for(int i=0;i<n;i++){
        if(s[i] != character[0]){
            ans = ans + s[i];
        }
    }

    return ans;
}

//reverse a number
int reverseNumber(int n){
    string s = to_string(n);

    reverse(s.begin(), s.end());

    int n2 = stoi(s);

    return n2;
}


//prime factor of given number
void primefactor(int n){
    while(n % 2 == 0) {
        cout<<2<<" ";
        n = n/2;
    }

    for(int i = 3;i <= sqrt(n);i = i + 2){
        while(n % i == 0){
            cout<<i<<" ";
            n = n/i;
        }
    }

    if(n>2){
        cout<<n<<" ";
    }
}

//gcd or hcf of two number
int gcd(int a , int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

//lcm of two number
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

//sum of number
int sumOfNumber(int n){
    int sum = 0, rem = 0;
    while(n){   
        rem = n % 10;
        sum = sum + rem;
        n = n / 10;
    }

    return sum;
}

//sum of number using recursion
int sumOfNumberUsingRecursion(int n){
    int sum = 0;

    if(n == 0){
        return 0;
    }

    return n % 10 + sumOfNumberUsingRecursion(n/10);
}

//sum in range
int sumInRange(int n, int m){
    int sum = 0;
    for(int i=n;i<=m;i++){
        sum = sum + i;
    }

    return sum;
}

//perfect number
void perfectNumber(int n){
    int sum = 0;

    for(int i=1;i<n;i++){
        if(n%i == 0){
            sum = sum + i;
        }
    }

    if(n == sum){
        cout<<"perfect Number";
    }else{
        cout<<"non perfect Number";
    }
}

int fac(int n){

    if(n == 1){
        return 1;
    }

    return n*fac(n-1);
}

//strong number or not
void strongNumber(int n){
    int sum = 0, rem, temp = n;

    while(n){
        rem = n % 10;
        sum = sum + fac(rem);
        n = n / 10;
    }

    if(temp == sum){
        cout<<"strong number";
    }else{
        cout<<"It is not strong number";
    }
}

//automorphic number
void automorphicNumber(int n){
    int num;

    num = pow(n, 2);

    if(n == num % 10 ){
        cout<<"valid Input";
    }else{
        cout<<"invalid number";
    }
}

//harshad number
void harshadNumber(int n){
    int sum = 0, temp = n, rem;

    while(n){
        rem = n % 10;
        sum = sum + rem;
        n = n / 10;
    }


    if(temp % sum == 0){
        cout<<"harshad number";
    }else{
        cout<<"not a harshad number";
    }
}

int countPalindrome(string str){
    str = str + " ";

    string word = "";

    int count = 0;

    for(int i=0;i<str.length();i++){
        char ch = str[i];

        if(ch != ' '){
            word = word + ch;
        }else{
           
            if(palindrome(word)){
                count++;
           
            }
            word = "";
            
        }
    }

    return count;
}

bool areRotations(string str1, string str2){
    if(str1.length() != str2.length())
        return false;
    
    string temp = str1 + str2;

    return (temp.find(str2) != string::npos);
}

void printReverseOfstring(string s){
    if(s.length() == 0){
        return ;
    }

    printReverseOfstring(s.substr(1));
    cout<<s[0];
}

void occurenceOfNumber(string s){
    map<char, int> occurance;
    int n = s.length();

    for(int i = 0;i<n;i++){
        occurance[s[i]]++;
    }

    for(auto s : occurance){
        cout<<s.first<<" "<<s.second<<endl;
    }
} 

//reverse a string in the sentence
void reverseString(string s){
    string word="";
    int count = 0;

    stack<string> temp;

    int n = s.length();

    for(int i=0;i<n;i++){
        if(s[i] != ' '){
            word = word + s[i];
        }else{
            temp.push(word);
            count++;
            word = "";
        }
    }

    temp.push(word);

    while(!temp.empty()){
        string ans = temp.top();
        cout<<ans<<" ";
        temp.pop();
    }
}


node* reverseLinkedList(node* &head){
    node* prev = NULL;
    node* currPtr = head;
    node* nextPtr;

    while(currPtr != NULL){
        nextPtr = currPtr -> next;
        currPtr -> next = prev;

        prev = currPtr;
        currPtr = nextPtr;
    }

    return prev;
}

void unionOfArray(int arr1[], int arr2[], int n, int n1){
    map<int, int> mp;

    for(int i = 0;i < n;i++){
        mp[arr1[i]]++;
    }

    for(int i = 0;i < n1;i++){
        mp[arr2[i]]++;
    }

    //union of two array
    for(auto i : mp){
        cout<<
    }
}

int main(){
    string n;
    getline(cin, n);
    reverseString(n);
    return 0;
}

