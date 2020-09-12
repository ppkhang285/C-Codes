#include <bits/stdc++.h>
#define task "J_BONUS"
#define REP(i,a,b) for(int i = a ; i<=b ;++i)
#define maxC -100000
using namespace std;
int a[300][300],n,m;
double F[300][300];

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n;
    swap(m,n);
    REP(i,1,n){
        REP(j,1,m){
            cin>>a[i][j];
        }
    }
    REP(i,1,n)
        if (a[i][1] >=0) F[i][1] =a[i][1];
            else F[i][1] = 0;
    REP(i,1,m){
        a[0][i] = maxC;
        a[n+1][i] = maxC;
    }
    REP(j,2,m){
        REP(i,1,n){
            double numnow = max( max(F[i][j-1], F[i-1][j-1]),F[i+1][j-1] );
            if (a[i][j]<0) F[i][j] = numnow / double(-a[i][j]);
                else F[i][j] = numnow + a[i][j];
        }
    }
    double res = F[1][m];
    REP(i,2,n){
        res = max(res, F[i][m]);
    }
    cout<< setprecision(3) << fixed <<res;
    return 0;

}
