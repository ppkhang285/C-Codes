#include <bits/stdc++.h>
#define task "CABLE"
#define REP(i,a,b) for(int i = a; i<= b;++i)

using namespace std;
int n , a[25005] , F[25005][2];
int main(){
    ios_base::sync_with_stdio(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin>> n;
    REP(i,1,n-1) cin>>a[i];
    memset(F, 0 , sizeof(F));
    F[2][1] = a[1];
    F[2][0] = 100000;
    REP(i,3,n){
        F[i][0] = F[i-1][1];
        F[i][1] = min(F[i-1][1] , F[i-1][0]) +a[i-1];
    }
    cout<< F[n][1];
    return 0;
}
