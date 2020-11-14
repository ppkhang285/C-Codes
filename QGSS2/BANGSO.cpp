#include <bits/stdc++.h>
#define task "BANGSO"
#define REP(i,a,b) for(int i = a ; i<=b; ++i)

using namespace std;
int n;
int a[1000005], F[1000005][3];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    F[1][0] = a[1];
    F[1][1] = -a[1];
    REP(i,2,n){
        F[i][0] = max( max(a[i],F[i-1][0]), F[i-1][1] + a[i]);
        F[i][1] = max( max(-a[i],F[i-1][1]), F[i-1][0] - a[i]);
    }
    cout<<max(F[n][1], F[n][0]);
    return 0;
}
