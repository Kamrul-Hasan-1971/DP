#include<bits/stdc++.h>
using namespace std;
#define  CIN      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector<int>v1;
int a , b ,dp[103][5];
int fun(int indx ,int pre)
{
    if(indx>=a) return 0;
    if(dp[indx][pre]!=-1) return dp[indx][pre];
    int ret1=INT_MAX,ret2=INT_MAX,ret3=INT_MAX;
    if(v1[indx]==0) ret1=1+fun(indx+1,0);
    else if(v1[indx]==1)
    {
        if(pre!=1) ret1 = fun(indx+1,1);
        ret2 = 1+fun(indx+1,0);
    }
    else if(v1[indx]==2)
    {
        if(pre!=2) ret1 = fun(indx+1,2);
        ret2 = 1+fun(indx+1,0);
    }
    else
    {
        if(pre!=1) ret1 = fun(indx+1,1);
        if(pre!=2) ret2 = fun(indx+1,2);
        ret3 = 1+fun(indx+1,0);
    }
    return dp[indx][pre]=min(ret1,min(ret2,ret3));
}
int main()
{
    CIN;
    cin >> a ;
    for(int i = 0 ; i < a; i++)
    {
        cin >> b ;
        v1.push_back(b);
    }
    memset(dp,-1,sizeof dp);
    cout<<fun(0,0)<<endl;
    return 0 ;
}
//https://codeforces.com/contest/698/problem/A
