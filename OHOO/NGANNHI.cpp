#include <bits/stdc++.h>
#define task "NGANNHI"
#define REP(i,a,b) for(int i=a; i<=b ; i++)
#define oo 100000000
using namespace std;

struct EDGED{
    int u,v,w;
};
int n,m,min1[1000], min2[1000], a[1000][1000];
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

int Find_Min_First()
{
    REP(i,1,n)
    {
        min1[i]=a[1][i];
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
        ED[i].w=w;
    }
    return 0;
}

int Find_Min_Second( int t)
{
    if (t==n+1)
        return 0;
    int ans=oo;
    REP(i,1,m)
    {
        int u=ED[i].u;
        int v=ED[i].v;
        int w=ED[i].w;
        if (t==1){
                       if (a[1][u]+a[v][t] +w != a[1][t] && u!=1 && v!=1 && a[1][u]+a[v][t] +w < ans)
            {
                ans=a[1][u]+a[v][t] +w;
            }
        }

        else
            if (a[1][u]+a[v][t] +w != a[1][t] && a[1][u]+a[v][t] +w < ans)
            {
                ans=a[1][u]+a[v][t] +w;
            }
        }
    min2[t]=ans;
    Find_Min_Second(t+1);
    return 0;
}

int write_Result()
{
    REP(i,1,n)
    {
        cout<<min1[i]<<" "<<min2[i]<<"\n";
    }
    return 0;
}
int main()
{

    Init();
    FLOYD();
    Find_Min_First();
    Find_Min_Second(1);
    write_Result();
}
