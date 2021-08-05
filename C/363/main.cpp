#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int col=matrix[0].size();
        int Max=INT_MIN;
        for(int l=0;l<col;++l){
            int *rowsum=new int[row]{0};
            for(int r=l;r<col;++r){
                for(int i=0;i<row;++i){
                    rowsum[i]+=matrix[i][r];
                }
                Max=max(Max,dpmax(rowsum,k,row));
            }
        }
        return Max;
    }
    int dpmax(int *arr,int k,int n){
        int rollsum=arr[0],rollmax=rollsum;
        for(int i=1;i<n;++i){
            if(rollsum>0){
                rollsum+=arr[i];
            }else {
                rollsum=arr[i];
            }
            if(rollsum>rollmax){
                rollmax=rollsum;
            }
        }
        if(rollmax<=k){
            return rollmax;
        }
        int max=INT_MIN;
        for(int l=0;l<n;++l){
            int sum=0;
            for(int r=l;r<n;++r){
                sum+=arr[r];
                if(sum>max&&sum<=k){
                    max=sum;
                }
                if(max==k)return max;
            }
        }
        return max;
    }
};
int main()
{
    int *rowsum=new int[10]{0};
    for(int i=0;i<10;i++){
        cout<<rowsum[i]<<'\t';
    }
    getchar();
    return 0;
}