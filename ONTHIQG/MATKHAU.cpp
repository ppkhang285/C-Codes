#include <bits/stdc++.h>
#define task "MATKHAU"
#define REP(i,a,b) for(int i = a;i<=b; ++i)

using namespace std;
string S;
int C[1000005], L[1000005][4];

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>S;
    int n = S.length();
    REP(i,0,n-1){
        if (S[i]>= 'A' && S[i]<='Z') C[i+1] = 1;
        if (S[i]>= 'a' && S[i]<='z') C[i+1] = 2;
        if (S[i]>= '0' && S[i]<='9') C[i+1] = 3;
    }
    L[n+1][1] = n+1;
    L[n+1][2] = n+1;
    L[n+1][3] = n+1;
    for(int i = n; i>=1; --i){
        REP(j,1,3) L[i][j] = L[i+1][j];
        L[i][C[i]] = i;
    }
    int res = 0;
    REP(i,1,n-5){
        res += n - max( max(i+5, L[i][1]) , max(L[i][2], L[i][3])) + 1;
    }
    cout<<res;
    return 0;
}
