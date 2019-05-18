#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back
#define           pii              pair < ll, ll>

vector<ll>v;
int main()
{
    ll test=64,N,E,a,b=1,i,x;
    while(test--)
    {
        cin>>N>>E;
        if(N==0 && E==0){
            break;
        }
        for(i=0; i<N; i++)
        {
            scanf("%lld", &a);
            v.pb(a);
        }
        sort(v.begin(),v.end());
        printf("CASE# %lld:\n",b);
        for(i=0;i<E;i++){
            scanf("%lld",&a);
            x=lower_bound(v.begin(),v.end(),a)-v.begin();
            if(x<N && v[x]==a){
                printf("%lld found at %lld\n",a,x+1);
            }
            else{
                printf("%lld not found\n",a);
            }
        }
        v.clear();
        b++;
    }
    return 0;
}
