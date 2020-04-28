#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
#define  min4(a,b,c,d)  min(d,min(a,min(b,c)))
#define  zero(a)        memset(a,-1,sizeof a)
#define  all(v)         v.begin(),v.end()
const ll INF = 100000000000000000;
vector<ll>v1;
vector<string>v3,v2;
string s1;
ll a,chk=0,dp[100005][3][3];

ll fun(ll indx, ll fr , ll sc)
{
    if(indx>=a-1) {chk=1;return 0 ;}
    if(dp[indx][fr][sc]!=-1) return dp[indx][fr][sc];
    ll ret1 = INF , ret2 = INF , ret3 = INF , ret4 = INF;
    if(indx==0){
    if(v2[indx]<=v2[indx+1]) ret1 = fun(indx+1,0,0);
    if(v3[indx]<=v2[indx+1]) ret2 = v1[indx]+fun(indx+1,1,0);
    if(v2[indx]<=v3[indx+1]) ret3 = v1[indx+1]+fun(indx+1,0,1);
    if(v3[indx]<=v3[indx+1]) ret4 = v1[indx]+v1[indx+1]+fun(indx+1,1,1);
    }
    else{
    if(sc==0 && v2[indx]<=v2[indx+1]) ret1 = fun(indx+1,0,0);
    if(sc==1 && v3[indx]<=v2[indx+1]) ret2 = fun(indx+1,1,0);
    if(sc==0 && v2[indx]<=v3[indx+1]) ret3 = v1[indx+1]+fun(indx+1,0,1);
    if(sc==1 && v3[indx]<=v3[indx+1]) ret4 = v1[indx+1]+fun(indx+1,1,1);}
    return dp[indx][fr][sc]=min4(ret1,ret2,ret3,ret4);
}

int main()
{
    CIN;
    ll  b,c,d,e,f,i,j,k,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    zero(dp);
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
    ll x =fun(0,0,0);
    if(chk==0) x = -1;
    cout<<x<<endl;
}
//https://codeforces.com/contest/706/problem/C
