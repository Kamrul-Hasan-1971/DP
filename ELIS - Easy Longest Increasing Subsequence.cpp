#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define  ll             long long int
string s1 ;
ll dp[12][23],vis[12][23],ara[13],a,k;
ll fun(ll pos,ll pre)
{
    if(pos>=a) return 0;
    ll &ret1 = dp[pos][pre];
    ll &v = vis[pos][pre];
    if(v==k) return  ret1 ;
    v=k;
    ret1 = 0 ;
    if(ara[pos]>pre)
    {
        ret1 = 1+fun(pos+1,ara[pos]);
    }
    ret1 = max(ret1,fun(pos+1,pre));
    return ret1 ;
}
int main()
{
    ll  i,T;
    k++;
    cin>> a ;
    for( i = 0 ; i < a ; i++ ) cin >>ara[i];
    cout<<fun(0,0);
    return 0 ;
}
//https://www.spoj.com/problems/ELIS/
