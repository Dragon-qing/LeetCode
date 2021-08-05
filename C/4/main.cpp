#include"head.h"
#include<iomanip>
int main(){
    Solution s;
    vector<int>v1={100001},v2={100000};
    double d=s.findMedianSortedArrays(v1,v2);
    double d2=100000.5;
    cout<<fixed<<setprecision(3)<<d2<<endl;
    getchar();
    return 0;
}