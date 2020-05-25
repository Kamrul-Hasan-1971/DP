#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  MX             10e17
ll ara[103][103],dp[103][103],res[103][103],a,b;
ll fun(ll x)
{
    for(ll i = 0 ; i < a ; i++) for(ll j = 0 ; j < b ; j++) dp[i][j]=MX;
    res[0][0]=x;
    if(ara[0][0]>=x) dp[0][0] = ara[0][0]-x;
    for(ll i = 0 ; i < a ; i++){
        for(ll j = 0 ; j < b ; j++)
        {
            res[i][j]=x+i+j;
            if(ara[i][j]<res[i][j]) continue;
            if(i>0) dp[i][j] = min( dp[i][j], dp[i-1][j]+ara[i][j]-res[i][j]);
            if(j>0) dp[i][j] = min( dp[i][j], dp[i][j-1]+ara[i][j]-res[i][j]);
        }
    }
    return dp[a-1][b-1];
}
int main()
{
    CIN;
    ll i,j,T;
    cin>> T ;
    while(T--)
    {
        ll ans = LLONG_MAX;
        cin >> a >> b ;
        for( i = 0 ; i < a ; i++) for( j = 0 ; j < b ; j++) cin >> ara[i][j];
        for( i = 0 ; i < a ; i++) for( j = 0 ; j < b ; j++) ans=min(ans,fun(ara[i][j]-i-j));
        cout<<ans<<endl;
    }
    return 0 ;
}
//https://codeforces.com/contest/1353/problem/F
