#include<bits/stdc++.h>
using namespace std;
int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int reset(int N,int pos){return N= N & ~(1<<pos);}
string s1 ;
int n,dp[1<<15],ara[15][15];
int call(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int price,ret1=1<<28;
    for(int j = 0 ; j < n ; j++)
    {
        if(check(mask,j)==0)
        {
            price = ara[j][j];
            for(int i=0; i<n; i++) if(check(mask,i)) price+=ara[j][i];
            ret1=min(ret1,price+call(Set(mask,j)));
        }
    }
    return dp[mask]=ret1;
}
int main()
{
    int T, i,j, k;
    scanf("%d",&T);
    for( int k = 1 ; k <= T ; k++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=0; i<n; i++) for(j=0;j <n ;j++)scanf("%d",&ara[i][j]);
        printf("Case %d: %d\n",k,call(0));
    }
    return 0;
}
//http://www.lightoj.com/volume_showproblem.php?problem=1119
