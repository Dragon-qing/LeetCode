#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int Max(int x,int y){
        return x>y?x:y;
    }
    int lengthOfLongestSubstring(string s) {
        int prev=0,end=0;
        int max=0;
        map<char,int>m;
        while(end<s.length()){
            if(m[s[end]]>prev){
                prev=m[s[end]];
            }
            max=Max(max,end-prev+1);
            m[s[end]]=end+1;
            end++;
        }
        return max;
    }
};