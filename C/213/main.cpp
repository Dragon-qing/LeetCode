#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
       return max(mydp(vector<int>(nums.begin(),nums.end()-1)),mydp(vector<int>(nums.begin()+1,nums.end())));
    }
    int mydp( vector<int> ms){
        int temp;
        int cur=0;
        int pre=0;
        for(int i=0;i<ms.size();++i){
            temp=cur;
            cur=max(cur,pre+ms[i]);
            pre=temp;
        }
        return cur;

    }
};
int main()
{
    vector<int >v={1,3,1,3,100};
    Solution s;
    cout<<s.rob(v);
    getchar();
    return 0;
}