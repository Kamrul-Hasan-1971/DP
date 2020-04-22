#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define  ll             long long int

ll a,b,ara[1005],dp[1005][1005],vis[1005][1005],k;
ll fun(ll pos,ll cap_now)
{
    if(pos>=a) return 0 ;
    ll &ret1 = dp[pos][cap_now] ;
    ll &v= vis[pos][cap_now];
    if(v==k) return ret1 ;
    v=k;
    ret1 = 0 ;
    if(cap_now-ara[pos]>=0) ret1 = ara[pos]+fun(pos+2,cap_now-ara[pos]);
    ret1 = max(ret1,fun(pos+1,cap_now));
    return ret1 ;
}
int main()
{
    ll  i,T;
    scanf("%lld",&T);
    while(T--){
            k++;
    scanf("%lld%lld",&a,&b);
    for( i = 0 ; i <a ; i++)
    {
        scanf("%lld",&ara[i]);
    }
    printf("Scenario #%lld: %lld\n",k,fun(0,b));
    }
    return 0 ;
}
//https://www.spoj.com/problems/RPLB/
