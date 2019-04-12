#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;
int main()
{
    ll a,b,c,d,e,i,j,x,sum;

    cout<<"PERFECTION OUTPUT\n";
    while(1)
    {
        cin>>a;
        if(a==0)
        {
            cout<<"END OF OUTPUT\n";
            return 0;
        }
        b=sqrt(a+1);
        sum=1;
        for(i=1;i<=b;i++){
            if(a%i==0){
                c=a/i;
                if(i==c){
                    c=0;
                }
                sum=sum+i+c;
            }
        }
        sum=sum-a;

        if(sum<a){
            printf("%5lld  DEFICIENT\n",a);
        }
        else if(sum==a){
            printf("%5lld  PERFECT\n",a);
        }
        else{
            printf("%5lld   ABUNDANT\n",a);
        }
    }
    return 0;
}
