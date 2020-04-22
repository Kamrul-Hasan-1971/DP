#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

ll a, b, c ,dp[103][103],vis[103][103],ara[103][103],k;
ll fun( ll x , ll y )
{
    if(x<a && x>=0 && y <b && y>=0 )
    {
        ll &ret1= dp[x][y];
        ll &v=vis[x][y];
        if(v==k) return ret1 ;
        v=k;
        ret1 = 0;
        ret1 = ara[x][y]+fun(x+1,y);
        ret1 = max(ret1, ara[x][y]+fun(x+1,y+1));
        ret1 = max(ret1, ara[x][y]+fun(x+1,y-1));
        if (x==0)ret1 = max(ret1, fun(x,y+1));
        return ret1 ;
    }
    else
    {
        return 0 ;
    }
}
int main()
{
    ll  d,e,f,i,j,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    scanf("%lld",&T);
    while(T--)
    {
        k++;
        scanf("%lld%lld",&a,&b);
        for( i = 0 ; i < a ; i++)
        {
            for( j = 0 ; j < b ; j++ )
            {
                scanf("%lld",&ara[i][j]);
            }
        }
        printf("%lld\n",fun(0,0));
    }
    return 0 ;
}
https://www.spoj.com/problems/BYTESM2//
