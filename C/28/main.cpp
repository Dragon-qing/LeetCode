#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int first;
        int second=0;
        int temp;
        int len1=haystack.size();
        int len2=needle.size();
        if(len2==0){
            return 0;
        }
        for(first=0;first<len1;first++){   
            temp=first;     
            while(haystack[temp]==needle[second]&&temp<len1){
                if(second==len2-1){
                    return first;
                }
                ++temp;
                ++second;
            }
            second=0;
        }
        return -1;
    }
};
int main()
{
    getchar();
    return 0;
}