#include <bits/stdc++.h>
#define task "MINPATH"
#define REP(i,a,b) for(int i = a; i<=b; ++i)
#define X first
#define Y second
#define oo 1000000000
#define N 1005
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int dx[] = {0, 1, 0,-1};
int dy[] = {1, 0,-1, 0};
int d[N][N], a[N][N];
ii Trace[N][N];
int n,m;
int DIJ(){
    priority_queue< iii, vector<iii> , greater<iii> > PQ;
    bool Free[N][N];
    REP(i,1,n)
        REP(j,1,m) d[i][j] = oo;
    d[1][1] = a[1][1];
    Trace[1][1] = ii(0,0);
    memset(Free,true, sizeof(Free));
    PQ.push(iii(a[1][1],ii(1,1)));
    while(PQ.size() >0){
        int i = PQ.top().Y.X;
        int j = PQ.top().Y.Y;
        PQ.pop();
        if (i==n && j==m) break;
        if (i == 0 || j == 0) continue;
        Free[i][j] = false;
        REP(k,0,3){
            int u = i + dx[k];
            int v = j + dy[k];
            if (u<=0 || v<=0 || u>n || v>m) continue;
            if (Free[u][v] && d[u][v] > d[i][j] + a[u][v]){
                d[u][v] = d[i][j] + a[u][v];
                Trace[u][v] = ii(i,j);
                PQ.push(iii(d[u][v], ii(u,v)));
            }
        }
    }
    return 0;
}
int FindPath(int i, int j){
    if (i<=0 || j<=0 || i>n || j>m ) return 0;
    FindPath(Trace[i][j].X, Trace[i][j].Y);
    cout<<i<<" "<<j<<"\n";
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    REP(i,1,n)
        REP(j,1,m) cin>>a[i][j];
    DIJ();
    cout<<d[n][m]<<"\n";
    FindPath(n,m);
    return 0;
}

