#include <bits/stdc++.h>
#define task "SQUARE01"
#define REP(i,a,b) for(int i = a; i<=b ;++i)
using namespace std;

int n,m, A[1005][1005],F[1005][1005];
int Find_With_0(int i, int j, int L, int R){
    int res = 0;
    do{
        int mid = ( L + R ) / 2;
        if (F[i-j+mid][mid] - F[i-1][mid] - F[mid-j+i][j-1] + F[i-1][j-1] == 0){
            res = -j + mid + 1;
            L = mid+1;
        }
        else R = mid - 1;
    }
    while (L <= R);
    return res;
}
int Find_With_1(int i, int j, int L, int R){
    int res = 0;
    do{
        int mid = ( L + R ) / 2;
        if (F[i+ mid - j][mid] - F[i-1][mid] - F[mid-j+i][j-1] + F[i-1][j-1] == (mid - j +1)*(mid - j +1) ){
            res = mid - j + 1;
            L = mid+1;
        }
        else R = mid - 1;
    }
    while (L <= R);
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    int result = 0;
    REP(i,1,n)
        REP(j,1,m)
            cin>>A[i][j];
    F[1][1] = A[1][1];
    REP(j,1,m) F[1][j] = F[1][j-1] + A[1][j];
    REP(i,1,n) F[i][1] = F[i-1][1] + A[i][1];
    REP(i,2,n)
        REP(j,2,m)
            F[i][j] = F[i][j-1] + F[i-1][j] - F[i-1][j-1] + A[i][j];
    REP(i,1,n){
        REP(j,1,m){
            if (A[i][j] == 0) result = max(result , Find_With_0(i,j, j+1, m));
                else result = max(result , Find_With_1(i,j, j+1, m));
        }
    }
    cout<<result;
    return 0;
}
