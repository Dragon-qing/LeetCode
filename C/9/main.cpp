#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    string s = to_string(x);
    string temp(s.rbegin(), s.rend());
    cout<<temp<<endl;
    if(s==temp){
        return true;
    }
    return false;
}
int main(){
    cout<<isPalindrome(123);
    return 0;
}