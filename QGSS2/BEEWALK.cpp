#include <bits/stdc++.h>
#define REP(i,a,b) for(int i =a; i<=b;++i)

using namespace std;
int F[20][20][20];
int n;
int dx[] = {1,1,0,-1,-1, 0};
int dy[] = {0,-1,-1, 0,1,1};
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    F[0][15][15] = 1;
    REP(i,1,14){
        REP(u,1,20){
            REP(v,1,20){
                REP(k,0,5){
                    F[i][u][v] += F[i-1][u+dx[k]][v+dy[k]];
                }
            }
        }
    }
    cout<<F[n][15][15];
}
