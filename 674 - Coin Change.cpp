#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           mod              10000007
#define           zero(a)          memset(a,-1,sizeof a)
#define           pii              pair < ll, ll>
#define           pb               push_back


ll dp[6][10000] ;
int coin[] = {50,25,10,5,1};

ll fun(ll pos, ll val)
{
    if(pos==5)
    {
        if(val==0)
            return 1;
        return 0 ;
    }
    if(dp[pos][val]!=-1)
        return dp[pos][val];
    ll ret1 = 0, ret2 ;

    if(val-coin[pos] >= 0 )
    {
        ret1 = fun( pos, val-coin[pos] );
    }
    ret2 = fun( pos+1, val ) ;
    return dp[pos][val] = ret1 + ret2 ;
}

int main()
{
    ll val ;
    zero(dp);
    while(scanf("%lld",&val)!=EOF)
    {
        ll p = fun(0,val);
        printf("%lld\n",p);
    }
    return 0;
}

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615
