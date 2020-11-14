#include <bits/stdc++.h>
#define task "DREAM"
#define REP(i,a,b) for(int i = a ; i<=b;++i)

using namespace std;

int c[105], d[10000];
int n,k;

struct MATRIX{
    int A[105][105];
    int N,M;
    MATRIX(){

    }
};
MATRIX MA,MB;
/*int MultTrix(int A[105][105], int B[105][105], int N, int M, int P){
    int C[105][105];
    memset(C, 0, sizeof(C));
    REP(i,1,N){
        REP(k,1,M){
            REP(j,1,P){
            C[i][j] += A[i][k]*B[k][j];
        }
    }
    }
    return C;
} */
MATRIX operator *(MATRIX Ai, MATRIX Bi){
    MATRIX res;
    memset(res.A, 0, sizeof(res.A));
    res.N = Ai.N;
    res.M = Bi.M;
    REP(i,1,Ai.N){
        REP(k,1,Ai.M){
            REP(j,1,Bi.M){
                res.A[i][j] += Ai.A[i][k] * Bi.A[k][j];
            }
        }
    }
    return res;
}

MATRIX POWERMA(int k){
    if (k==1) return MA;
    MATRIX tmp = POWERMA(k/2);
    if (k &2 ==0) return tmp*tmp;
        else return tmp*tmp*MA;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>k;
    REP(i,1,n){
        cin>>d[i];
        c[d[i]]++;
    }
    //Make A;
    MA.N = 101;
    MA.M =  101;
    MA.A[1][1] = 1;
    REP(i,2,100) MA.A[1][i] = MA.A[2][i] =  c[i-1];
    MA.A[2][1] =  1;
    REP(i,3,102)
    REP(j,1,101){
        MA.A[i][j] = (j-1==i-2)?1:0;
    }
    //Make B
    MB.A[1][1] = 1;
    MB.A[2][1] = 1;
    MB.N = 101;
    MB.M = 1;
    //
    MATRIX D = POWERMA(k);

    return 0;
}
