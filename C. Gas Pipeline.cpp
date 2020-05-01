#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
ll a , pipe, pillar , k ;
string s1 ;
ll dp[200005][3],vis[200005][3];
ll fun(ll indx , ll pre)
{
    if(indx==a) return 0 ;
    ll &ret1 = dp[indx][pre];
    ll &v = vis[indx][pre];
    if(v==k) return ret1 ;
    v=k;
    ret1 = LLONG_MAX;
    if(pre==0 && s1[indx]=='0' ) ret1 = pipe+pillar+fun(indx+1,0);
    if(pre==0 && s1[indx]=='1' ) ret1 = pipe+pillar+pipe+pillar+pillar+fun(indx+1,1);
    if(pre==1 && s1[indx]=='1' ) ret1 = pipe+pillar+pillar+fun(indx+1,1);
    if(pre==1 && s1[indx]=='0' )
    {
        if(indx+1!=a)ret1 = pipe+pillar+pillar+fun(indx+1,1);
        ret1 = min(ret1,pipe+pipe+pillar+fun(indx+1,0));
    }
    return ret1 ;
}
int main()
{
    CIN;
    ll  d,e,f,i,j,T;
    cin >> T ;
    while(T--)
    {
        k++;
        cin >> a >> pipe >> pillar >> s1 ;
        cout<<pillar+fun(0,0)<<endl;
    }
    return 0 ;
}
https://codeforces.com/contest/1207/problem/C
