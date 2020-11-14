#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = a; i<= b;++i)
#define task "DIJHEAP"
#define X first
#define Y second
#define oo 100000
using namespace std;
typedef pair<int, int> ii;
vector<ii> a[1000];
int n,m, d[1000];

int Dijsktra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    REP(i,1,n) d[i] = oo;
    d[1] = 0;
    pq.push(ii(0,1));
    while (pq.size()){
        int dd  =  pq.top().X;
        int u = pq.top().Y;
        pq.pop();
        if (dd != d[u]) continue;
        for(auto t:a[u]){
            int v = t.Y;
            int uv = t.X;
            if (d[v] > dd+uv){
                d[v] = dd+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(ii(w,v));
    }
    Dijsktra();
    return 0;
}
