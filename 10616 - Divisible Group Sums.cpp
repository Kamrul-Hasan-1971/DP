#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
ll ara[205],a,d,dp[205][12][22],vis[205][12][22],k,c;
ll fun(ll indx , ll cnt ,ll sum)
{

    if(cnt==d)
    {
        if(sum%c==0) return 1;
        return 0 ;
    }
    if(indx>=a) return 0;
    ll &ret1 = dp[indx][cnt][sum];
    ll &v = vis[indx][cnt][sum];
    if(v==k) return ret1 ;
    v=k;
    ret1 = 0 ;
    ll x = (sum+ara[indx])%c;
    if(x<0) x+=c;
    ret1 =fun(indx+1,cnt+1,x);
    ret1 += fun(indx+1,cnt,sum);
    return ret1 ;
}
int main()
{
    CIN;
    ll  b,i,T,s=0;
    while(1)
    {
        k++;
        s++;
        cin >> a >> b ;
        if(a==0&& b==0 ) break;
        for( i = 0 ; i < a ; i++)
        {
            cin >> ara[i];
        }
        cout<<"SET "<<s<<":"<<endl;
        for( i = 1 ; i <= b ; i++)
        {
            cin>> c >> d;
            k++;
            ll x = fun(0,0,0);
            cout<<"QUERY "<<i<<": "<<x<<endl;
        }
    }
    return 0 ;
}
