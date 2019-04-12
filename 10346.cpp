#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int ara[13];
int main()
{
    ll a,b,c,d,e,i,j,x,sum;
    while(cin>>a>>b)
    {
        e=a;
        while(1)
        {
            d=a/b;
            e=e+d;
            a=(a-(d*b))+d;
            if(a<b){
                break;
            }
        }
        cout<<e<<endl;
    }
    return 0;
}
