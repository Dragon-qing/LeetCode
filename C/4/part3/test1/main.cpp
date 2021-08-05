#include<iostream>
#include<string.h>
using namespace std;
void LCSLength(int m,int n,char*x,char*y,int **c,int **b )
{
    int j,i;
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(i=1;i<=n;i++)
        c[0][i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=3;

            }else {
                c[i][j]=c[i][j-1];
                b[i][j]=2;
            }

        }
}
void LCS(int i,int j,char*x,int **b)
{
    if(i==0||j==0){
        return;
    }
    if(b[i][j]==1){
        LCS(i-1,j-1,x,b);
        cout<<x[i];
    }else if(b[i][j]==2){
        LCS(i,j-1,x,b);
    }else {
        LCS(i-1,j,x,b);
    }
}
int main()
{
    //char x[]={'A','B','C','B','D','B'};
    //char y[]={'A','C','B','B','A','B','D','B','B'};
    char x[]={'A','B','C','B','D','A','B'};
    char y[]={'B','D','C','A','B','A'};
    int m=sizeof(x)/sizeof(x[0]);
    int n=sizeof(y)/sizeof(y[0]);
    int **c,**b;
    c=new int*[m+1];
    for(int i=0;i<=m;i++)
    c[i]=new int [n+1];
    b=new int*[m+1];
    for(int i=0;i<=m;i++)
    b[i]=new int [n+1];
    for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
    {
        b[i][j]=0;
        c[i][j]=0;
    }
    LCSLength(m,n,x,y,c,b);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout<<b[i][j]<<"\t";
        cout<<endl;
    }
    LCS(m,n,x,b);
    cout<<endl;
    system("pause");
    return 0;
}