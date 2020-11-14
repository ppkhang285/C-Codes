#include <bits/stdc++.h>
#define task "PEARL"
#define REP(i,a,b) for(int i = a ; i<=b;++i)

using namespace std;
typedef long long LL;

vector<int> L;
map<int, bool> appeared;
int F[500005],n, a[500005];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    L.push_back(1);
    REP(i,2,n)
        if (n%i == 0)
             L.push_back(i);
    appeared[a[1]] = true;
    F[0] = 0;
    F[1] = 1;
    REP(i,2,n) if(appeared[a[i]] == false){
        appeared[a[i]] = true;
        F[i] = F[i-1] + 1;
    }
    else F[i] = F[i-1];
    cout<<L.size()<<"\n";
    for(auto k:L){
        int res = 100005;
        for(int i =1; i<=n; i+=k ){
            res = min(res, F[i+k-1] - F[i-1]);
        }
        if (res == 0) res++;
       cout<<k<<" "<<res<<"\n";
    }
    return 0;
}
