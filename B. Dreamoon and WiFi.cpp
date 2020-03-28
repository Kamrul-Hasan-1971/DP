#include<bits/stdc++.h>
using namespace std;
string s1, s2 ;
int sum, n,cnt1,cnt2 ;
void fun( int indx, int sum1)
{
    if(indx== n )
    {
        if(sum1==sum) cnt1++;
        else cnt2++;
        return ;
    }
    if(s2[indx]=='?')
    {
        fun( indx+1, sum1+1 );
        fun( indx+1, sum1-1 ) ;
    }
    else
    {
        int x ;
        if(s2[indx]=='+') x = 1 ;
        else x = -1 ;
        fun(indx+1,sum1+x);
    }
}
int main()
{
    int T, i,j;
    cin >> s1 >> s2 ;
    for( i = 0  ; i < s1.size() ; i++)
    {
        if(s1[i]=='+') sum+=1;
        else sum-=1;
    }
    n = s2.size();
    fun(0,0);
    float xx = (double)cnt1/(cnt1+cnt2) ;
    printf("%.12f\n",xx);
    return 0;
}
//https://codeforces.com/contest/476/problem/B
