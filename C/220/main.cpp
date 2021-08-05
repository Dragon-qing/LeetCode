#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;++i){
            auto itr=s.lower_bound(max(nums[i],INT_MIN+t)-t);
            if(itr!=s.end()&&*itr<=min(nums[i],INT_MAX-t)+t){
                return true;
            }
            s.insert(nums[i]);
            if(i>=k){
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};
int main()
{
    vector<int>v={1,5,9,1,5,9};
    int k=2,t=3;
    bool re;
    Solution s;
    re=s.containsNearbyAlmostDuplicate(v,k,t);
    cout<<re;
    getchar();
    return 0;
}