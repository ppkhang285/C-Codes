#include <bits/stdc++.h>
#define task "CITY"
#define REP(i,a,b) for(int i = a ; i<=b;++i)
#define oo 1000000000
using namespace std;
struct Edge{
    int u,v,w;
};

Edge E[20010];
int par[205];
int n,m;
bool Deleted[20010];
bool cmd(Edge i, Edge j){
    return i.w< j.w;
}
int Find(int u){
    if (u==par[u]) return u;
    else{
        par[u] = Find(par[u]);
        return par[u];
    }
}
int Init(){
    REP(i,1,n) par[i] = i;
    memset(Deleted, false, sizeof(Deleted));
    sort(E+1, E +1+m, cmd);
    return 0;
}
bool Merge(int i, int j){
    i = Find(i);
    j = Find(j);
    if (i==j) return 0;
    if (i>j) par[i] = j;
        else par[j] = i;
    return 1;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        E[i] = {u,v,w};
    }

    Init();

    int di = 0;
    int li = 0;
    REP(i,1,m){
        int u = E[i].u;
        int v = E[i].v;
        bool is_Merged = Merge(u,v);
        if (is_Merged){
                di++;
                li += E[i].w;
        }
        else Deleted[i] = true;
    }
    cout<<di<<" "<<li<<"\n";
    REP(i,1,m)
        if (!Deleted[i]) cout<<E[i].u<<" "<<E[i].v<<"\n";
    return 0;
}
