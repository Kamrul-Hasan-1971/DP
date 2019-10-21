#include<bits/stdc++.h>
using namespace std;

#define           ll                 long long int
#define           pb                 push_back
#define           zero(a)            memset(a,-1,sizeof a)

char s1[70] ;
ll dp[65][65];
ll fun( ll i, ll j )
{
    if( i > j ) return 0 ;
    if( i == j ) return 1 ;
    if( dp[i][j] != -1 ) return dp[i][j];
    ll ret1 = 0 ;
    if( s1[i] == s1[j] )  ret1 = 1 + fun( i+1, j )+fun( i, j-1 ) ;
    else  ret1 = fun( i+1, j ) + fun( i, j-1 ) - fun( i+1, j-1 ) ;
    return dp[i][j] = ret1 ;
}

int main()
{
    ll  T ;
    scanf("%lld",&T);
    for( ll i = 1 ; i <= T ; i++ )
    {
        zero(dp);
        scanf("%s",s1);
        ll len = strlen(s1);
        ll p = fun( 0, len-1 );
        printf("Case %lld: %lld\n",i,p);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1025
