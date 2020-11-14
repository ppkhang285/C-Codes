#include <bits/stdc++.h>
#define task "QBSELECT"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define Bit 15
using namespace std;

int n;
int F[1005][18], a[6][1005];
int getBit(int x, int i){
    return (x >> (i-1)) & 1;
}
bool CheckSelf(int x){
    REP(i,1,3) if (getBit(x,i) == 1 && getBit(x,i+1) == 1) return false;
    return true;
}
bool Check(int x, int y){
    REP(i,1,4) if (getBit(x,i) == 1 && getBit(y,i) == 1) return false;
    return true;
}
int Add(int i, int k){
    int ans = 0;
    REP(j,1,4) if (getBit(k,j) == 1) ans += a[j][i];
    return ans;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,4)
        REP(j,1,n) cin>>a[i][j];
    F[0][0] = 0;
    REP(k,0,Bit){
       if (CheckSelf(k)) F[1][k] = Add(1,k);
    }
    REP(i,2,n){
        REP(k,0,Bit){
            if (CheckSelf(k))
            REP(m,0,Bit){
                if (CheckSelf(m))
                if (Check(k,m)) F[i][k] = max(F[i][k], F[i-1][m] + Add(i,k));
            }
        }
    }
    int res = 0;
    REP(k,0,Bit) res = max(res, F[n][k]);
    cout<<res;
    //cout<<getBit(1,4);
    return 0;
}
