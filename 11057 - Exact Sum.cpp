#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back
#define         output             freopen("output.txt","wt", stdout)

vector<ll>v;

ll binarySearch(ll l, ll r, ll x)
{
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (v[m] == x)
            return m;
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}




int main()
{
    ll a,b,i,c,d,e,f,g,mn;
    while(scanf("%lld", &a)!=EOF)
    {
        f=0;g=0,mn=10000000;
        for(i=0;i<a;i++){
            scanf("%lld", &b);
            v.pb(b);
        }
        sort(v.begin(),v.end());
        scanf("%lld", &c);
        for(i=0;i<a;i++){
            d=c-v[i];
            e=binarySearch(i+1,a,d);
            if(e!=-1 && abs(v[i]-v[e])<mn){
                f=v[i];
                g=v[e];
                mn=abs(f-g);
            }
        }
        printf("Peter should buy books whose prices are %lld and %lld.\n\n",f,g);
        v.clear();
    }
    return 0;
}
