#include <bits/stdc++.h>
#define task "BST"
#define REP(i,a,b) for(int i = a;i<=b; ++i)

using namespace std;

int S[1000], leaf[1000], R[1000], L[1000], a[1000];
int n;
int Build(int id, int l, int r){
    if (l>r) return 0;
    L[id] = l;
    R[id] = r;
    if ( l == r){
        leaf[l] = id;
        S[id] = a[l];
        return 0;
    }
    int mid = (l+r) / 2;
    Build(id*2, l, mid);
    Build(id*2+1, mid+1, r);
    S[id] = S[id*2] + S[id*2+1];
    return 0;
}
int update(int i, int v){
    int id = leaf[i];
    S[id] = v;
    while(id>1){
        id /= 2;
        S[id] = S[id*2] + S[id*2+1];
    }
    return 0;
}
int query(int id,int u, int v){
    int l = L[id];
    int r = R[id];
    if (v<l || u>r) return 0;
    if (u<=l && r<=v){
        return S[id];
    }
    return  query(id*2,u,v) + query(id*2+1,u,v);
}


int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    Build(1 , 1, n);
    update(1,2);
    int res = query(1,1,2);
    return 0;
}
