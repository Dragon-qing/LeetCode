#include<iostream>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        bool ***dp=new bool**[n];
        for(int i=0;i<n;++i){
            dp[i]=new bool*[n];
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dp[i][j]=new bool[n+1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n+1;++k){
                   dp[i][j][k]=false;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][1]=s1[i]==s2[j];
            }
        }
        
        for(int len=2;len<n+1;len++){
            for(int i=0;i<=n-len;i++){
                for(int j=0;j<=n-len;j++){
                    for(int k=1;k<=len-1;k++){
                        if(dp[i][j][k]&&dp[i+k][j+k][len-k]){
                            dp[i][j][len]=true;
                            break;
                        }
                        if(dp[i][j+len-k][k]&&dp[k+i][j][len-k]){
                            dp[i][j][len]=true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
int main()
{
    string s1="great";
    string s2="rgeat";
    Solution s;
    bool b=s.isScramble(s1,s2);
    cout<<b;
    getchar();
    return 0;
}