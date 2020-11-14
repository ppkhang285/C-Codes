#include <bits/stdc++.h>
#define task "CSC"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;
int n, a[1005], F[1005][105];
int Trace[1005][105], maxD, maxRes, maxId;
int FindPath(int i, int d){
    if (i == 0) return 0;
    FindPath(Trace[i][d], d);
    cout<<i<<" ";
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    REP(i,1,100) F[1][i] = 1;
    REP(i,2,n){
        REP(j,1,i-1){
            int d = a[i] - a[j];
            if (F[i][d] == 0) F[i][d] = 1;
            if (d>=0 && d<=100)
            if ( F[j][d] +1 > F[i][d]){
                F[i][d] = F[j][d] + 1;
                Trace[i][d] = j;
            }
            if (F[i][d] > maxRes){
                maxRes = F[i][d];
                maxD = d;
                maxId = i;
            }
        }
    }
    cout<<maxRes<<" "<<maxD<<"\n";
    FindPath(maxId, maxD);
    return 0;
}
