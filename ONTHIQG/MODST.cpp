#include <bits/stdc++.h>
#define task "MODST"
#define REP(x,i,j) for(int x=i;x<=j;++x)

struct Egde{
    int x[100000];
    int y[100000];
    int ts[100000];
};
Egde C;
int a[100000],res,par[100000],n,N;
using namespace std;

bool cmd(int i, int j){
    return(C.ts[i]<C.ts[j]);
}
int Find(int u){
    return (par[u]==u)?u:(par[u]=Find(par[u]));
}
int Merge(int u,int v){
    int x=Find(u);
    int y=Find(v);
    if (x==y) return 0;
    par[y]=par[x];
    return 1;
}

void SORT(int L, int R){
    int i=L;
    int j=R;
    int x=C.ts[(L+R)/2];
    do {
        while (C.ts[i]<x) i++;
        while (x<C.ts[j]) j--;
        if (i<=j){
            swap(C.x[i],C.x[j]);
            swap(C.y[i],C.y[j]);
            swap(C.ts[i],C.ts[j]);
            i++;j--;
        }
    } while (i<=j);
    if (L<j) SORT(L,j);
    if (i<R) SORT(i,R);
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;

    REP(i,1,n) cin>>a[i];
    N=0;
    REP(i,1,n-1)
        REP(j,i+1,n){
            N++;
            C.x[N]=i;
            C.y[N]=j;
            C.ts[N]=min(a[i] % a[j],a[j] % a[i]);
        }
    res=0;
    SORT(1,N);
    REP(i,1,N) par[i]=i;
    REP(i,1,N){
            int cmt=Merge(C.x[i],C.y[i]);
            res= (cmt==1)?res+=C.ts[i]:res;
    }
    cout<<res;
    return 0;
}
