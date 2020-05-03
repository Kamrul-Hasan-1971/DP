#include<bits/stdc++.h>
using namespace std;
#define           ll        long long int
#define           MX        5005

ll ara[MX],sum[MX],k,r,lim,m,dp[MX][MX],cnt1;
ll fun( ll indx , ll cnt )
{
    if(cnt==k) return 0 ;
    if(indx>lim) return LLONG_MIN ;
    if(dp[indx][cnt]!=-1) return dp[indx][cnt];
    ll ret1 = 0 ;
    ret1 = sum[indx]+fun(indx+m,cnt+1);
    ret1 = max(ret1,fun(indx+1,cnt));
    return dp[indx][cnt]=ret1 ;
}

int main()
{
    ll i , n ;
    memset(dp,-1,sizeof dp);
    scanf("%lld%lld%lld",&n,&m,&k);
    for( i = 1 ; i <= n ; i++ ) scanf("%lld",&ara[i]);
    for( i = 1 ; i <= n ; i++ ) ara[i] += ara[i-1];
    lim= n-m+1;
    for( i = 1 ; i <= lim ; i++ ) sum[i] = ara[i+m-1]-ara[i-1];
    printf("%lld\n",fun(1,0));
    return 0 ;
}
//https://codeforces.com/contest/467/problem/C
