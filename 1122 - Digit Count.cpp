#include<bits/stdc++.h>
using namespace std;

#define           zero(a)            memset(a,-1,sizeof a)
#define           pb                 push_back

vector<int>v;
int m, n;
int dp[12][12];

int fun( int baki,int pre)
{

    if( baki == 0 ) return 1;
    if( dp[baki][pre] != -1 ) return dp[baki][pre];
    if(baki>0 )
    {
        int ret2 = 0 ;
        for(int i = 0 ; i <m ; i++)
        {
            if(abs(v[i]-pre)<3)
            {
                ret2 += fun(baki-1,v[i]);
            }
        }
        return dp[baki][pre]= ret2 ;
    }
}


int main()
{
    int  T, i, inp, j,res ;
    scanf("%d",&T);
    for( i = 1 ; i <= T ; i++ )
    {
        res = 0 ;
        zero(dp);
        v.clear();

        scanf("%d %d",&m,&n);

        for( j = 0 ; j < m ; j++ )
        {
            scanf("%d",&inp);
            v.pb(inp);
        }

        for( j = 0 ; j < m ; j++)
        {
            res += fun(n-1,v[j]) ;
        }

        printf("Case %d: %d\n",i,res);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1122
