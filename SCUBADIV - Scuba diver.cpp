#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int
#define  pb             push_back

ll a, b, c ,dp[1009][24][82],vis[1009][24][82],k;
vector<ll>v1,v2,v3;
ll fun( ll indx, ll oxy , ll nitro)
{
    if(oxy>=a && nitro>=b) return 0;
    if(indx>=c) return INT_MAX;
    if(oxy>=a) oxy=a;
    if(nitro>=b) nitro = b;
    ll &ret1=dp[indx][oxy][nitro];
    ll &v = vis[indx][oxy][nitro];
    if(v==k) return ret1 ;
    v=k;
    ret1=0;
    ret1 = v3[indx] + fun( indx+1, oxy+v1[indx] , nitro+v2[indx]);
    ret1 = min(ret1, fun( indx+1, oxy , nitro )) ;
    return ret1;
}
int main()
{
    ll  d,e,f,i,j,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    scanf("%lld",&T);
    while(T--)
    {
        k++;
        v1.clear();
        v2.clear();
        v3.clear();
        scanf("%lld%lld%lld",&a,&b,&c);
        for( i = 0 ; i < c ; i++)
        {
            scanf("%lld%lld%lld",&d,&e,&f);
            v1.pb(d);
            v2.pb(e);
            v3.pb(f);
        }
        printf("%lld\n",fun(0,0,0));
    }
    return 0 ;
}
//https://www.spoj.com/problems/SCUBADIV/
