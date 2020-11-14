#include <bits/stdc++.h>
#define task "RBULL"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;
bool A[1005][1005];
int B[2010][2010], S[2010][2010];
int F1[1005][1005],F2[1005][1005],F3[1005][1005],F4[1005][1005];
int n,m;
int  u_res, v_res, r_res;
long long res;

int Init(){
    REP(i,1,n+m-1){
        REP(j,1,m+n-1){
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + B[i][j];
        }
    }
    return 0;
}
int makeF_array(){
    REP(i,1,n){
        REP(j,1,m){
            if (A[i][j] && (A[i-1][j] || A[i][j-1])) F1[i][j] = 1;
                else F1[i][j] = min(F1[i][j-1] , F1[i-1][j]) +1;
        }
    }
     for(int i =n; i>=1;--i){
        REP(j,1,m){
            if (A[i][j] && (A[i+1][j] || A[i][j-1])) F2[i][j] = 1;
                else F2[i][j] = min(F2[i+1][j] , F2[i][j-1]) +1;
        }
    }
     REP(i,1,n){
        for(int j = m; j>=1;--j){
            if (A[i][j] && (A[i-1][j] || A[i][j+1])) F3[i][j] = 1;
                else F3[i][j] = min(F3[i-1][j] , F3[i][j+1]) +1;
        }
    }
     for(int i=n;i>=1;--i){
        for(int j = m; j>=1;--j){
            if (A[i][j] && (A[i+1][j] || A[i][j+1])) F4[i][j] = 1;
                else F4[i][j] = min(F4[i][j+1] , F4[i+1][j]) +1;
        }
    }
    return 0;
}
int calc(int u, int v, int r){
    int lef = v - r +1;
    int rig = v + r -1;
    int xx = rig + u - 1;
    int yy = n - u + rig;
    int XX = lef + u -1 ;
    int YY = n - u + lef;
    return S[xx][yy] - S[XX-1][yy] - S[xx][YY-1] + S[XX-1][YY-1];
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    REP(i,1,n){
        REP(j,1,m){
            char x;
            cin>>x;
            A[i][j] = x=='*';
            B[i+j-1][n-i+j] = A[i][j];
        }
    }
    Init();
    makeF_array();
    res = -10000000;
    u_res = 0;
    v_res = 0;
    r_res = 0;
    REP(i,1,n){
        REP(j,1,m){
            int r = min(F1[i][j], min(F2[i][j], min(F3[i][j], F4[i][j])));
            int sum = calc(i,j,r);
            if (sum>res){
                res = sum;
                u_res = i;
                v_res = j;
                r_res =r-1;
            }
        }
    }
    cout<<res<<" "<<u_res<<" "<<v_res<<" "<<r_res;
    return 0;

}
