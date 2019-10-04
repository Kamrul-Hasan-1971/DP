#include<bits/stdc++.h>
using namespace std;

#define           ll               long long int
#define           mod              100000000
#define           pb               push_back
#define           zero(a)          memset(a,-1,sizeof a)

vector<ll>v;
ll n ;
int dp[18][5000];

ll fun( ll x, ll y )
{
    if (x==n )
    {
        if(y==0 || y%360==0)
        {
            return 1 ;
        }
        else
        {
            return 0;
        }
    }
    if(dp[x][y]!=-1)
        return dp[x][y];

    ll ret1 = 0, ret2 = 0;

    ret1 = fun(x+1,y+v[x]);
    ret2 = fun(x+1,y-v[x]);
    return dp[x][y]=ret1+ret2;
}

int main()
{
    ll i, b ;
    zero(dp);
    cin >> n ;

    for( i = 0 ; i < n ; i++ )
    {
        cin >> b ;
        v.pb(b);
    }

    if(fun(0,0))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0 ;
}
//https://codeforces.com/problemset/problem/1097/B
