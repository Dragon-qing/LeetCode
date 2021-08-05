#include<iostream>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0)return 0;
        int a=0,b=0,c=0;
        int *arr=new int[n];
        arr[0]=1;
        for(int i=1;i<n;i++){
            int r=arr[a]*2;
            int s=arr[b]*3;
            int t=arr[c]*5;
            arr[i]=min(r,min(s,t));
            if(arr[i]%2==0){
                a++;
            }
            if(arr[i]%3==0){
                b++;
            }
            if(arr[i]%5==0){
                c++;
            }
        }
        return arr[n-1];
    }
};
int main()
{
    int n=1352;
    Solution s;
    cout<<s.nthUglyNumber(n);
    getchar();
    return 0;
}