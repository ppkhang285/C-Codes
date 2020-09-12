#include <bits/stdc++.h>
#define task "KAGAIN"
#define REP(i,a,b) for(int i = a; i<=b; ++i)


using namespace std;
int n, A[1000],D[1000],L[1000],R[1000];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>A[i];
    D[0] = 0;
    int top = 0;
    REP(i,1,n){
        while(top > 0 && A[D[top]] >= A[i]) --top;
        L[i] = D[top] + 1;
        D[++top] = i;
    }
    memset(D,0,sizeof(D));
    top = 0;
    D[0] = n + 1;
    for(int i = n; i>=1; --i){
        while (top > 0 && A[D[top]] >= A[i]) --top;
        R[i] = D[top] - 1;
        D[++top] = i;
    }
    int res = 0;
    REP(i,1,n){
        res = max(res, (R[i] - L[i] +1)*A[i]);
    }
    cout<<res;
    return 0;
}
