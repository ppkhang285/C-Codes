#include <bits/stdc++.h>
#define task "CAG"
#define REP(i,a,b) for(int i=a; i<=b ; ++i)

using namespace std;
int n,m , amountLong,par[10000], N;
struct EGDE{
    int u, v ,w;
};
EGDE C[10000], E[10000];
bool cmd(EGDE i, EGDE j){
    return i.w< j.w;
}
void readInput(){
    freopen(task".inp","r", stdin);
    freopen(task".out","w", stdout);

    cin>>n>>m;
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        C[i].u = u;
        C[i].w = w;
        C[i].v = v;
    }
}
void Init(){
    REP(i,1,n) par[i] = i;
    N = 0;
}
int Find(int x){
    (x == par[x])? x:Find(par[x]);
}
int Kruskal( int u, int v){
    int a = Find(u);
    int b = Find(v);
    if (a==b){
        return 0;
    }
    else{
        if (b>a) par[b] = a;
            else par[a] = b;
        return 1;
    }
}
void process(){
    REP(i,1,m){
        int u = C[i].u;
        int v = C[i].v;
        int w = C[i].w;
        int Merge = Kruskal(u , v);
        if (Merge == 1){
            amountLong+= w;
            E[++N] = C[i];
        }
    }
}
void writeOutput(){
    cout<<amountLong<<"\n";
    cout<<N<<"\n";
    REP(i,1,N){
        cout<<E[i].u<<" "<<E[i].v<<"\n";
    }
}
int main(){
    readInput();
    sort(C+1, C+1+m , cmd);
    Init();
    process();
    writeOutput();
    return 0;
}

