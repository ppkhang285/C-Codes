#include <bits/stdc++.h>

#define task "HARBINGERS"
#define REP(x,i,j) for (int x=i;x<=j;x++)
#define long long long

#define X first
#define Y second
using namespace std;

int n,top;
long f[100005];
typedef pair<long,long> Line;
typedef pair<long, long > ii;
vector<Line> a[100005];
Line lines[100005];
long d[10005];
long S[100005],V[100005];
struct operate
{
    int pos,top;
    Line overwrite;
    operate(int p, int t, Line ov)
    {
        pos=p;
        top=t;
        overwrite=ov;
    }
};
vector<operate> undolist;
long get(Line d, long x)
{
    return x*d.X+d.Y;
}
long minGet(long point)
{
    int l=0;
    int r=top-1;
    long now=get(lines[1], point);
    while (l<r)
    {
        int mid=(l+r)/2;
        long x=get(lines[mid],point);
        long y=get(lines[mid+1],point);
        if (x>y)
            l=mid+1;
        else
            r=mid;
        now=min(now,min(x,y));
    }
    return now;
}
bool useless(Line a, Line b, Line c)
{
    return (b.Y-a.Y)*(a.X-c.X)>=(a.X-b.X)*(c.Y-a.Y);
}
int instline(Line newline)
{
    int l=1;
    int r=top-1;
    int k=top;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (useless(lines[mid-1],lines[mid],newline))
        {
            r=mid-1;
            k=mid;
        }
        else
            l=mid+1;
    }
    undolist.push_back(operate(k,top,lines[k]));
    lines[k]=newline;
    top=k+1;
    return 0;
}
int undo()
{
    operate ope=undolist.back();
    undolist.pop_back();
    top=ope.top;
    lines[ope.pos]=ope.overwrite;
    return 0;
}
int dfs(int u, int parent)
{
    if (u>1)
        f[u]=minGet(V[u])+S[u]+d[u]*V[u];
    instline(make_pair(-d[u],f[u]));
    for (auto ed:a[u])
    {
        int v=ed.X;
        long uv=ed.Y;
        if (v==parent)
            continue;
        d[v]=d[u]+uv;
        dfs(v,u);
    }
    undo();
    return 0;
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    REP(i,1,n-1)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }
    REP(i,2,n) cin>>S[i]>>V[i];
    dfs(1,0);
    REP(i,2,n) cout<<f[i]<<" ";
    return 0;
}


