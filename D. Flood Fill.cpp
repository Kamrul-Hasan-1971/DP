#include<bits/stdc++.h>
using namespace std;

#define           CIN                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll                 long long int
#define           zero(a)            memset(a,-1,sizeof a)
#define           pb                 push_back

vector<ll>v1;
ll x,dp[5005][5005];
ll fun( ll left , ll right )
{
    if( left > right ) return 0;
    if(dp[left][right]!=-1) return dp[left][right];
    if(left!=right && v1[left]==v1[right])
        return dp[left][right] =1+fun( left+1, right-1);
    else
    {
        ll ret1 = fun( left+1 , right);
        ll ret2 = fun( left , right-1 );
        return dp[left][right]=max(ret1,ret2);
    }
}
int main()
{
    CIN;
    zero(dp);
    ll a, b, i, pre = -1,mx=0;
    cin >> a ;
    for(i =0 ; i < a ; i++)
    {
        cin >> b ;
        if(b!=pre) v1.pb(b);
        pre = b;
    }
    x = v1.size();
    b = fun(0,x-1);
    x-=(b*2);
    cout<<x-1+b<<endl;
    return 0 ;
}
//https://codeforces.com/problemset/problem/1114/D
