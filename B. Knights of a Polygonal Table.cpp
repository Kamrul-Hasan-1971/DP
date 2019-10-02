#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           pii              pair < ll, ll>
#define           fs               first
#define           scnd             second
#define           pb               push_back
#define           zero(a)              memset(a,-1,sizeof a)
#define           rall(v)        v.rbegin(),v.rend()

vector<ll>v1;
vector<pii>v2;
map<ll,ll>mp;
ll a, b,dp[100005][12];


ll fun(ll pos,ll cnt)
{
    if(pos==a)
        return 0;

    if(dp[pos][cnt]!=-1)
        return dp[pos][cnt];

    ll ret1=0, ret2=0 ;

    if( cnt+1 <= b )
    {
        ret1 = v2[pos].scnd+ fun(pos+1,cnt+1);
    }
    ret2= fun(pos+1,cnt);

    return dp[pos][cnt]=max(ret1,ret2);
}

int main()
{
    CIN;
    ll  c, d, i ;
    zero(dp);
    cin >> a >> b ;
    for( i = 0 ; i < a ; i++ )
    {
        cin >> c ;
        v1.pb(c);
    }
    for( i = 0 ; i < a ; i++ )
    {
        cin >> c ;
        mp[v1[i]]=c;
        v2.pb(pii(v1[i],c));
    }
    sort(rall(v2));
    for( i = 0 ; i < a-1 ; i++ )
    {
        mp[v2[i].fs]+=fun(i+1,0);
    }
    for( i = 0 ; i < a ; i++ )
    {
        cout<<mp[v1[i]]<<" ";
    }
    return 0 ;
}

//https://codeforces.com/contest/994/problem/B
