#include<bits/stdc++.h>
using namespace std;

#define           zero(a)            memset(a,-1,sizeof a)

string s1 ;
int dp[103][103];

int fun( int left , int right )
{
    if( left > right ) return 0 ;

    if( dp[left][right]!=-1) return dp[left][right];

    if( s1[left] == s1[right] )
    {
        return dp[left][right] = fun(left+1,right-1);
    }
    else{
        int ret1 = 1 + fun(left+1 ,right );
        int ret2 = 1 + fun(left , right-1);
        return dp[left][right] = min(ret1,ret2);
    }
}


int main()
{
    int  T , i;
    scanf("%d",&T);
    for( i = 1 ; i <= T ; i++ )
    {
        zero(dp);
        cin >> s1 ;
        int len = s1.size();
        int res = fun(0,len-1);
        printf("Case %d: %d\n",i,res);
    }
    return 0 ;
}
