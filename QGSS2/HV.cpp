#include <bits/stdc++.h>
#define task "HV"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;
int n,m;
int a[4005][8005], H[4005][8005], F[4005][8005];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    //cin>>T;
    //while(T--){
        cin>>n;
        n*=2;
        REP(i,1,n)
            REP(j,1,n) cin>>a[i][j];
        m = n*2;
        REP(i,1,n)
            REP(j,n+1,m) a[i][j] = a[i][(j%n==0)?m:j%n];
        REP(i,1,m) F[1][i] = a[1][i];
        REP(i,1,n) F[i][1] = a[i][1];
        REP(i,2,n)
            REP(j,2,m){
                F[i][j] = a[i][j];
                if (a[i][j] ==1 && a[i][j-1] == 1 && a[i-1][j-1] == 1 && a[i-1][j] ==1)
                    F[i][j] = min(F[i-1][j],min( F[i][j-1], F[i-1][j-1])) + 1;
            }
        int res =0;
        REP(i,1,n)
            REP(j,1,m) res = max(res, F[i][j]*F[i][j]);
        cout<<res<<"\n";
    //}
    return 0;
}
