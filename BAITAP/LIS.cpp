#include <bits/stdc++.h>
#define task "LIS"
#define REP(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

int n,a[1000005];
int b[1000005],F[1000005];
vector<int> T;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    int m = 0;
    REP(i,1,n){
        F[i] = lower_bound(b+1, b+1+m, a[i]) - b;
        m = max(m, F[i]);
        b[F[i]] = a[i];
    }
    int Ex = m;

    for(int i = n; i>=1 ;--i){
        if (F[i] == Ex){
            T.push_back(a[i]);
            Ex--;
        }
    }
    cout<<m<<"\n";
    for(int i = T.size()-1 ; i>=0; --i){
        cout<<T[i]<<" ";
    }
    return 0;
}
