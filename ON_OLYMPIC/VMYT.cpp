#include <bits/stdc++.h>
#define task "VMYT"
#define REP(i,a,b) for(int i = a; i<=b; ++i)
#define module 1000000007
using namespace std;
int n,a[100000],k;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>k;
    REP(i,1,k) cin>>a[i];
    a[0] = 1;
    if ( n<=k) cout<<a[n];
    else{
        a[k+1] = 1;
        REP(i,1,k) a[k+1]*=a[i];
        REP(i,k+2,n) a[i] = (  ((a[i-1] %module) * (a[i-1]%module)) /a[i-k-1]) %module;
        cout<<a[n];
    }
    return 0;
}


