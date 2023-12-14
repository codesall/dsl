#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(string str){
    
    stack<char> s;
    for (char c : str) {
        s.push(c);
    }
    string rev;
    while (!s.empty()){
        rev+=s.top();
        s.pop();
    }

    if (str==rev){
        return true;
    }else{
        return false;
    }
}

int main(){
    string str;
    cout<<"Enter string : ";
    cin>>str;
    if (isPalindrome(str)){
        cout<<"Is palindrome";
    }else{
        cout<<"Not Palendrome";
    }
    return 0;
    
}