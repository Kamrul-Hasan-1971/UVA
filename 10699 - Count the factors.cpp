#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

vector<int>v;
bool prime[100005];

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


int PrimeFactorization(int a)
{
    int cnt=0,n;

    for(int i =0;v[i]*v[i]<=a;i++)
    {
        n=v[i];
        if((a%n)==0){
            cnt++;
        while(a%n==0){
            a=a/n;
        }
        }
    }
    if(a!=1){
        cnt++;
    }
    return cnt;
}

int main()
{
    int n,a,b,p;
    n=100002;
    findPrime(n);

    while(1)
    {
        scanf("%d",&a);
        if(a==0){
            break;
        }
        p=PrimeFactorization(a);
        printf("%d : %d\n",a,p);
    }
    return 0;
}
