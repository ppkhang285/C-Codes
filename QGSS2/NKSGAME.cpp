#include <bits/stdc++.h>
#define task "NKSGAME"
#define REP(i,a,b) for(int i = a; i<=b; ++i)
#define oo 1000000000000000005
using namespace std;
typedef long long ll;

int n,b[100005], c[100005];
ll ans;
ll Find(int L, int R, int S){
    ll nowAns = oo;
    while (L <= R){
        int mid = (L + R) /2;
        if (c[mid] == S) return 0;
        if ( abs(S -  c[mid]) <= nowAns) nowAns = abs(S - c[mid]);
        if (c[mid] < S){
            L = mid +1;
        }
        else R = mid - 1;
    }
    return nowAns;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>b[i];
    REP(i,1,n) cin>>c[i];
    REP(i,1,n) c[i] = -c[i];
    sort(c + 1, c+1+n);
    ans = oo;
    REP(i,1,n){
        ll k = Find(1,n, b[i]);
        ans = min(ans, k) ;
    }
    cout<<ans;
    return 0;
}
