#include<bits/stdc++.h>
using namespace std;
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int priority[16][16],n,dp[1<<16];
int call(int groom,int mask)
{
    if(mask==(1<<n)-1)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int mx=0;
    for(int i=0; i<n; i++)
        if(check(mask,i)==0)
            mx=max(mx,priority[groom][i]+call(groom+1,Set(mask,i)));
    return dp[mask]=mx;
}
int main()
{
    int T, i,j, k;
    scanf("%d",&T);
    for( int k = 1 ; k <= T ; k++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&priority[i][j]);
        printf("Case %d: %d\n",k,call(0,0));
    }
    return 0;
}
//http://lightoj.com/volume_showproblem.php?problem=1011
