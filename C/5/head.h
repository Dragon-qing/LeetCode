#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        int maxlen=1;
        string re=s.substr(0,1);
        if(len<2)
            return s;
        for(int i=0;i<len-1;i++){
            int j=i+1;
            string s1=centerspread(s,i,i);
            string s2=centerspread(s,i,j);
            string maxstring;
            if(s1.length()>s2.length()){
                    maxstring=s1;
            }else{
                maxstring=s2;
            }
            if(maxstring.length()>maxlen){
                maxlen=maxstring.length();
                re=maxstring;
            }
        }
        return re;
        
    }
    string centerspread(string s,int left,int right){
        int i=left;
        int j=right;
        int size;
        while(i>=0&&j<s.size()){
            if(s[i]==s[j]){
                i--;
                j++;
            }else{
                break;
            }
        }
        if(j-i-1>0){
            size=j-i-1;
        }else{
            size=1;
        }
        return s.substr(i+1,size);
    }
};