//https://codeforces.com/contest/1433/problem/F
#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

int n,m,k,lim,ara[72][72];
ll dp[72][72][36][72];
ll fun(int r , int c, int take , int sum)
{
    if(r>n)
    {
        if(sum%k) return INT_MIN;
        return 0;
    }
    if(dp[r][c][take][sum]!=-1) return dp[r][c][take][sum];
    ll ret = 0;
    if(c>m || take>=lim) ret+=fun(r+1,1,0,sum);
    else ret = max(fun(r,c+1,take,sum),ara[r][c]+fun(r,c+1,take+1,(sum+ara[r][c])%k));
    return dp[r][c][take][sum]=ret;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    lim = m/2;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&ara[i][j]);
    memset(dp,-1,sizeof dp);
    printf("%lld\n",fun(1,1,0,0));
    return 0 ;
}
