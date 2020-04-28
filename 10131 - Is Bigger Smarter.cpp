#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
struct data{
    ll wt,iq,indx;
    bool operator <(const data &other) const{
        if (wt==other.wt) return iq>other.iq;
        return wt<other.wt;
    }
}ara[1005];

ll dir[1005];

int main()
{
    CIN;
    ll  a,b,c,d,e,f,i=1,j,k,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    memset(dir,-1,sizeof dir);
    while(scanf("%lld%lld",&ara[i].wt,&ara[i].iq)!=EOF) {
            ara[i].indx=i;
            i++;
    }
    sort(ara+1,ara+i);
    i--;
    ll L[i+4];
    for( j = i ; j >= 1 ; j--)
    {
        ll ans = 0 ;
        for( k = j+1 ; k<=i ; k++)
        {
            if(ara[j].wt<ara[k].wt && ara[k].iq<ara[j].iq)
            {
                if(L[k]>ans)
                {
                    ans=L[k];
                    dir[j]=k;
                }
            }
        }
        L[j]=ans+1;
    }
    ll mx = 0 , id ;
    for( j = 1 ; j<=i ; j++ )
    {
        if(L[j]>mx)
        {
            mx=L[j];
            id = j ;
        }
    }
    cout<<mx<<endl;
    cout<<ara[id].indx<<endl;
    while(dir[id]!=-1)
    {
        cout<<ara[dir[id]].indx<<endl;
        id=dir[id];
    }
    return 0 ;
}
