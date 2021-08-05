#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        if(len==0)return 0;
        int left=0,right=len-1;
        for(left=0;left<=right;left++){
            if(nums[left]==val){
                swap(nums[left],nums[right]);
                --right;
                --left;
            }
        }
        return right+1;
    }
    void swap(int &a,int &b){
        int t=a;
        a=b;
        b=t;
    }
};
int main()
{
    Solution s;
    vector<int >v={1};
    int re;
    re=s.removeElement(v,1);
    cout<<re<<endl;
    for(int i=0;i<re;i++)
    {
        cout<<v[i];
    }
    getchar();
    return 0;
}