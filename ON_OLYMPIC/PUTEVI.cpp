#include <bits/stdc++.h>
#define task "PUTEVI"
#define REP(i,a,b) for(int i=a ;i<=b ;++i)
#define oo 1000000

using namespace std;

int C[10000][10000] ,m,n;

void Floyd_With_The_Light(){
    REP(k,1,n)
        REP(i,1,n)
            REP(j,1,n){
                if (C[i][k] !=oo && C[k][i]!=oo && C[i][j] >C[i][k]*C[k][j] ){
                    C[i][j] = C[i][k]*C[k][j];
                }
            }
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin>>n;
    m = n-1;
    REP(i,1,n)
        REP(j,1,n)
             if (i!=j) C[i][j]=oo;
             else C[i][j]= 1;
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        C[u][v] = w;
        C[v][u] = w;
    }
    Floyd_With_The_Light();
    int res =0;
    REP(i,1,n-1)
        REP(j,i+1,n){
            res+= C[i][j];
        }
    cout<<res;
    return 0;
}
