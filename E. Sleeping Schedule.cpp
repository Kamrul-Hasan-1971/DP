#include<bits/stdc++.h>
using namespace std;
#define           zero(a)            memset(a,-1,sizeof a)

int ara[2005],dp[2005][2005];
int n , h ,l , r ;
int fun(int indx ,int last)
{
    if(indx>=n) return 0 ;
    if(dp[indx][last]!=-1) return dp[indx][last];
    int ret1=0,ret2=0;
    int t1 = (ara[indx]+last)%h;
    int t2 = (ara[indx]-1+last)%h;
    if(t1>=l && t1<=r) ret1=1+fun( indx+1 ,t1);
    else ret1=fun( indx+1 ,t1);
    if(t2>=l && t2<=r) ret2=1+fun( indx+1 ,t2);
    else ret2=fun( indx+1 ,t2);
    return dp[indx][last]=max(ret1,ret2);
}
int main()
{
    zero(dp);
    scanf("%d%d%d%d",&n,&h,&l,&r);
    for(int i = 0 ; i < n ; i++ ) scanf("%d",&ara[i]);
    printf("%d\n",fun(0,0));
    return 0 ;
}
//http://codeforces.com/contest/1324/problem/E
