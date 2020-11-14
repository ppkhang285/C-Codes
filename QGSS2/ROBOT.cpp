#include <bits/stdc++.h>
#define task "ROBOT"
#define REP(i,a,b) for(int i = a; i<=b; ++i)

using namespace std;
char A[105][105];
string F[105][105];
int n;

string minBit(string X, string Y){
    int L = X.size();
    //string res;
    REP(i,0,L-1){
        if (X[i] < Y[i]){
            return X;
        }
        if (X[i] > Y[i]){
            return Y;
        }
    }
    return X;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n)
        REP(j,1,n) cin>>A[i][j];
    F[1][1] = A[1][1];
    REP(i,2,n){
        F[1][i] = F[1][i-1] + A[1][i];
        F[i][1] = F[i-1][1] + A[i][1];
    }
    REP(i,2,n){
        REP(j,2,n){
            F[i][j] = minBit( F[i-1][j], F[i][j-1] ) + A[i][j];
        }
    }
    cout<<F[n][n];
    return 0;
}
