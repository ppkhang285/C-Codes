#include <bits/stdc++.h>
#define task "G2W"
#define REP(x,i,j) for(int x=i;x<=j;++x)
using namespace std;

typedef pair<int, int> ipair;
priority_queue<ipair, vector <ipair>, greater<ipair> > ED;

int C[1000][1000],a[1000],b[1000],n,m,p,q,D[10000];
bool Free[1000],DD[1000][1000];
int init(int go)
{
    REP(i,1,n)
    {
        D[i]=C[go][i];
        ED.push(make_pair(D[i],i));
    }
    return 0;
}

int DIJSTRA(int go)
{
    while (ED.size()){
        int u=ED.top().second;
        Free[u]=false;
        if (u==0 && u==go)
            return 0;
        ED.pop();
        REP(v,1,n)
        {
            if (Free[v]==true && DD[u][v]==true)
            {
                if (D[v]>D[u]+C[u][v])
                {
                    D[v]=D[u]+C[u][v];
                    ED.push(make_pair(D[v],v));
                }
            }
        }
    }
    return 0;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>p>>q;
    REP(i,1,p) cin>>a[i];
    REP(i,1,q) cin>>b[i];
    REP(i,1,m)
    {
        int u;
        int v;
        cin>>u>>v>>C[u][v];
        DD[u][v]=true;
    }
    memset(Free, true, sizeof(Free));
    REP(i,1,p) Free[a[i]]=false;
    init(1);
    DIJSTRA(n);
    cout<<D[n]<<" ";
    memset(Free, true,sizeof(Free));
    REP(i,1,q) Free[b[i]]=false;
    init(n);
    DIJSTRA(1);
    cout<<D[1];
    return 0;
}
