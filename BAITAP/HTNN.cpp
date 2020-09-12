#include <bits/stdc++.h>
#define task "HTNN"
#define REP(i,a,b) for(int i = a; i<= b; ++i)
#define oo 100000
using namespace std;
int n,m, C[105][105], d[105] ,d2[105], trace[105], C1[105][105];
bool Free[105];
int Openfile(){
    ios_base::sync_with_stdio(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    return 0;
}

int Readfile(){
    cin>>n>>m;

    REP(i,1,n){
        REP(j,1,n){
            C[i][j] = (i ==j)?0:oo;
            C1[i][j] = C[i][j];
        }
    }

    REP(i,1,m){
        int u,v,w1,w2;
        cin>>u>>v>>w1>>w2;
        C[u][v] = C[v][u] = w1;
        C1[u][v] = C1[v][u] =w2;

    }

    return 0;
}
int Init(){
    REP(i,1,n) d[i] = C[1][i];
    REP(i,1,n) d2[i] = C1[1][i];
    REP(i,1,n)
        if (d[i]<oo) trace[i] = 1;
    memset(Free , true , sizeof(Free) );

    return 0;
}
int Dijsktra(){
    Free[1] = false;
    do{
        int u = 0;
        int nmax = oo;
        REP(i,1,n){
            if ( Free[i] == true && d[i] <nmax){
                u = i;
                nmax = d[i];
            }
        }
        if (u == 0 || u == n) return 0;
        Free[u] = false;
        REP(v,1,n){
            if (Free[v] && C[u][v] < oo ){
                    if( d[v] > d[u] + C[u][v]){
                        d[v] = d[u] +C[u][v];
                        d2[v] = d2[u] +C1[u][v];
                        trace[v] = u;
                }
                    else
                        if(d[v] == d[u]+C[u][v]){
                            if (d2[v] > d[u] +C1[u][v]){
                                d[v] = d[u] + C[u][v];
                                trace[v] = u;
                            }
                        }
            }
        }
    }
    while (true);

    return 0;
}
int writeOut(int u){

    if (u == 1 ) {
        cout <<"1 ";
        return 0;
    }
    writeOut(trace[u]);

    cout<<u<<" ";

    return 0;
}
int main(){
    Openfile();

    Readfile();

    Init();

    Dijsktra();

    writeOut(n);

    return 0;
}
