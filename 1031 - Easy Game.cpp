#include<bits/stdc++.h>
using namespace std;
 
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  mn             -100000000
ll ara[102],dp[102][102],tc,vis[102][102];
ll fun(ll i , ll j )
{
    if(i>j ) return 0 ;
    ll &ret1 = dp[i][j];
    ll &v = vis[i][j];
    if(v==tc) return ret1 ;
    v=tc;
    ll sum = 0 , gap = mn;
    for( ll k = i ; k <= j ; k++ )
    {
        sum+=ara[k];
        gap = max(gap,sum-fun(k+1,j));
    }
    sum = 0;
    for( ll k = j ; k >= i ; k-- )
    {
        sum+=ara[k];
        gap = max(gap,sum-fun(i,k-1));
    }
    return ret1=gap ;
 
}
int main()
{
    CIN;
    ll a,i,T;
    cin>> T ;
    while(T--)
    {
        tc++;
        cin >> a ;
        for( i= 1 ; i <= a ; i++) cin >> ara[i];
        ll ans = fun(1,a);
        printf("Case %lld: %lld\n",tc,ans);
    }
    return 0 ;
}
