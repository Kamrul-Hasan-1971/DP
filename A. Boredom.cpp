#include<bits/stdc++.h>
using namespace std;
#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           pb               push_back
#define           all(v)           v.begin(),v.end()
#define           zero(a)          memset(a,-1,sizeof a)

vector<ll>v,v1;
ll ara[100005] , dp[100005];

ll mx ;

ll fun( ll pos )
{
    if(pos>mx)
    {
        return 0;
    }
    if(dp[pos]!=-1) return dp[pos];
    ll ret1 , ret2 ;
    ret1 = fun(pos+2)+(ara[pos]*pos);
    ret2 = fun(pos+1) ;
    return dp[pos]=max(ret1,ret2);
}

int main()
{
    CIN;
    ll a , b , i, j;
    zero(dp);

    cin >> a ;

    for( i = 0 ; i <a ; i++ )
    {
        cin >> b ;
        ara[b]++;
        v.pb(b);
    }

    mx = *max_element(all(v));

    cout<<fun( 1 );

    return 0 ;
}

//https://codeforces.com/problemset/problem/455/A
