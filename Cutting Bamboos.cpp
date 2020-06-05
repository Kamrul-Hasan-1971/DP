#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
vector<ll>v1;
ll a ,dp[2002][2002];
ll fun(ll i , ll j ,ll cnt )
{
    if(i>j) return 0 ;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ret1 = (cnt*v1[i])+fun(i+1,j,cnt+1);
    ll ret2 = (cnt*v1[j])+fun(i,j-1,cnt+1);
    return dp[i][j]=min(ret1,ret2);
}

int main()
{
    CIN;
    memset(dp,-1,sizeof dp);
    ll  b,i;
    cin >>a ;
    for( i=0 ; i <a ;i++)
    {
        cin >> b ;
        v1.pb(b);
    }
    cout<<fun(0,a-1,1);
    return 0 ;
}
//https://toph.co/p/cutting-bamboos
