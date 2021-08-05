#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        char str[32];
        int re;
        int temp=abs(x);
        int number;
        int i=0;
        int flag=0;
        for(number=1;temp>9;number++){
            temp/=10;
        }
        sprintf(str,"%d",x);
        if(str[i]=='-')
            i=1;
        flag=i;
        for(int j=number-1+i;i<j;i++,j--){
            char t=str[i];
            str[i]=str[j];
            str[j]=t;
        }
        re=atoi(str);
        if((re<0&&x>0)||(re>0&&x<0))
            re=0;
        if(number==10&&str[0+flag]>'3'){
            re=0;
        }
        return re;
    }
};
class Solutionbetter {
public:
    int reverse(int x) {
        long long result = 0;
        while(x != 0 )
        {
            result = result * 10 + (x % 10);
            x = x / 10;
        }
        return result > INT_MAX || result < INT_MIN ? 0:result;
    }
};
int main()
{
    int x=1534236469;
    Solutionbetter s;
    Solution s1;
    // Solution s;
    cout<<s.reverse(x)<<endl;
    cout<<s1.reverse(x)<<endl;
    getchar();
    return 0;
}