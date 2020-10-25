//https://codeforces.com/contest/219/problem/C
#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             int
#define  pb             push_back

string ans,s1;
vector<ll>v1;
ll a,b,dp[500005][32];
ll fun(ll indx, ll last)
{
    if(indx>=a) return dp[indx][last]=0;
    if(dp[indx][last]!=-1) return dp[indx][last];
    ll ret = 10e8;
    for( int i = 0 ; i< b ; i++ )
    {
        if(i==last) continue;
        ret = min(ret,(v1[indx]!=i)+fun(indx+1,i));
    }
    return dp[indx][last]=ret;
}
//complexity(row*col)
void Print(ll indx,ll last)
{
    if(indx>=a) return ;
    ll ret = INT_MAX,temp,nextColor;
    for(ll i = 0 ; i < b ; i++)
    {
        if(i==last) continue;
        temp = (i!=v1[indx])+dp[indx+1][i];
        if(temp<ret)
        {
            ret = temp;
            nextColor =i;
        }
    }
    ans+=(char) nextColor+'A';
    Print(indx+1,nextColor);
}
int main()
{
    CIN;
    cin >> a >> b >>s1;
    for(ll i = 0 ; i < a; i++) v1.pb(s1[i]-'A');
    memset(dp,-1,sizeof dp);
    cout<<fun(0,30)<<endl;
    Print(0,30);
    cout<<ans<<endl;
    return 0 ;
}
