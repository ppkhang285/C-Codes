#include <bits/stdc++.h>
#define task "BANDO"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define oo 1000000000
using namespace std;

int a[105][105],trace[105][105], d[105][105];
int n,s,k;

int Floyd(){
    REP(k,1,n){
        REP(i,1,n){
            REP(j,1,n){
                if (a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                    trace[i][j] = trace[i][k];
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    return 0;
}
int FindPath(int s, int t){
    cout<<s<<" ";
    if (trace[s][t] == t){
            cout<<t<<" ";
        return 0;
    }
    FindPath(trace[s][t],t);

    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>s>>k;
    REP(i,1,n){
        REP(j,1,n){
            d[i][j] = a[i][j] = (i==j)?0:oo;
            trace[i][j] = j;
        }
    }
    REP(i,1,n){
        REP(j,1,n){
            int x;
            cin>>x;
            if (x>0) {
                    a[i][j] = x;
                    d[i][j] = 1;
            }
        }
    }
    Floyd();
    REP(i,1,k){
        int x;
        cin>>x;
        if (a[s][x] == oo) cout<<"-1\n-1\n";
        else{
            cout<<d[s][x] + 1<<" "<<a[s][x]<<"\n";
            FindPath(s,x);
            cout<<"\n";
        }
    }
    return 0;
}
