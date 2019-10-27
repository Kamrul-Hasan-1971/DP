#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           zero(a)            memset(a,-1,sizeof a)

ll ara[205][103] , N , dp[205][103] ,lim ;

ll fun(ll i , ll j)
{
    if( i >= lim ) return 0;
    if( dp[i][j]!=-1) return dp[i][j];
    ll ret3 = 0 ;

    if( i < N-1 )
    {
        ll  ret1 = ara[i][j]+fun( i+1 , j ) ;
        ll  ret2 = ara[i][j]+fun( i+1 , j+1 ) ;
        ret3 = max( ret1 , ret2 ) ;
    }
    else
    {
        if( j== 0 )
        {
            ret3 = ara[i][j]+ fun(i+1,j);
        }
        else if( j == lim-i-1 )
        {
            ret3 = ara[i][j] + fun(i+1,j-1);
        }
        else
        {
            ll  ret1 = ara[i][j]+fun( i+1 , j ) ;
            ll  ret2 = ara[i][j]+fun( i+1 , j-1 ) ;
            ret3 = max( ret1 , ret2 ) ;
        }
    }
    return dp[i][j]=ret3 ;
}

int main()
{
    ll T , i , j , k ;

    scanf("%lld",&T);

    for( i = 1 ; i <= T ; i++ )
    {
        zero(dp);
        scanf("%lld",&N);

        for( j = 0 ; j < N ; j++ )
        {
            for( k = 0 ; k <= j ; k++ )
            {
                scanf("%lld",&ara[j][k]);
            }
        }
        lim = (N*2)-1;

        for( j = N ; j < lim ; j++ )
        {
            for( k = 0 ; k < lim-j ; k++ )
            {
                scanf("%lld",&ara[j][k]);
            }
        }
        printf("Case %lld: %lld\n",i,fun(0,0));

    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1004
