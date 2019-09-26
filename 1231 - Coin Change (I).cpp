#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           mod              100000007
#define           zero(a)          memset(a,-1,sizeof a)
#define           pii              pair < ll, ll>
#define           pb               push_back


ll dp[55][55][1005] ;
vector<ll>number,coin;
ll n ;

ll fun(ll pos,ll cnt, ll val)
{
    if(pos==n)
    {
        if(val==0)
            return 1 ;
        return 0 ;
    }
    if(dp[pos][cnt][val]!=-1)
        return dp[pos][cnt][val] ;
    ll ret1 = 0,ret2 ;
    if(val-coin[pos]>=0 && number[pos] >= cnt )
    {
        ret1 = fun( pos, cnt+1, val-coin[pos] ) % mod ;
    }
    ret2 = fun( pos+1, 1, val ) % mod ;

    return dp[pos][cnt][val]=(ret1+ret2) % mod ;
}

int main()
{
    ll T, K, i, j,inp;
    scanf("%lld",&T);
    for( i = 1 ; i <= T ; i++ )
    {
        coin.clear();
        number.clear();
        zero(dp) ;

        scanf("%lld%lld",&n,&K) ;

        for(  j = 0 ; j < n ; j++)
        {
            scanf("%lld",&inp ) ;
            coin.pb(inp) ;
        }
        for(  j = 0 ; j < n ; j++)
        {
            scanf("%lld",&inp ) ;
            number.pb(inp) ;
        }
        ll p = fun( 0, 1, K );
        printf("Case %lld: %lld\n",i, p);
    }
    return 0;
}

//http://www.lightoj.com/volume_showproblem.php?problem=1231
