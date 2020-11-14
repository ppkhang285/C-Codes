#include <bits/stdc++.h>
#define task "HALL"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define oo 100000000
using namespace std;
int a[105][105];
int n;

int Floyd(){
    REP(k,1,n){
        REP(i,1,n){
            REP(j,1,n){
                if (a[i][j] > a[i][k] + a[k][j]) a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n){
        REP(j,1,n) a[i][j] = (i==j)?0:oo;
    }
    int x,y,w;
    while( cin>>x>>y>>w){
        a[x][y] = w;
        a[y][x] = w;
    }
    Floyd();
    int nMin = oo;
    int res = 1;
    REP(i,1,n){
        int nNow = 0;
        REP(j,1,n){
            if (i!=j) nNow+=a[i][j];
        }
        if (nNow < nMin){
            nMin = nNow;
            res = i;
        }
    }
    cout<<res;
    return 0;
}
