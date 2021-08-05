#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int *n=new int[s.size()+1];
        for(int i=0;i<s.size()+1;++i){
            n[i]=0;
        }
        n[0]=1;
        s=" "+s;
        for(int i=1;i<s.size();++i){
            int a=s[i]-'0';
            int b=(s[i-1]-'0')*10+s[i]-'0';
            if(1<=a&&a<=9){
                n[i]=n[i-1];
            }
            if(10<=b&&b<=26){
                n[i]+=n[i-2];
            }
        }
        return n[s.size()-1];
    }
};
int main(){
    string s="10";
    Solution a;
    cout<<a.numDecodings(s);
    getchar();
    return 0;
}