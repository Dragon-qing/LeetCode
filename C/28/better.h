#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        if(n==0){
            return 0;
        }
        int *next=new int[n];
        int i=0,j=0;
        makenext(needle,next,n);
        movenext(next,n);
        while(i<m){
            if(j==n-1&&haystack[i]==needle[j]){
                return i-j;
            }
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j=next[j];
                if(j==-1){
                    i++;
                    j++;
                }
            }
        }
        return -1;
    }
    void makenext(string needle,int *next,int n){
        next[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            if(needle[i]==needle[len]){
                len++;
                next[i]=len;
                i++;
            }else{
                if(len>0){
                    len=next[len-1];
                }
                else{
                    next[i]=len;
                    i++;
                }
            }
        }
    }
    void movenext(int *next,int n){
        for(int i=n-1;i>0;--i){
            next[i]=next[i-1];
        }
        next[0]=-1;
    }
};