#include <bits/stdc++.h>
#define task "FT"
#define REP(i,a,b) for(int i = a; i<=b; ++i)
#define oo 10000000
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;

vector<ii> a[10005];
int n,m;
int D[10005][2]; //D[i][0]: dmin den i khi ko xai ve, D[i][1]L dmin den i khi xai 1 ve
int DIJ(){

    priority_queue<ii, vector<ii>, greater<ii>> PQ;
    bool Free[10005];memset(Free,true, sizeof(Free));
    REP(i,1,n) D[i][1] = D[i][0] = oo;
    D[1][0] = D[1][1] = 0;
    PQ.push(ii(0,1));
    while(PQ.size() > 0){
        int u = PQ.top().Y;
        //int dd = PQ.top().X;
        PQ.pop();
        if (u == 0) break;
        if (Free[u] == false) continue;
        Free[u] = false;
        for(auto t:a[u]){
            int v = t.Y;
            int ss = t.X;
            if (Free[v] && D[v][0] > D[u][0] + ss) D[v][0] = D[u][0] + ss;
            if (Free[v]){
                D[v][1] = min(D[v][1], min(D[u][1] + ss, D[u][0]) );
                PQ.push(ii(D[v][1], v));
            }
        }
    }
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(ii(w,v));
        a[v].push_back(ii(w,u));
    }
    DIJ();
    cout<<D[n][1];
    return 0;
}
