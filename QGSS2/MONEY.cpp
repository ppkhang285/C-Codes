#include <bits/stdc++.h>
#define task "MONEY"
#define REP(i,a,b) for(int i = a ; i<=b; ++i)

using namespace std;
int a[105], F[105][10005];
int n,m;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,n) cin>>a[i];

    REP(j,1,a[1]) F[1][j] = 1;
    REP(i,2,n){
        F[i][a[i]] +=1;
        REP(j, 1,m){
                if (j - a[i] <0) F[i][j]+=1; else
                 F[i][j] += F[i-1][j] + F[i-1][j - a[i]];
            }
        }
    cout<<F[n][m];
    return 0;
}
