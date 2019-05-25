#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back
#define           pii              pair<ll,ll>
#define           mx               100
#define         output             freopen("output.txt","wt", stdout)


ll parent[mx];
set<ll>s;

void initialization(ll n)
{
    for(ll i=1; i<=n; i++)
    {
        parent[i]=i;
    }
}


ll findParent(ll x)
{
    if(x != parent[x])
    {
        return parent[x]=findParent(parent[x]);
    }
    else
    {
        return x;
    }
}

void unionSet(ll x,ll y)
{
    ll px= findParent(x);
    ll py= findParent(y);

    if(px!=py)
        parent[py]=px;
}


int main()
{
    ll n,i,test,c,d,e;
    char p[3],r;
    cin>>test;
    for(ll j=0; j<test; j++)
    {
        cin>>r;
        c=r-'A'+1;
        getchar();
        initialization(c);

        while(gets(p))
        {
            if(strlen(p)==0)
                break;
            d=p[0]-'A'+1;
            e=p[1]-'A'+1;
            unionSet(d,e);
        }

        for(i=1; i<=c; i++)
        {
            findParent(i);
        }
        for(i=1; i<=c; i++)
        {
            s.insert(parent[i]);
        }
        cout<<s.size()<<endl;
        if(j!=test-1){
            cout<<endl;
        }
        s.clear();
    }
    return 0;
}
