#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           mod              10000007
#define           zero(a)          memset(a,0,sizeof a)
#define           pii              pair < ll, ll>
#define           pb               push_back


vector<int>vec[20005];
int visited[2005],color[2005],cnt1,cnt2;

int BFS(int a)
{
    visited[a]=1;
    color[a]=1;
    queue<int>qu;
    qu.push(a);
    cnt1++;

    while(!qu.empty())
    {
        int p = qu.front();
        qu.pop();

        for( int i = 0 ; i < vec[p].size() ; i++ )
        {
            int x = vec[p][i];
            if(!visited[x])
            {
                qu.push(x);
                visited[x]=1;
            }
            if(color[p]==1)
            {
                if(!color[x])
                {
                    color[x]=2;
                    cnt2++;
                }
                else if(color[x]==1)
                {
                    return 1 ;
                }
            }
            else
            {
                if(!color[x])
                {
                    color[x]=1;
                    cnt1++;
                }
                else if(color[x]==2)
                {
                    return 1 ;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n, a, b, c, u, v, x,p ;
    scanf( "%d" ,&n );

    while(n--)
    {
        int chk = 0;
        zero( visited ) ;
        zero( color ) ;
        scanf("%d%d%d", &b, &c, &a) ;
        for(int j = 1 ; j <= b+c ; j++ )
        {
            vec[j].clear();
        }

        while(a--)
        {
            scanf("%d%d", &u ,&v ) ;
            vec[u].pb(v);
            vec[v].pb(u);
        }
        int lim = b+c ;
        for(int j = 1 ; j <= lim ; j++ )
        {
            cnt1=cnt2=0;
            if( !visited[j] )
            {
                p = BFS(j);
                if(p==1)
                {
                    chk=1;
                    break;
                }
                if(cnt1+cnt2<=1)
                    continue;
                if(b>c)
                {
                    if(cnt1>cnt2)
                    {
                        b-=cnt1;
                        c-=cnt2;
                    }
                    else
                    {
                        b-=cnt2;
                        c-=cnt1;
                    }
                }
                else
                {
                    if(cnt1>cnt2)
                    {
                        c-=cnt1;
                        b-=cnt2;
                    }
                    else
                    {
                        c-=cnt2;
                        b-=cnt1;
                    }
                }
                if( b<0 || c<0 )
                {
                    chk=1;
                    break;
                }
            }
        }
        if(chk==1)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
    return 0;
}

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2306
