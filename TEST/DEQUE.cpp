#include <bits/stdc++.h>
#define task "DEQUE"
#define REP(i,a,b) for(int i = a; i<=b; ++i)


using namespace std;
int A[1000],L[1000],R[1000],n,D[1000];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>A[i];
    int top = 0;
    D[0] = 0;
    //L[i] -1
    REP(i,1,n){
        while (top>0 && A[D[top]] >= A[i]) --top;
        L[i] = D[top] +1;
        D[++top] = i;
    }
    //R[i] +1
    memset(D,0,sizeof(D));
    D[0] = n+1;
    top = 0;
    for(int i = n;i>=1;--i){
        while (top > 0 && A[D[top]] >=A [i]) --top;
        R[i] = D[top] -1;
        D[++top] = i;
    }
    REP(i,1,n) cout<<L[i]<<" ";
    cout<<"\n";
    REP(i,1,n) cout<<R[i]<<" ";


}
