#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define  ll             long long int
string s1 ;
ll dp[6105][6105],vis[6105][6105],k,sz;
ll fun(ll x,ll y)
{
    if(x>=y || x>=sz || y<0) return 0;
    ll &ret1 = dp[x][y];
    ll &v = vis[x][y];
    if(v==k) return ret1;
    v=k;
    ret1 = INT_MAX ;
    if(s1[x]==s1[y])
    {
        ret1 = fun(x+1,y-1);
    }
    else
    {
        ret1 =  min( ret1 , 1+fun(x+1,y));
        ret1 =  min( ret1 , 1+fun(x,y-1));
    }
    return ret1 ;
}
int main()
{
    ll  i,T;
    scanf("%lld",&T);
    while(T--)
    {
        k++;
        cin >> s1 ;
        sz = s1.size();
        cout<<fun(0,sz-1)<<endl;;
    }
    return 0 ;
}
//https://www.spoj.com/problems/AIBOHP/cstart=50
