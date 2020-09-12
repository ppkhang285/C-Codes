#include <bits/stdc++.h>
#define task "HIGHWAY"
#define REP(i,a,b) for(int i = a; i<= b; ++i)
#define oo 100000;
struct Point{
    int x, y;
};

struct EDGE{
    int u,v;
    float w;
};
Point P[800];

EDGE E[1005] , Eres[1005];

int n,m,N ,N2, par[800] , a[800][800], trace[800];

bool Free[800];
using namespace std;

int openFile(){

    ios_base::sync_with_stdio(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    return 0;
}
float Distance(Point a, Point b){
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y )*(a.y - b.y));
}
bool cmd(EDGE i, EDGE j){
    return (i.w< j.w);
}

int Find(int u){
    par[u] =  (par[u]==u)?u:Find(par[u]);
    return par[u];
}
int Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x == y) return 0;
    if (x>y){
        par[x] =y;
    }
    else par[y] = x;
    return 1;
}
int readFile(){
    cin>>n;
    memset(a,false , sizeof(a));
    REP(i,1,n) par[i] = i;
    REP(i,1,n) cin>>P[i].x>>P[i].y;
    cin>>m;
    REP(i,1,m) {
        int u,v;
        cin>>u>>v;
        E[i].u = u;
        E[i].v = v;
        E[i].w = Distance(P[u] , P[v]);
        a[u][v] = a[v][u] = true;
        Union(u,v);
    }
    return 0;
}
int createEGDE(){
    REP(i,1,n-1){
        REP(j,i+1,n){
            if (a[i][j] ==false){
                E[++N].u = i;
                E[N].v = j;
                E[N].w = Distance(P[i] , P[j]);
            }
        }
    }
    return 0;
}
int Kruskal(){

    REP(i,1,m){
        int u = E[i].u;
        int v = E[i].v;
        if (Union(u,v) == 1){
            Eres[++N2] = E[i];
        }
    }
    return 0;
}
int writeOut(){
    cout<<N2<<"\n";
    REP(i,1,N2){
        cout<<Eres[i].u<<" "<<Eres[i].v<<"\n";
    }
    return 0;
}
int main(){
    openFile();

    readFile();

    createEGDE();

    sort(E+1 , E+1+N , cmd);

    Kruskal();

    writeOut();

    return 0;
}
