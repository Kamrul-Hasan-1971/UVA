#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
#define           ll               long long int


vector<int>v2[2000004];
int ara[2000002];
vector<int>v;
bool prime[2000005];

void findPrime(int n)
{
    for(int i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }


    for(int i=3; i*i<=n; i+=2)
    {
        if(!prime[i])
        {
            for(int j=2; i*j<=n; j++)
            {
                prime[i*j]=true;
            }
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(!prime[i])
        {
            v.push_back(i);
        }
    }
}

ll PrimeFactorization(int a)
{
    ll i,cnt=0,x=a;
    if(prime[a]==0)
    {
        v2[1].push_back(a);
        return 0;
    }
    for(i=0;; i++)
    {
        if(a%v[i]==0)
        {
            while(1)
            {
                if(a%v[i]!=0)
                {
                    break;
                }
                cnt++;
                a=a/v[i];
            }
        }
        if(a==1)
        {
            break;
        }
        if(prime[a]==0)
        {
            cnt++;
            break;
        }
    }
    v2[cnt].push_back(x);
    return 0;
}

int main()
{
    int n,a,b,i,p=1,t=1;
    n=2000002;
    findPrime(n);

    for(i=1; i<=2000000; i++)
    {
        PrimeFactorization(i);
    }

    for(i=1; i<=2000000; i++)
    {
        if(v2[i].size()!=0){
            for(int j=0;j<v2[i].size();j++){
                ara[p]=v2[i][j];
                p++;
            }
        }
    }

    while(1)
    {
        scanf("%lld",&a);
        if(a==0)
        {
            break;
        }
        printf("Case %d: %d\n",t,ara[a]);
        t++;
    }

}
