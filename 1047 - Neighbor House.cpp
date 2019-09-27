#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           mod              10000007
#define           zero(a)          memset(a,-1,sizeof a)
#define           pii              pair < ll, ll>
#define           pb               push_back
#define           min3(a,b,c)          min(a,min(b,c))

int ara[22][5],n,dp[22][5];

int fun(int pos, int pre )
{
    if(pos==n+1)
        return 0;

    if(dp[pos][pre]!=-1)
        return dp[pos][pre];
    int ret1 = 0, ret2 = 0 ;

    if(pre==1)
    {
        ret1 = ara[pos][pre]+fun(pos+1,2);
        ret2 = ara[pos][pre]+fun(pos+1,3);
    }
    else if(pre==2)
    {
        ret1 = ara[pos][pre]+fun(pos+1,1);
        ret2 = ara[pos][pre]+fun(pos+1,3);
    }
    else if(pre==3)
    {
        ret1 = ara[pos][pre]+fun(pos+1,1);
        ret2 = ara[pos][pre]+fun(pos+1,2);
    }

    return dp[pos][pre] = min(ret1,ret2) ;
}


int main()
{
    int T, i ;
    scanf( "%d",&T );

    for( i = 1 ; i <= T ; i++ )
    {
        zero(dp);
        scanf("%d",&n);

        for(int j = 1 ; j<= n ; j++ )
        {
            for( int k = 1 ; k<= 3 ; k++ )
            {
                scanf("%d",&ara[j][k]);
            }
        }
        int x = min3(fun(1,1),fun(1,2), fun(1,3));
        printf("Case %d: %d\n",i,x);
    }
    return 0;
}

//http://www.lightoj.com/volume_showproblem.php?problem=1047
