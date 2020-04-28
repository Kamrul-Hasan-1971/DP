#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
#define  all(v)         v.begin(),v.end()
vector<ll>v1;
vector<string>v3,v2;
string s1;
int main()
{
    CIN;
    ll  a,b,i;
    cin >> a ;
    for( i = 0 ; i < a ;i++)
    {
        cin>> b ;
        v1.pb(b);
    }
    for( i = 0 ; i <a ; i++)
    {
        cin >> s1;
        v2.pb(s1);
        reverse(all(s1));
        v3.pb(s1);
    }
    ll dp[a+2][2];
    for( i = 0 ; i <=a ; i++)
    {
        dp[i][0]=1e18;
        dp[i][1]=1e18;
    }
    dp[0][1]=v1[0];
    dp[0][0]=0;
    for( i = 1 ; i< a ; i++)
    {
        if(v2[i]>=v2[i-1]) dp[i][0] = min(dp[i][0],dp[i-1][0]);
        if(v2[i]>=v3[i-1]) dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if(v3[i]>=v2[i-1]) dp[i][1] = min(dp[i][1],dp[i-1][0]+v1[i]);
        if(v3[i]>=v3[i-1]) dp[i][1] = min(dp[i][1],dp[i-1][1]+v1[i]);
    }
    ll x = min(dp[a-1][0],dp[a-1][1]);
    if(x==1e18) x=-1;
    cout<<x<<endl;
}
//https://codeforces.com/contest/706/problem/C
