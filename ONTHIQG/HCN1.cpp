#include <bits/stdc++.h>
#define task "HCN1"
#define REP(i,a,b) for(int i =a; i<=b; ++i)
using namespace std;
int a[1000][1000],n,m,H[1000][1000];
pair<int,int> D1,D2;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,n)
        REP(j,1,m)cin>>a[i][j];
    memset(H,0,sizeof(H));
    //H[i][j] la do cao cua HCN co chieu rong = 1 co dinh la i,j
    //  1
    //  1
    //  1  =>H[i][j] = 3
    //  1  =>H[i][j] = 4
    REP(i,1,n)
        REP(j,1,m){
            if (a[i][j] == 0) H[i][j] = 0;
                else H[i][j] = H[i-1][j] +1;
        }
    int ans = 0;
    // Duyệt từng dòng, nếu HCN có đỉnh bên phải nằm ở dòng i => S = (j-i+1)* min(H[i], H[i+1],..H[j]) ( 1<=i,j<=m)
    // => Dùng Deque để tìm min max=> Định H[i][j] là min => S = H[i][j]*(R[i]-L[i] +1)
    REP(i,1,n){
        int D[1000] = {0};
        int top = 0;
        int L[1000]={0},R[1000] = {0};
        REP(j,1,m){
            while (top>0 && H[i][D[top]] >= H[i][j]) top--;
            L[j] = D[top] +1;
            D[++top] = j;
        }
        top = 0;
        memset(D,0,sizeof(D));
        D[0] = m+1;
        for(int j =m;j>=1; --j){
            while (top>0 && H[i][D[top]] >= H[i][j]) top--;
            R[j] = D[top] -1 ;
            D[++top] = j;
        }
        REP(j,1,m){
            if (ans < H[i][j]*(R[j] - L[j] +1)){
                ans = H[i][j]*(R[j] - L[j] +1);
                D1 = {i-H[i][j] + 1 , L[i]};
                D2 = {i,R[i]};
            }
        }
    }
    cout<<ans<<"\n";
    cout<<D1.first<<" "<<D1.second<<"\n";
    cout<<D2.first<<" "<<D2.second;
    return 0;
}
