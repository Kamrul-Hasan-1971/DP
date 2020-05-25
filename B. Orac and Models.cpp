#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
ll n ,i,dp[100005],value[100005];
ll longest( ll u )
{
    if(dp[u]!=-1) return dp[u];
    ll maxi = 0;
    for( ll v = u+u ; v<=n ; v+=u)
        if(value[v]>value[u]) if(longest(v)>maxi) maxi=longest(v);
    dp[u]=1+maxi;
    return dp[u];
}
int main()
{
    CIN;
    ll i,j,T,x,y,b;
    cin>> T ;
    while(T--)
    {
        ll ans = 0 ,x=0;
        cin >> n ;
        for( i = 1 ; i <= n ; i++) dp[i]=-1;
        for( i = 1 ; i <= n ; i++) cin >> value[i];
        for( i = 1 ; i <= n ; i++) ans=max(ans,longest(i));
        cout<<ans<<endl;
    }
    return 0 ;
}
//https://codeforces.com/contest/1350/submission/81383663
