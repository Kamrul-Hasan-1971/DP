#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
ll n, l, r, x, ara[20],vis[1<<16],res;
void call(ll indx,ll mask)
{
    cout<<indx<<" "<<mask<<endl;
    ll mn = 10e9+10, mx = 0, sum = 0, cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(check(mask,i)==1)
        {
            sum += ara[n-i-1];
            mn = min(mn,ara[n-i-1]);
            mx = max(mx,ara[n-i-1]);
            cnt++;
        }
    }
    if(vis[mask]==0 && cnt>=2 && sum>=l && sum <= r && mx-mn>=x ) res++;
    vis[mask]=1;
    if(indx+1<=n && check(mask,indx)==0)
    {
        call(indx+1,Set(mask,indx));
        call(indx+1,mask);
    }
}

int main()
{
    int i, j ;
    scanf("%d%d%d%d",&n, &l,&r, &x);
    for( int i = 0 ; i < n ; i++) scanf("%d",&ara[i]);
    call(0,0);
    printf("%d\n",res);
    return 0;
}
//https://codeforces.com/problemset/problem/550/B
