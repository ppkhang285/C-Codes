#include <bits/stdc++.h>
#define task "NTSHOES"
#define REP(i,a,b)for(int i = a ; i<=b;++i)
#define oo 100000000
using namespace std;
int S[1005],H[1005], F[1005][1005],n,m;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n;
    REP(i,1,m) cin>>S[i];
    REP(i,1,n) cin>>H[i];
    sort(S +1, S+1+m);
    sort(H +1, H+1+n);
    REP(i,0,m)
        REP(j,1,n) F[i][j] = oo;
    F[1][1] = abs(S[1] - H[1]);
    REP(i,2,m) F[1][i] = min(F[1][i-1], abs(S[i] - H[1]));

    REP(i,2,n)
        REP(j,i,m){
            F[i][j] = min(F[i][j-1], F[i-1][j-1] + abs(S[j] - H[i]) );
    }
    cout<<F[n][m];
    return 0;

}
