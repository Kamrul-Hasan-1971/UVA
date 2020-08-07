#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  all(a)         a.begin(),a.end()
#define  output         freopen("output.txt","wt", stdout)
int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

ll n,a[32],x;
vector<ll>ans;
void fun(ll pre, ll mask)
{
    if(ans.size()==n && a[ans.back()+1])
    {
        for(ll i = 0 ; i < n-1; i++) cout<<ans[i]<<" ";
        cout<<ans.back()<<endl;
        return ;
    }
    for(ll i = 2 ; i <= n ; i++)
    {
        if(!check(mask,i) && a[pre+i])
        {
            ans.push_back(i);
            fun(i,Set(mask,i));
            ans.pop_back();
        }
    }
}

int main()
{
    CIN;
    a[2]=a[3]=a[5]=a[7]=a[11]=a[13]=a[17]=a[19]=a[23]=a[29]=a[31]=1;
    ans.push_back(1);
    while(cin>>n)
    {
        x++;
        if(x!=1) cout<<endl;
        cout<<"Case "<<x<<":"<<endl;
        fun(1,0);
    }
    return 0 ;
}
