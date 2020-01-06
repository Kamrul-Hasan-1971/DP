#include<bits/stdc++.h>
using namespace std;

#define           CIN                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll                 long long int
#define           zero(a)            memset(a,-1,sizeof a)
#define           pb                 push_back

vector<ll>v1;
ll dp[101][101][101][3],a;

ll fun(ll idx, ll evenBaki, ll oddBaki, ll parity )
{
    if( idx == a )
        return 0 ;

    ll ret1 =100000, ret2 = 100000 ;
    if(dp[idx][evenBaki][oddBaki][parity]!=-1) return dp[idx][evenBaki][oddBaki][parity];
    if(idx==0)
    {
        if(v1[idx]!=0)
        {
            ret1 = fun( idx + 1, evenBaki, oddBaki, v1[idx]%2 );
        }
        else
        {
            if(evenBaki>0)
            {
                ret1 = fun( idx + 1, evenBaki-1, oddBaki, 0 );
            }
            if(oddBaki>0)
            {
                ret2 = fun( idx + 1, evenBaki, oddBaki-1, 1 );
            }
        }
    }
    else
    {
        if(v1[idx]!=0)
        {
            ll x= v1[idx]%2;
            ret1 =(parity!=x) + fun( idx + 1, evenBaki, oddBaki, v1[idx]%2 );
        }
        else
        {
            if(evenBaki>0)
            {
                ret1 = (parity == 1) + fun( idx + 1, evenBaki-1, oddBaki, 0 );
            }
            if(oddBaki>0)
            {
                ret2 = (parity == 0 ) + fun( idx + 1, evenBaki, oddBaki-1, 1 );
            }

        }
    }
    return dp[idx][evenBaki][oddBaki][parity]=min(ret1,ret2);
}

int main()
{
    CIN;
    ll b,i,bijor=0,jor=0;
    cin >> a ;
    zero(dp);
    for( i =0; i < a ; i++ )
    {
        cin >> b ;
        v1.pb(b);
        if(b==0)continue;
        if(b%2==0)
            jor++ ;
        else
            bijor++;
    }

    ll evenBaki = (a/2)-jor;
    ll oddBaki = (a+1)/2 - bijor ;
    cout<<fun( 0, evenBaki, oddBaki, 0 ) ;
    return 0 ;
}
//https://codeforces.com/contest/1287/problem/C
