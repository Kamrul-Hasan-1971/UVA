#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int
#define  pb             push_back
#define  zero(a)        memset(a,-1,sizeof a)

vector<ll>v1(1005),v2(1005),v3(1005);
ll a, b, n ,dp[1005][22][80];
ll fun( ll indx, ll oxy , ll nitro)
{
    if(oxy>=a && nitro>=b) return 0;
    if(indx==n) return INT_MAX;
    if(oxy>=a) oxy=a;
    if(nitro>=b) nitro = b;
    if(dp[indx][oxy][nitro]!=-1) return dp[indx][oxy][nitro];
    ll ret1 = v3[indx] + fun( indx+1, oxy+v1[indx] , nitro+v2[indx]);
    ll ret2 = fun( indx+1, oxy , nitro ) ;
    return dp[indx][oxy][nitro]=min(ret1,ret2);
}
int main()
{
    ll  i,T;
    scanf("%lld",&T);
    while(T--)
    {
        zero(dp);
        scanf("%lld%lld",&a,&b);
        scanf("%lld",&n);
        for( i = 0 ; i < n ; i++)
        {
            scanf("%lld%lld%lld",&v1[i],&v2[i],&v3[i]);
        }
        ll ans = fun(0,0,0);
        printf("%lld\n",ans);
    }
    return 0 ;
}

