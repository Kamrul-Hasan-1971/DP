#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define  ll             long long int
pair<ll,ll> ara[1005];
ll L1[1005],L2[1005],sz;
void fun1()
{
    for(ll i = sz-1 ; i>= 0 ; i--)
    {
        ll ans = 0 ;
        for(ll j = i+1 ; j< sz ; j++ )
        {
            if(ara[j].first>=ara[i].first) ans=max(ans,L1[j]);
        }
        L1[i]=ans+1;
    }
}
void fun2()
{
    for(ll i = sz-1 ; i>= 0 ; i--)
    {
        ll ans = 0 ;
        for(ll j = i+1 ; j< sz ; j++ )
        {
            if(ara[j].second>=ara[i].second) ans=max(ans,L2[j]);
        }
        L2[i]=ans+1;
    }
}
int main()
{
    ll T ,  i , a , b , c ;
    cin>>T;
    while(T--)
    {
        memset(L1,0,sizeof L1);
        memset(L2,0,sizeof L1);
        cin >> a ;
        sz=a;
        for( i = 0 ; i < a ; i++) cin >> ara[i].first;
        for( i = 0 ; i < a ; i++) cin >> ara[i].second;
        sort(ara,ara+a);
        fun1();
        fun2();
        ll ans = 0 ;
        for( i = 0 ; i < a ; i++) ans = max(ans,min(L1[i],L2[i]));
        cout<<ans<<endl;
    }
    return 0 ;
}
//https://www.spoj.com/problems/BRIDGE/cstart=30
