#include <bits/stdc++.h>
#define task "QHROAD"
#define REP(i,a,b) for(int i = a; i <= b ; ++i)
#define Nmax 100005
using namespace std;
struct EDGELIST{
    int x,y;
};

EDGELIST edge[Nmax];
int Deleted[Nmax] , par[Nmax] ,res[Nmax] ,m , q , n , ans;
bool Alive[Nmax];
int Find(int u){
    if (par[u] != u) par[u] = Find(par[u]);
    return par[u];
}

int UNION(int u,int v){
    int x = Find(u);
    int y = Find(v);
    if ( x != y) {
        ans--;
        if (x<y) par[y] =x;
            else par[x] = y;
    }

    return 0;
}
int main(){
    //open and read after eating
     //Init

    memset(Alive , true , sizeof(Alive));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>q;
    REP(i,1,n) par[i] = i;
    REP(i,1,m) cin>>edge[i].x>>edge[i].y;
    REP(i,1,q) {
        cin>>Deleted[i];
        Alive[Deleted[i]] = false;
    }
    //

    ans = n;
    REP(i,1,m){
        if (Alive[i]) UNION(edge[i].x , edge[i].y);
    }
    res[q] = ans;
    for (int i = q; i>0 ;--i){
        int u = edge[Deleted[i]].x;
        int v = edge[Deleted[i]].y;
        UNION(u ,v);
        res[i-1] = ans;
    }
    REP(i,1,q) cout<<res[i]<<"\n";
    return 0;
}
