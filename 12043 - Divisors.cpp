#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum=0;
ll cnt=0;
ll nod[100002];
ll sod[100002];

void NOD(ll a)
{
    ll limit=sqrt(a);
    for(ll i=1; i<=limit; i++)
    {
        if(!(a%i))
        {
            cnt=cnt+2;
            sum=sum+i;
            sum=sum+(a/i);
        }
    }
    if(limit*limit==a)
    {
        cnt--;
        sum=sum-limit;
    }
}

int main()
{
    ll i,a,b,c,d,sum1=0,sum2=0,f;
    for(i=1;i<=100000;i++){
        NOD(i);
        nod[i]=cnt;
        sod[i]=sum;
        cnt=0;
        sum=0;
    }

    cin>>a;
    while(a--)
    {
        sum1=0;sum2=0;
        cin>>b>>c>>d;
        f=b/d;
        if(b%d!=0){
            f=f+1;
        }
        f=f*d;
        for(i=f;i<=c;i=i+d){
            sum1=sum1+nod[i];
            sum2=sum2+sod[i];
        }
        cout<<sum1<<" "<<sum2<<endl;
    }
    return 0;
}
