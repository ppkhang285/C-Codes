#include <bits/stdc++.h>
#define task "TCOST"
#define REP(i,a,b) for(int i = a ; i<=b;++i)
#define simp cin
using namespace std;

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,n) simp>>B[i];
    REP(i,1,n){
        REP(j,1,n){
            cin>>a[i][j];
            a[i][j]+=b[j];
        }
    }
}
