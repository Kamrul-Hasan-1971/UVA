#include <bits/stdc++.h>
#define zero(a) memset(a, 0 , sizeof(a))
#define   output   freopen("output.txt","wt", stdout)
using namespace std;
vector<int> vc[105];
vector<int> vcc;
int visited[105];

void DFS(int a)
{
    int i,d=vc[a].size();
    for(i=0; i<d; i++)
    {
        int r=vc[a][i];
        if(visited[r]==0)
        {
            visited[r]=1;
            DFS(r);
        }
    }
}

int main()
{
    int n,p=1,q=1,j,cnt=0;
    while(cin>>n && n != 0)
    {
        int v;
        while(cin>>v && v!= 0)
        {
            int c;
            while(cin>>c && c!=0)
            {
                vc[v].push_back(c);
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            cnt=0;
            int v;
            cin>>v;
            DFS(v);
            for(j=1; j<=n; j++)
            {
                if(visited[j]==0)
                {
                    cnt++;
                    vcc.push_back(j);
                }
            }
            cout<<cnt;
            for(int x=0; x<vcc.size(); x++)
            {
                cout<<" "<<vcc[x];
            }
            cout<<endl;
            vcc.clear();
            zero(visited);
        }
        for(int y=0; y<=n; y++)
        {
            vc[y].clear();
        }
    }
}
