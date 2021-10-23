#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int left,right;
    left = 0;
    right = height.size()-1;
    int max_area = 0;
    while(left<right){
        max_area = max(min(height[left],height[right])*(right-left), max_area);
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }
    }
    return max_area;
}
int main()
{
    vector<int>a = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(a)<<endl;
    return 0;
}