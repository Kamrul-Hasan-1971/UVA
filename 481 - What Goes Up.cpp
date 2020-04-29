#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
ll ara[10000006];
int main()
{
    CIN;
    ll  a,b,i=0;
    while(cin>>ara[i]) i++;
    ll sz = i ;
    ll temp[sz+2],res[sz+2],val[sz+2],len=1;
    memset(res,-1,sizeof res);
    val[0]=ara[0];
    temp[0]=0;
    for( i = 1 ; i < sz ; i++)
    {
        ll indx = lower_bound(val,val+len,ara[i])-val;
        if(indx==len) len++;
        val[indx]=ara[i];
        temp[indx]=i;
        if(indx>0) res[i]=temp[indx-1];
    }
    vector<ll>v1;
    ll indx = temp[len-1];
    v1.push_back(ara[indx]);
    while(res[indx]!=-1)
    {
        v1.push_back(ara[res[indx]]);
        indx = res[indx];
    }
    cout<<len<<endl;
    cout<<"-"<<endl;
    while(v1.size())
    {
        cout<<v1.back()<<endl;
        v1.pop_back();
    }
}

