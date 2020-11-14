#include <bits/stdc++.h>
#define task "HOICHO"
#define REP(i,a,b) for(int i = a; i<=b; ++i)

using namespace std;
int dx[] = {0, -1,  0, 1 };
int dy[] = {1,  0, -1, 0};
int D[15][15];
int n,x,y;
bool Free[15][15];
int Check(){
    if (D[n][1] != n*n) return 0;
    REP(i,1,n){
        REP(j,1,n){
            cout<<D[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}
int DFS(int i, int j, int step){
    D[i][j] = step;
    if (step == n*n) {
            Check();
            return 0;
    }
    Free[i][j] = false;
    REP(k,0,3){
        int u = i + dx[k];
        int v = j + dy[k];
        if (step+1 < n*n && u == n && v == 1) continue;
        if (Free[u][v] == true &&  1<=u && u<=n && 1<=v && v<=n){
            DFS(u , v , step+1);
            Free[u][v] = true;
        }
    }

    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>x>>y;
    memset(Free,true, sizeof(Free));
    DFS(x,y,1);
    return 0;
}
