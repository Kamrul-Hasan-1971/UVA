#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  all(a)         a.begin(),a.end()
ll a;
string s1 , s2;
void fun(ll indx)
{
    if(s2.size()==a)
    {
        cout<<s2<<endl;
        return ;
    }
    for(ll i = indx ; i < s1.size() ; i++)
    {
        s2+=s1[i];
        fun(i+1);
        s2.pop_back();
        while(i+1<s1.size() && s1[i]==s1[i+1]) i++;
    }
}

int main()
{
    CIN;
    while(cin>>s1>>a)
    {
        sort(all(s1));
        fun(0);
    }
    return 0 ;
}
