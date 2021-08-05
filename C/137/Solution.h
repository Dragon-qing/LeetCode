#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <int ,int> m;
        for(int a:nums){
            m[a]++;
        }
        for(auto x:m){
            if(x.second==1)
            return x.first;
        }
        return -1;
    }
};