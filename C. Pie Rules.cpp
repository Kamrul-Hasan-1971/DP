#include<bits/stdc++.h>
using namespace std;
#define    ll   long long int
#define           zero(a)            memset(a,-1,sizeof a)
#define           CIN                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector<ll>v1;
int dp[52][2];
ll a ,tot;
ll fun(ll indx, ll TakeOrNot)
{
    if(indx>=a) return 0;
    if(dp[indx][TakeOrNot]!=-1) return dp[indx][TakeOrNot];
    ll ret1 = v1[indx]+fun( indx+1 , 1 ) ;
    ll ret2 = fun( indx+1 , 0 ) ;
    if(TakeOrNot) dp[indx][TakeOrNot] = min(ret1,ret2);
    else dp[indx][TakeOrNot] = max( ret1 , ret2 );
    return dp[indx][TakeOrNot];
}
int main()
{
    CIN;
    zero(dp);
    ll  b ,i;
    cin >> a ;
    for( i = 0 ; i < a ; i++ )
    {
        cin >> b ;
        tot+=b;
        v1.push_back(b);
    }
    ll x= fun(0,0);
    cout<<tot-x<<" "<<x<<endl;
    return 0 ;
}
//https://codeforces.com/contest/859/problem/C
