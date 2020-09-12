#include <bits/stdc++.h>
#define task "DULICH1"
#define REP(i,a,b) for(int i=a ; i<=b ; ++i)
#define oo 10000000
using namespace std;

struct EGDE{
    int u,v,w;
};
EGDE E[10000];
int C[100][100] ,n, m , T[1000][100], chosenE, chosenU , chosenV , chosen[1000] ,N , L[100][100];
void FLoyd(){
    REP(k,1,n)
        REP(i,1,n)
            REP(j,1,n){
                if (C[i][j]> C[i][k] +C[k][j]){
                    C[i][j] = C[i][k] + C[k][j];
                    L[i][j] = L[i][k] + L[k][j];
                    T[i][j] =T[i][k];
                }
            }
}
void trace(int u, int v){
    while (u!=v){
            u = T[u][v];
        chosen[++N] = u;

    }
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,n)
        REP(j,1,n){
            if (i==j) C[i][j] = 0;
                else C[i][j]= oo;
        }
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        C[u][v] = C[v][u] = min(C[u][v] , w);
        T[u][v] = v;
        T[v][u] = u;
        E[i].u = u;
        E[i].v = v;
        E[i].w = w;
        L[u][v] = 1;
        L[v][u] = 1;

    }
    FLoyd();
    int res = oo;
    REP(i,1,n){
        REP(j,1,m){
        int u = E[j].u;
        int v = E[j].v;
        int w = E[j].w;
        if (u!=i && v!=i){
            if ( C[i][u]+C[u][v]!= C[i][v] && C[i][v]+C[v][u]!= C[i][u] && T[i][v] != T[i][u] && L[i][u] +L[i][v]>=3){
                if (res>C[i][u]+C[i][v]+ w ){
                    res = C[i][u]+C[i][v]+ w;
                    chosenE = i;
                    chosenU = u;
                    chosenV = v;
                }
            }
        }
        }
    }
    N = 0;
    trace(chosenE , chosenU);
    chosen[++N] = chosenV;
    trace(chosenV , chosenE);
    if (res==oo) cout<<"0";
    else{
        cout<<"1\n";
        cout<<res<<"\n";;
        cout<<N<<"\n";
        REP(i,1,N) cout<<chosen[i]<<" ";
    }
}

