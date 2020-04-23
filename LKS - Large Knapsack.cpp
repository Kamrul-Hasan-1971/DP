#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

ll a,b,weight[503],item[503];
ll fun()
{
    ll dp[a+2],i , j ;
    memset(dp,0,sizeof dp);
    for( i = 0 ; i< b ; i++ )
    {
        for( j = a ; j>=weight[i] ; j-- )
        {
            dp[j] = max( dp[j] , item[i]+dp[j-weight[i]]);
        }
    }
    return dp[a];
}
int main()
{
    ll  i,T;
    scanf("%lld%lld",&a,&b);
    for( i = 0 ; i <b ; i++)
    {
        scanf("%lld%lld",&item[i],&weight[i]);
    }
    printf("%lld\n",fun());
    return 0 ;
}
