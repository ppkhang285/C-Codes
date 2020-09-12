#include <bits/stdc++.h>
#define task "FT"
#define REP(i,a,b) for(int i=a; i<=b ; i++)
#define oo 100000000
using namespace std;

struct EDGED{
    int u,v;
};
int n,m,  a[1000][1000], ans;
EDGED ED[1000];
int FLOYD()
{

    REP(k,1,n)
    {
        REP(i,1,n)
        {
            REP(j,1,n)
            {
                if (a[i][j]> a[i][k]+a[k][j])
                {
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
    return 0;
}


int Init()
{

    ios_base::sync_with_stdio(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,n)
    {
        REP(j,1,n)
        {
            if (i==j)
            {
                a[i][j]=0;
                a[j][i]=0;
            }
            else
            {
                a[i][j]=oo;
                a[j][i]=oo;
            }
        }
    }
    REP(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
        ED[i].u=u;
        ED[i].v=v;
    }
    return 0;
}

int Find_Res()
{
    ans=oo;
    REP(i,1,m)
    {
        int u=ED[i].u;
        int v=ED[i].v;
        if (a[1][u]+a[v][n]  < ans)
            {
                ans=a[1][u]+a[v][n];
            }
          if (a[1][v]+a[u][n]  < ans)
            {
                ans=a[1][v]+a[u][n];
            }
        }
    return 0;
}

int write_Result()
{
    cout<<ans;
    return 0;
}
int main()
{

    Init();
    FLOYD();
    Find_Res();
    write_Result();
}

