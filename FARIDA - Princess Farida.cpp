#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

ll a ,dp[10004],vis[10004],ara[10004],k;
ll fun( ll pos )
{
    if(pos>=a) return 0;
    ll &ret1 = dp[pos];
    ll &v = vis[pos];
    if(v==k) return ret1;
    v=k;
    ret1 = ara[pos]+fun(pos+2);
    ret1 = max(ret1,fun(pos+1));
    return ret1 ;
}
int main()
{
    ll  i,T;
    scanf("%lld",&T);
    while(T--)
    {
        k++;
        scanf("%lld",&a);
        for( i = 0 ; i < a ; i++)
        {
            scanf("%lld",&ara[i]);
        }
        printf("Case %lld: %lld\n",k,fun(0));
    }
    return 0 ;
}
//https://www.spoj.com/problems/FARIDA/
