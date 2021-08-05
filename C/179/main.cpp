#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(int a,int b){
        string s1,s2;
        s1=to_string(a);
        s2=to_string(b);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        string s;
        char c[900];
        int itr=0;
        for(int i=0;i<nums.size();++i){
            sort(nums.begin(),nums.end(),cmp);
        }
        for(int i=0;i<nums.size();++i){
            itr+=sprintf(c+itr,"%d",nums[i]);
        }
        if(atoi(c)==0)return "0";
        else{
            return c;
        }
            
    }
};
int main()
{
    vector<int> v={0,0};
    string s;
    Solution a;
    s=a.largestNumber(v);
    cout<<s<<endl<<s.size();
    getchar();
    return 0;
}
