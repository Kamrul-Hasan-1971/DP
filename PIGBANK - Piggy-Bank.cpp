#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define  ll             long long int

ll a,c,b,chk,ara[505],wt[505],dp[505][10005],vis[505][10005],k;
ll fun(ll pos,ll cap_now)
{
    if(cap_now<0) return INT_MAX;
    if(cap_now==0) {chk=1;return 0;}
    ll &ret1 = dp[pos][cap_now];
    ll &v = vis[pos][cap_now];
    if(v==k) return ret1 ;
    v=k;
    ret1 = ara[pos]+fun(pos,cap_now-wt[pos]);
    if(pos+1<c) ret1 = min(ret1, fun( pos+1, cap_now )) ;
    return ret1 ;
}
int main()
{
    ll  i,T;
    scanf("%lld",&T);
    while(T--)
    {
        k++;
        chk=0;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll total = b-a;
        for( i = 0 ; i <c ; i++) scanf("%lld%lld",&ara[i],&wt[i]);
        ll ans = fun(0,total);
        if(!chk) printf("This is impossible.");
        else printf("The minimum amount of money in the piggy-bank is %lld.\n",ans);
    }
    return 0 ;
}
//https://www.spoj.com/problems/PIGBANK/cstart=70
