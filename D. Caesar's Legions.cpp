#include<bits/stdc++.h>
using namespace std;

#define           ll               long long int
#define           mod              100000000
#define           pb               push_back
#define           zero(a)          memset(a,-1,sizeof a)

ll a , b , c , d ;
ll dp[110][110][12][12];

fun(ll p,ll q , ll m , ll n )
{
    if( p == 0 && q == 0 ) return 1 ;
    if(dp[p][q][m][n]!=-1) return dp[p][q][m][n];
    ll ret1 = 0 , ret2 = 0 ;
    if(m+1<=c && p!=0)
    {
       ret1 = fun(p-1,q,m+1,0)%mod;
    }
    if(n+1<=d && q!=0)
    {
       ret2 = fun(p,q-1,0,n+1)%mod;
    }
    return dp[p][q][m][n]=(ret1+ret2)%mod;
}

int main()
{
    ll  e, f, i, j, k, cnt1 = 0, cnt2 = 0, chk = 0 ;
    zero(dp);
    cin >> a >> b >> c >> d ;
    cout<<fun(a,b,0,0);
    return 0 ;
}
//https://codeforces.com/contest/118/problem/D
