#include<bits/stdc++.h>
using namespace std;
int a,b,c,dp[4004][4004];
int fun( int len , int cnt)
{
    if( len == 0 ) return cnt ;
    if( len < 0 ) return 0 ;
    int &ret = dp[len][cnt] ;
    if(ret!=-1) return ret ;
    ret = fun( len - a , cnt+1 );
    ret = max(ret,fun( len - b , cnt+1 ));
    ret = max(ret,fun( len - c , cnt+1 ));
    return ret ;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int  n;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    printf("%d\n",fun(n,0));
    return 0 ;
}
//http://codeforces.com/contest/189/problem/A
