#include <bits/stdc++.h>
#define task "PRIMES"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;
bool Prime[100005];
int maxN,n;
int a[100005], F[100005];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    maxN = 0;
    REP(i,1,n) cin>>a[i];
    REP(i,1,n) maxN = max(maxN, a[i]);
    memset(Prime, 1 , sizeof(Prime));
    Prime[1] = Prime[0] = 0;
    REP(i,2,sqrt(maxN)){
        if (Prime[i]){
            for(int j = i*i; j<=n; j+=i) Prime[j] = 0;
        }
    }
    F[0] = 0;
    int res = 0;
    int dx = 0;
    REP(i,1,n){
        F[i] = Prime[a[i]]?F[i-1]+1:0;
        res = max(res, F[i]);
        if (res == F[i]) dx = i;
    }
    cout<<dx- res + 1 <<" "<<res;
    return 0;
}
