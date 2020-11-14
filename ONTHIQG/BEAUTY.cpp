#include <bits/stdc++.h>
#define task "BEAUTY"
#define REP(i,a,b) for(int i = a ;i<=b;++i)

using namespace std;
typedef long long ll;

ll m[300005], F[300005];
int n, a[300005];

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    if (n<=1){
        cout<<"0";
        return 0;
    }
    if (n == 2){
        cout<<a[1] + a[2];
        return 0;
    }
    F[0] = 0;
    REP(i,1,n) F[i] = F[i-1] + a[i];
    m[1] = min(ll(0), F[1]);
    m[2] = min(ll(0), F[2]);
    m[3] = min(m[1], F[3]);
    m[4] = min(m[2], F[4]);
    m[0] = 0;
    ll res = max(F[2], F[3] - F[1]);
    REP(i,4,n){
        res = max(res, F[i] - m[i-4]);
        m[i] = min(m[i-2], F[i]);
    }
    cout<<res;
    return 0;
}
