#include <bits/stdc++.h>
#define task "TONG3"
#define REP(i,a,b) for(int i = a ; i<=b ;++i)

using namespace std;
int n, a[10000];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int Sum = 0;
    REP(i,1,n) Sum +=a[i];
    int res = 0;
    int node = n;
    bool found = true;
    while ( a[node]+a[node-1]+a[node-2]>= Sum -(a[node]+a[node-1]+a[node-2]) ){
        if (node<3) found = false;
        Sum-= a[node];
        node--;
        res++;
    }
    if (found ==false) cout<<"-1";
        else cout<<res;
    return 0;
}
