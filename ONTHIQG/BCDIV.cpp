#include <bits/stdc++.h>
#define task "BCDIV"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;
int n,k, F[30][30];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        memset(F, 0, sizeof(F));
        REP(i,1,n) F[i][1] = 1;
        REP(i,1,n) F[i][i] = 1;
        REP(i,2,n)
            REP(j,2,min(i,k)){
               F[i][j] = F[i-1][j-1] + F[i-1][j]*j;
            }
        cout<<F[n][k]<<"\n";
    }
    return 0;
}
