#include <bits/stdc++.h>
#define task "G2W"
#define REP(x,i,j) for(int x=i;x<=j;x++)
#define oo 1000000

using namespace std;

typedef pair<int, int> ii;

priority_queue<ii, vector<ii>, greater<ii>> ed;
vector<ii> c[10005];
int n,m,p,q,a[50005],b[50005],d[50005];
bool f[50005];
int dijstra(int go)
{
    ed.empty();
    REP(i,1,n) d[i]=oo;
    d[go]=0;
    ed.push(ii(0,go));
    while (ed.size())
    {
        int u=ed.top().second;
        int dd=ed.top().first;
        ed.pop();
        if (dd!=d[u])
            continue;
        for (int i=0 ; int v=c[u][i].second ; i++)
         if (f[v]==true)
            {
                int uv=c[u][i].first;
                if (d[v]>dd+uv)
                {
                    d[v]=dd+uv;
                    ed.push(ii(d[v],v));
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
        int u,v,w;
        cin>>u>>v>>w;
        c[u].push_back(ii(w,v));
    }
    REP(i,1,n) c[i].push_back(ii(0,0));
    memset(f, true, sizeof(f));
    REP(i,1,p) f[a[i]]=false;
    dijstra(1);
    cout<<d[n]<<" ";
    memset(f, true, sizeof(f));
    REP(i,1,q) f[b[i]]=false;
    dijstra(n);
    cout<<d[1];
    return 0;
}
