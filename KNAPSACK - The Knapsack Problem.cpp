#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define  ll             long long int

ll a,b,ara[2005],val[2005],dp[2005][2005],vis[2005][2005],k;
ll fun(ll pos,ll cap_now)
{
    if(pos>=a) return 0 ;
    ll &ret1 = dp[pos][cap_now] ;
    ll &v= vis[pos][cap_now];
    if(v==k) return ret1 ;
    v=k;
    ret1 = 0 ;
    if(cap_now-ara[pos]>=0) ret1 = val[pos]+fun(pos+1,cap_now-ara[pos]);
    ret1 = max(ret1,fun(pos+1,cap_now));
    return ret1 ;
}
int main()
{
    ll  i,T;
    k++;
    scanf("%lld%lld",&a,&b);
    swap(a,b);
    for( i = 0 ; i <a ; i++)
    {
        scanf("%lld%lld",&ara[i],&val[i]);
    }
    printf("%lld\n",fun(0,b));
    return 0 ;
}
//https://www.spoj.com/problems/KNAPSACK/
