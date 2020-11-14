#include <bits/stdc++.h>
#define task "LIS"
#define REP(i,a,b) for(int i =a; i<=b;++i)

using namespace std;
int a[10000],b[10000];
int n;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    int m  = 0;
    REP(i,1,n){
        int k = lower_bound(b+1, b+1+m, a[i]) - b ;
        m = max(m,k);
        b[k] = a[i];
    }
    cout<<m;
    return 0;
}
