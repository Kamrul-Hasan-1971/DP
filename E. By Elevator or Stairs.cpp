#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           zero(a)            memset(a,-1,sizeof a)

ll n , c  ,stair[200005],elevator[200005] ,dp[200005][4];

ll fun(ll i , ll id )
{
    if(i<0) return 0 ;
    if(dp[i][id]!=-1) return dp[i][id];
    ll ret1 , ret2 = c;
    ret1 = stair[i]+fun( i-1 , 1 );
    if(id==2) ret2 = 0 ;
    ret2 += elevator[i]+fun( i-1 , 2 );
    return dp[i][id]=min(ret1,ret2);
}

int main()
{
    ll i , inp ;
    zero(dp);
    scanf("%lld%lld",&n , &c );
    n--;
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%lld",&stair[i]);
    }
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%lld",&elevator[i]);
    }
    fun( n-1 , 1 );
    printf("0 ");
    for( i = 0 ; i < n ; i++ )
    {
        printf("%lld ",dp[i][1]);
    }
    return 0 ;
}
//http://codeforces.com/contest/1249/problem/E
