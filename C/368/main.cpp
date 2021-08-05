#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int *f=new int [n]{0};
        int *g=new int [n]{0};
        for(int i=0;i<n;i++){
            int len=1,prev=i;
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    if(f[j]+1>len){
                        len=f[j]+1;
                        prev=j;
                    }
                }
            }
            f[i]=len;
            g[i]=prev;
        }
        int max=-1,ind=-1;
        for(int i=0;i<n;i++){
            if(max<f[i]){
                max=f[i];
                ind=i;
            }
        }
        vector<int>v;
        while(v.size()!=max){
            v.push_back(nums[ind]);
            ind=g[ind];
        }
    }
};