#include <bits/stdc++.h>
#define task "NKREZ"
#define REP(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
struct room{
    int start, endf;
    bool operator<(const room& a){
        return endf<a.endf;
    }
};
int n,F[10005];
room A[10005];
int findind(int L, int R, int X){
    int res = 0;
    do{
        int mid = (L+R)/2;
        if (A[mid].endf <= X){
            res = mid;
            L = mid+1;
        }
        else R = mid-1;
    }
    while(L<=R);
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>A[i].start>>A[i].endf;
    sort(A+1,A+1+n);
    F[0] = 0;
    REP(i,1,n){
        int k = findind(1, i, A[i].start);
        F[i] = max(F[i-1], F[k] + A[i].endf - A[i].start);
    }
    cout<<F[n];
    return 0;
}
