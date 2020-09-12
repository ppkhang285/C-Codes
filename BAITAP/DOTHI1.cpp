#include <bits/stdc++.h>
#define task "DOTHI1"
#define REP(i,a,b) for(int i=a ; i<=b ;  i++)
#define INFF 100000
using namespace std;
int C[100][100] ;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    REP(i,0,100){
        REP(j,0,100){
            C[i][j] = INFF;
        }
    }
    int u,v,w;
    int m =0,n =0;
    while (cin>>u>>v>>w){
        C[u][v] = w;
        C[v][u] = w;
        n = max(n , max(u,v));
        m++;
    }
    cout<<n+1<<" "<<m<<"\n";
    REP(i,0,n){
        REP(j,0,n){
            if (C[i][j] == INFF) cout<<"oo ";
            else
                cout<<C[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
