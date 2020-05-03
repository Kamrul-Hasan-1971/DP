#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  mx4            1000005
#define  MOD            1000000007
ll n , k , d , dp[202][3],vis[202][3] , r ;
ll fun( ll sum , ll chk)
{
    if(sum==n && chk ) return 1 ;
    if( sum>= n ) return 0 ;
    ll &ret1 = dp[sum][chk] ;
    ll &v = vis[sum][chk];
    if(v==r) return ret1 ;
    v=r;
    ret1 = 0 ;
    for(int i = 1 ; i <= k ; i++ )
    {
        if(i>=d) ret1 +=(fun(sum+i,1)%MOD);
        else ret1+=(fun(sum+i,chk)%MOD);
        ret1%=MOD;
    }
    return ret1 ;
}
int main()
{
    CIN;
    ll  a,b,c,e,f,i,j,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    r++;
    cin >> n >> k >> d ;
    cout<<fun(0,0)<<endl;
    return 0 ;
}
//https://codeforces.com/contest/431/problem/C
