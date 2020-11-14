#include <bits/stdc++.h>
#define task "DAYCONMAX"
#define REP(i,a,b) for(int i = a; i<= b ; ++i)

using namespace std;
int a[100005], F[100005];
int n;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    F[0]  = 0;
    REP(i,1,n) F[i] = F[i-1] + a[i];
    int res = a[1];
    int nMin = min(0, a[1]);
    REP(i,2,n){
        res = max(res, F[i] - nMin);
        nMin = min(nMin, a[i]);
    }
    cout<<res;
    return 0;
}
