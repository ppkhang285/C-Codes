#include <bits/stdc++.h>
#define task "FWATER"
#define REP(x,i,j) for(int x=i;x<=j;++x)

using namespace std;
int mincost,n,N,par[305],W[305],a[305][305];
long long sum;

struct EGDE
{
    int x,y,ts;
};
EGDE C[305*305];

bool cmd(EGDE i,EGDE j){ return(i.ts<j.ts);}
int Find(int u)
{
    return (par[u]==u)?u:(par[u]=Find(par[u]));
}
int UNION(int u, int v)
{
    int x=Find(u);
    int y=Find(v);
    if (x==y)
        return 0;
    par[y]=x;
    return 1;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>> n;
    N=0;

    REP(i,1,n){
            cin>>W[i];
            a[n+1][i]=W[i];
            a[i][n+1]=W[i];
    }
    //nhap
    REP(i,1,n)
        REP(j,1,n)
    {
        cin>>a[i][j];
        }

    n++;
    REP(i,1,n-1)
        REP(j,i+1,n){
            N++;
            C[N].x=i;
            C[N].y=j;
            C[N].ts=a[i][j];
        }
//    SORT(1,N);
    sort(C+1,C+1+N,cmd);
    REP(i,1,n) par[i]=i;
    mincost=10000000;
    REP(i,1,N)
    {
        int cmt=UNION(C[i].x,C[i].y);
        if (cmt==1) sum+=C[i].ts;

    }
    cout<< sum;
}
