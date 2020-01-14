#include<bits/stdc++.h>
using namespace std;

#define           pii                pair < double, double>
#define           pb                 push_back

map<pii,int>mp;

struct edgeStructure
{
    int u;
    int v;
    double w;
};

bool operator<(edgeStructure lhs,edgeStructure rhs)
{
    return lhs.w<rhs.w;
}

int parent[210];

vector<edgeStructure>edgeVector;
vector<double>v1,v2;


void initializeSet(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
    }
}

int findParent(int x)
{
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

double kruskal(int n)
{
    initializeSet(n);
    sort(edgeVector.begin(),edgeVector.end());

    int sz=edgeVector.size();
    double ans=0.0;

    for(int i=0;i<sz;i++){
        int uPr = findParent(edgeVector[i].u);
        int vPr = findParent(edgeVector[i].v);
        if(uPr != vPr)
        {
            parent[uPr] = vPr;
            ans+=edgeVector[i].w;
        }
    }
    return ans;
}

int main()
{
    int  a,b,c,d,e,f,i,j=0,k,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    cin >> T ;
    for( j = 1 ; j <= T ; j++)
    {
        double xx, yy ;
        int cnt1 = 1 ;
        edgeVector.clear();
        mp.clear();
        v1.clear();
        v2.clear();
        cin >> a ;
        for( i = 0 ; i < a ; i++ )
        {
            cin >> xx>> yy ;
            v1.pb(xx);
            v2.pb(yy);
        }
        for( k = 0 ; k < a ; k++ )
        {
            if(!mp.count({v1[k],v2[k]}))
            {
                mp[ {v1[k],v2[k]}]=cnt1;
                cnt1++;
            }
            int x = mp[ {v1[k],v2[k]}];
            for( i = k+1 ; i < a ; i++ )
            {
                if(!mp.count({v1[i],v2[i]}))
                {
                    mp[ {v1[i],v2[i]}]=cnt1;
                    cnt1++;
                }
                int y = mp[ {v1[i],v2[i]}];

                edgeStructure xxx ;
                xxx.u = x;
                xxx.v = y;
                xxx.w = sqrt(pow((v1[k]-v1[i]),2)+pow((v2[k]-v2[i]),2)) ;
                edgeVector.pb(xxx);
            }
        }
        double ans = kruskal(cnt1-1);
        printf("%.2f\n",ans);
        if(j!=T)printf("\n");
    }
    return 0 ;
}
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=975
