#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int ara[13];
int main()
{
    ll a,b,c,d,e,i,j,x,sum;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>b;
        for(j=1; j<=b; j++)
        {
            c=j;
            while(1)
            {
                d=c%10;
                ara[d]++;
                c=c/10;
                if(c==0)
                {
                    break;

                }
            }
        }
        for(j=0; j<9; j++)
        {
            cout<<ara[j]<<" ";
            ara[j]=0;
        }
        cout<<ara[9];
        ara[9]=0;
        cout<<endl;
    }
    return 0;
}
