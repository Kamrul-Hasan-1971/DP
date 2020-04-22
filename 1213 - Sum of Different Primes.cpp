#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int
#define  pb             push_back
bool mark[1500];
vector<ll>prime;
void sieve(ll x)
{
    ll i,j;
    mark[1] = 1;
    for(ll i =4; i<=x; i=i+2)
        mark[i]=1;
    for(i=3; i*i<=x; i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i; j<=x; j+=2*i)
                mark[j]=1;
        }
    }
    prime.pb(2);
    for(i=3; i<=x; i+=2)
    {
        if(mark[i]==0)
            prime.pb(i);
    }
}

ll a, b, x,dp[200][15][1122],vis[200][15][1122],k;
ll fun( ll indx, ll cnt, ll sum)
{
    if(indx>=x || cnt>b || sum>a) return 0;
    ll &ret1=dp[indx][cnt][sum];
    ll &v = vis[indx][cnt][sum];
    if(v==k) return ret1 ;
    v=k;
    ret1=0;
    ret1 += (prime[indx]+sum ==a && cnt==b)?1:0+ fun( indx+1, cnt+1, sum+prime[indx]);
    ret1 += fun( indx+1, cnt, sum ) ;
    return ret1;
}
int main()
{
    sieve(1120);
    x = prime.size();
    ll  c,d,e,f,i,j,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    while(1)
    {
        k++;
        scanf("%lld%lld",&a,&b);
        if(a==0 && b==0) break;
        printf("%lld\n",fun(0,1,0));
    }
    return 0 ;
}
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3654
