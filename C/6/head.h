#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int*gap=new int[numRows];
        bool flag=true;
        for(int j=0,i=(numRows-1)*2;j<numRows-1;i-=2,j++){
            gap[j]=i;
        }
        gap[numRows-1]=(numRows-1)*2;
        if(numRows==1)gap[0]=1;
        string re;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<s.length();){
                re.push_back(s[j]);
                if(flag){
                    j+=gap[i];
                    flag=false;
                }else{
                    j+=gap[numRows-1-i];
                    flag=true;
                }
            }
            flag=true;
        }
        return re;
    }
};