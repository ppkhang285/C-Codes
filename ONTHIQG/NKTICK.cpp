#include <bits/stdc++.h>
#define task "NKTICK"
#define REP(i,a,b) for(int i = a; i<= b ; ++i)

using namespace std;
int a[60005], b[60005], F[60005];
int n;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    REP(i,1,n-1) cin>>b[i];
    F[1] = a[1];
    REP(i,2,n) F[i] = min( F[i-1] + a[i], F[i-2] + b[i-1] );
    cout<<F[n];
    return 0;
}

