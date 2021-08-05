#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result=0.0;
        vector<int> v;
        int i,j;
        int mid=(nums1.size()+nums2.size())/2;
        for(i=0,j=0;i+j<mid+1;){
            if(i==nums1.size()){
                v.push_back(nums2[j]);
                ++j;
            }else if(j==nums2.size()){
                v.push_back(nums1[i]);
                ++i;
            }else if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        if((nums2.size()+nums1.size())%2==0){
            result=(v[mid]*1.0+v[mid-1])/2;
        }else{
            result=(double)v[mid];
        }
        return result;
    }
};