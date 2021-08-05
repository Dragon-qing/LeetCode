#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> key;
         for(int i=0;i<nums.size()-1;i++){
             if(nums[i]<target)
            for(int j=i+1;j<nums.size();++j){
               if(nums[i]+nums[j]==target){
                    key.push_back(i);
                    key.push_back(j);
                    return key;
               }
            }
        }
    return key;
    }
};