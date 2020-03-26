#include<bits/stdc++.h>
using namespace std;
int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int n,dp[1<<16],ara[16];
char ara2[16][16];
int call(int mask)
{
    if(mask==(1<<n)-1)return 0;
    if(dp[mask]!=-1) return dp[mask];
    int power,ret1=1<<28;
    for(int i = 0 ; i < n ; i++)
    {
        power = 1 ;
        if(check(mask,i)==0)
        {
            for(int j=0; j<n; j++)if(check(mask,j)) power = max(power,ara2[j][i]-'0');
            int x = ara[i]/power;
            if(ara[i]%power) x++;
            ret1 = min(ret1, x+call(Set(mask,i)));
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
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d",&ara[i]);
        for( i = 0 ; i < n ; i++ ) scanf("%s",&ara2[i]);
        printf("Case %d: %d\n",k,call(0));
    }
    return 0;
}
//http://www.lightoj.com/volume_showproblem.php?problem=1037
