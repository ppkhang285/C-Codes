#include <bits/stdc++.h>
#define task "SUMMOD"
#define REP(i,a,b) for(int i = a; i<= b; ++i)

using namespace std;

int n,Q,a[100005];
long long F[100005][10];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>Q;
    REP(i,1,n) cin>>a[i];
    F[1][a[1]]=a[1] %10;
    REP(i,2,n){
        REP(j,0,9){
            if (j==a[i]%10) F[i][j]= F[i-1][j]+a[i];
                else F[i][j] = F[i-1][j];
        }
    }
    REP(i,1,Q){
        int L,R,K;
        cin>>L>>R>>K;
            cout<<F[R][K]-F[L-1][K] <<"\n";
    }
    return 0;
}
