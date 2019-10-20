#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           pb                 push_back
#define           zero(a)            memset(a,-1,sizeof a)

vector<ll> v1, v2 ;

ll N1, N2, dp[103][103];

ll LCS(ll i, ll j )
{
    if( i >= N1 || j >= N2 )
        return 0 ;

    ll ret1 = 0 ;
    if( dp[i][j]!=-1 )
        return dp[i][j];
    if( v1[i] == v2[j] )
    {
        ret1 = 1 + LCS( i+1, j+1 ) ;
    }
    else
    {
        ll x = LCS( i+1, j ) ;
        ll y = LCS( i, j+1 ) ;
        ret1 = max( x, y ) ;
    }
    return dp[i][j] = ret1 ;
}

int main()
{
    ll cnt = 1, inp ;

    while(scanf("%lld%lld",&N1,&N2)!= EOF )
    {
        zero(dp);
        v1.clear();
        v2.clear();

        if( N1 == 0 && N2 == 0 )
            return 0 ;

        for( int i = 0 ; i < N1 ; i++ )
        {
            cin >> inp ;
            v1.pb( inp ) ;
        }
        for( int i = 0 ; i < N2 ; i++ )
        {
            cin >> inp ;
            v2.pb( inp ) ;
        }

        ll p = LCS( 0, 0 ) ;
        printf("Twin Towers #%lld\n",cnt);
        printf("Number of Tiles : %lld\n\n",p);
        cnt++;
    }
    return 0 ;
}
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1007
