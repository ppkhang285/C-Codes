#include <bits/stdc++.h>
#define task "QBSCHOOL"
#define REP(x,i,j) for(int x=i;x<=j;++x)
#define oo 1000000

using namespace std;
typedef pair<int, int> ii;

vector<ii> a[5005];
int n,m;
long long d[5005],f[5005];
int dijstra()
{
    priority_queue<ii, vector<ii>,  greater<ii>> pq;
    REP(i,1,n) d[i]=oo;
    d[1]=0;
    pq.push(ii(0,1));
    while (pq.size())
    {
        int dd=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (dd!=d[u])
            continue;
        for(int i=0; int v=a[u][i].second ; i++)
        {
            int uv=a[u][i].first;
            if (d[v]> dd+uv)
            {
                d[v]=dd+uv;
                pq.push(ii(d[v],v));
                f[v]=f[u];
            }
            else if (d[v]==dd+uv)
                f[v]+=f[u];
        }

    }
    return 0;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    REP(i,1,m)
    {
        int cmd;
        int u,v,w;
        cin>>cmd>>u>>v>>w;
        a[u].push_back(ii(w,v));
        if (cmd==2)
            a[v].push_back(ii(w,u));
    }
    f[1]=1;
    REP(i,1,n) a[i].push_back(ii(0,0));
    dijstra();
    cout<<d[n]<<" "<<f[n];
    return 0;

}
