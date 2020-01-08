#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           mod              10000007
#define           zero(a)          memset(a,-1,sizeof a)
#define           pii              pair < ll, ll>
#define           pb               push_back


vector<ll>price,weight;
ll N ;
ll dp[1005][35] ;

ll fun(ll pos, ll cap_now)
{
    if(pos==N)
        return 0 ;
    ll ret1 = 0 , ret2 = 0 ;

    if( dp[pos][cap_now] != -1 )
        return dp[pos][cap_now] ;

    if( cap_now-weight[pos] >= 0 )
    {
        ret1 = price[pos] + fun( pos+1, cap_now-weight[pos] ) ;
    }

    ret2 = fun( pos+1, cap_now ) ;

    return dp[pos][cap_now] = max(ret1,ret2) ;
}

int main()
{
    ll T ,i ,P ,W ,G ,sum ,j ,MW ;
    scanf("%lld",& T);
    for( i  = 1 ; i <= T ; i++ )
    {
        sum = 0 ;
        price.clear();
        weight.clear();
        zero(dp);
        scanf("%lld",&N);

        for( j = 0 ; j < N ; j++ )
        {
            scanf("%lld%lld",&P,&W);
            price.pb(P);
            weight.pb(W);
        }

        scanf("%lld",&G);

        for( j = 0 ; j < G ; j++ )
        {
            scanf("%lld",&MW) ;
            sum+=fun(0,MW) ;
        }
        printf("%lld\n",sum) ;
    }
    return 0;
}
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1071&mosmsg=Submission+received+with+ID+24399864
