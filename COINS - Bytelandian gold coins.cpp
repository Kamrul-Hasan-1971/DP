#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

map<ll,ll>mp;

ll fun(ll n )
{
    if(n==0) return 0 ;
    if(mp.count(n)) return mp[n] ;
    mp[n] = max( n, fun(n/2)+fun(n/3)+fun(n/4));
    return mp[n];
}

int main()
{
    ll a, b, i, j ;
    while(cin>>a) cout<<fun(a)<<endl;
}
//https://www.spoj.com/problems/COINS/
