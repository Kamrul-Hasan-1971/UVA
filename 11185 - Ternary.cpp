#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back
#define         output             freopen("output.txt","wt", stdout)

vector<ll>v;
int main()
{
    ll a,b,i,c,d,e,f,g,mn,j;
    for(j=1;j<=100;j++)
    {
        scanf("%lld", &a);
        if(a<0) break;
        while(1)
        {
            b=a%3;
            v.pb(b);
            a=a/3;
            if(a==0){
                break;
            }
        }
        for(i=v.size()-1;i>=0;i--){
            printf("%lld",v[i]);
        }
        v.clear();
        printf("\n");
    }
    return 0;
}
