#include<bits/stdc++.h>
using namespace std;
const int NX = 30 ;
#define ll long long int
#define pb push_back

ll dp[20][2][2][185];
int vis[20][2][2][185];
int lim, tt ;
vector < int > inp ;

ll DP( int pos, int isSmall,int isStart , int sum )
{
    if( pos == lim )
        return sum ;
    ll &ret1 = dp[pos][isSmall][isStart][sum];
    int &v = vis[pos][isSmall][isStart][sum];
    if( v == tt ) return ret1 ;
    v=tt;
    int i , ses = isSmall ? 9 : inp[pos];
    ret1 = 0 ;
    if( !isStart )
    {
        for ( i = 0 ; i <= ses ; i++ )
        {
            ret1 += DP( pos + 1, isSmall | i < inp[pos],0,sum+i);
        }
    }
    else
    {
        for ( i = 1 ; i <= ses ; i++ )
        {
            ret1 += DP( pos + 1, isSmall | i < inp[pos],0,sum+i);
        }
        ret1 += DP( pos + 1, 1,1,0);
    }
    return ret1 ;
}

ll Cal( ll x )
{
    inp.clear();
    while( x )
    {
        inp.pb(x%10);
        x/=10;
    }
    reverse(inp.begin(),inp.end());
    lim = inp.size();
    tt++;
    return DP( 0, 0, 1 , 0);
}
int main()
{
    for (int cs = 1 ; ; cs++ )
    {

        ll n, m ;
        cin >>n >> m ;
        if(n==-1 && m==-1) break;
        if( n > m ) swap(n,m);
        ll ans = Cal(m)-Cal(n-1) ;
        printf("%lld\n",ans);
    }
    return 0;
}
//https://www.spoj.com/problems/CPCRC1C/
