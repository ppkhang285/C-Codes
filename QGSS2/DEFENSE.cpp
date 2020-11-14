#include <bits/stdc++.h>
#define task "DEFENSE"
#define REP(i,a,b) for(int i =a; i<=b; ++i)
using namespace std;
int T,n,a[100005];
int B[100005];
int solve(){
    memset(B,0, sizeof(B));
    int m = 0;
    REP(i,1,n){
        int k = lower_bound( B+1,B+1+m, a[i]) - B;
        m = max(m, k);
        B[k] = a[i];
    }
    cout<<m<<"\n";
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>T;
    REP(z,1,T){
        cin>>n;
        REP(i,1,n) cin>>a[i];
        solve();
    }
    return 0;
}
