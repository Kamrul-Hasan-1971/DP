#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define  ll             long long int
string s1 ,s2;
stringstream ss,ss2 ;
ll dp[22][205],vis[22][205],ara[23],k,sz;
ll fun(ll pos,ll cap_now)
{
    if(pos>=sz) return 0;
    ll &ret1 = dp[pos][cap_now] ;
    ll &v = vis[pos][cap_now];
    if(v==k) return  ret1 ;
    v=k;
    if(cap_now-ara[pos]>=0) ret1 =ara[pos]+fun(pos+1,cap_now-ara[pos]);
    ret1 = max(ret1,fun(pos+1,cap_now));
    return ret1 ;

}
int main()
{
    ll  i,T,a,sum,x;
    cin >> T ;
    while(T--)
    {
        i=sum=0;
        k++;
        s1="";
        while(s1.size()==0) getline(cin,s1);
        ss.clear();
        ss<<s1;
        while(ss>>a){
            ara[i]=a;
            sum+=a;
            i++;
        }
        sz=i;
        if(sum%2==0)
        {
            x=fun(0,sum/2);
            if(x==sum/2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}

