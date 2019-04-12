#include <bits/stdc++.h>
#define zero(a) memset(a, 0 , sizeof(a))
using namespace std;
char s[10][10];
int visited[10][10];
int b,c;

int dx4[]= {-1,0,0};
int dy4[]= {0,1,-1};
vector<string>v1;

bool valid(int x, int y)
{
    if(x>=0 && x<b && y>=0 && y<c && s[x][y]=='0' && !visited[x][y])
    {
        return 1;
    }
    return 0;
}


void DFS(int x,int y)
{
    int i;
    visited [x][y]=1;
    for(i=0; i<=2; i++)
    {
        int xx=x+dx4[i];
        int yy=y+dy4[i];
        if(valid(xx,yy))
        {
            if(xx!=x)
            {
                v1.push_back("forth");
            }
            else
            {
                if(yy==y-1)
                {
                    v1.push_back("left");
                }
                else
                {
                    v1.push_back("right");
                }

            }
            DFS(xx,yy);
        }
    }

    return;
}

int main()
{

    int a,i,j,k,out1,out2,home1,home2;
    cin>>a;
    for(i=0; i<a; i++)
    {
        zero(visited);
        cin>>b>>c;
        for(j=0; j<b; j++)
        {
            for(k=0; k<c; k++)
            {
                cin>>s[j][k];
                if(s[j][k]=='#')
                {
                    home1=j;
                    home2=k;
                }
                else if(s[j][k]=='@')
                {
                    out1=j;
                    out2=k;
                }

                if(s[j][k]=='I' || s[j][k]=='E' || s[j][k]=='H' || s[j][k]=='O' || s[j][k]=='V' || s[j][k]=='A' || s[j][k]=='#' || s[j][k]=='@')
                {
                    s[j][k]='0';
                }
            }
        }

        DFS(out1,out2);
        for(int u=0; u<v1.size()-1; u++)
        {
            cout<<v1[u]<<" ";
        }
        cout<<v1[v1.size()-1]<<endl;
        v1.clear();
    }
  return 0;
  /*
  #include <bits/stdc++.h>
using namespace std;
char s[10][10];
int visited[10][10];
pair< int , int > par[10][10] ;
vector< string > res ;
int b,c;

int dx4[]= {-1,0,0};
int dy4[]= {0,1,-1};

bool valid(int x, int y)
{
    if(x>=0 && x<b && y>=0 && y<c && s[x][y]=='0' && !visited[x][y])
    {
        return 1;
    }
    return 0;
}

void Print( int x , int y , int xx , int yy ){
    if( x != xx ) printf("fourth ") ;
    else{
        if( yy == y + 1 ) printf("right ") ;
        else printf("left ") ;
    }
}

void DFS(int x,int y)
{
    int i;
    visited [x][y]=1;
    for(i=0; i<=2; i++)
    {
        int xx=x+dx4[i];
        int yy=y+dy4[i];
        if(valid(xx,yy))
        {
            Print( x , y , xx , yy ) ;
            par[xx][yy] = make_pair( x , y ) ;
            DFS(xx,yy);
        }
    }
    return;
}

int main()
{

    int a,i,j,k,out1,out2,home1,home2;
    scanf("%d", &a);
    for(i=0;i<a;i++)
    {
        scanf("%d %d", &b, &c);
        for(j=0;j<b;j++){
            for(k=0;k<c;k++){
                cin>>s[j][k];
                if(s[j][k]=='#'){
                    home1=j;
                    home2=k;
                }
                else if(s[j][k]=='@'){
                    out1=j;
                    out2=k;
                }

                if(s[j][k]=='I' || s[j][k]=='E' || s[j][k]=='H' || s[j][k]=='O' || s[j][k]=='V' || s[j][k]=='A' || s[j][k]=='#' || s[j][k]=='@'){
                    s[j][k]='0';
                }
            }
        }


        //par[out1][out2] = make_pair( -1 , -1 ) ;
        DFS(out1,out2);
//        while( par[home1][home2].first != -1 ){
//            int tmp1 = par[home1][home2].first , tmp2 = par[home1][home2].second ;
//            if( home1 != tmp1 ) res.push_back( "forth" ) ;
//            else{
//                if( tmp2 < home2 ) res.push_back( "right" ) ;
//                else res.push_back( "left" ) ;
//            }
//            home1 = tmp1 , home2 = tmp2 ;
//        }
//        int d = res.size() ;
//        for( i = d - 1 ; i >= 0 ; i -- ){
//            if( i < d - 1 ) printf(" ") ;
//            cout<< res[i] ;
//        }
    }

}
*/
}
