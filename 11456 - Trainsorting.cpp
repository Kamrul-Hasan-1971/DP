#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int
#define  zero(a)        memset(a,0,sizeof a)

ll ara[2015],a,L1[2015],L2[2015];
void fun1()
{
    int i , j ;
    for( i = a-1 ; i >= 0 ; i--)
    {
        ll ans = 0 ;
        for( j = i+1 ; j<a; j++)
        {
            if(ara[j]>ara[i]) ans = max(ans,L1[j]);
        }
        L1[i]=ans+1;
    }
}
void fun2()
{
    int i , j ;
    for( i = a-1 ; i >= 0 ; i--)
    {
        ll ans = 0 ;
        for( j = i+1 ; j<a; j++)
        {
            if(ara[j]<ara[i]) ans = max(ans,L2[j]);
        }
        L2[i]=ans+1;
    }
}
int main()
{
    ll  i,T;
    cin >> T ;
    while(T--)
    {
        ll ans = 1 ;
        cin >> a ;
        for( i = 0 ; i < a ; i++ ) cin >> ara[i];
        for( i = 0 ; i < a ; i++)
        {
            L1[i]=0;
            L2[i]=0;
        }
        fun1();
        fun2();
        for( i = 0 ; i < a ; i++) ans= max(ans,(L1[i]+L2[i]));
        cout<<ans-1<<endl;
    }
    return 0 ;
}
