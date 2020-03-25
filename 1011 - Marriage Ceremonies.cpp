#include<bits/stdc++.h>
using namespace std;
int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int reset(int N,int pos){return N= N & ~(1<<pos);}
string s1 ;
int n,dp[1<<13];
int call(int mask,int indx)
{
    if(dp[mask]!=-1) return dp[mask];
    int ret1=0;
    for(int i=0; i<=10; i++)
    {
        if(check(mask,i)==1 && check(mask,i+1)==1)
        {
            if(i-1>=0 && check(mask,i-1)==0)
                ret1 = max(ret1,1+call((Set(reset(reset(mask,i+1),i),i-1)),1));
            if(i+2<12 && check(mask,i+2)==0)
                ret1 = max(ret1,1+call((Set(reset(reset(mask,i+1),i),i+2)),0));
        }
    }
    return dp[mask]=ret1;
}
int main()
{
    int T, i,j, k;
    scanf("%d",&T);
    for( int k = 1 ; k <= T ; k++)
    {
        int num = 0,cnt1=0;
        memset(dp,-1,sizeof dp);
        cin >> s1 ;
        for(i=0; i<12; i++)
        {
            if(s1[i]=='o')
            {
                num = Set(num,11-i);
                cnt1++;
            }
        }
        printf("%d\n",cnt1-call(num,1));
    }
    return 0;
}
