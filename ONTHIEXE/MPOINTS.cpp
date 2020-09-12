#include <bits/stdc++.h>
#define task "MPOINTS"
#define REP(x,i,j) for(int x=i;x<=j;x++)
#define oo 100000000000000000
#define X first
#define Y second
using namespace std;

typedef pair<long long, long long> ii;
vector<ii> a[100005];
int n,m,k,d1[100000],d2[100000];
int dfs1(){
     REP(i,1,n) d1[i]=oo;
     d1[1]=0;
     priority_queue<ii , vector<ii>, greater<ii>> ED;
     ED.push(ii(0,1));
     while (ED.size()){
        int u=ED.top().Y;
        int dd=ED.top().X;
        if (u==0) return 0;
        ED.pop();
        for( auto eded:a[u]){
            int v=eded.Y;
            int uv=eded.X;
            if (d1[v]> dd+uv){
                d1[v]=dd+uv;
                ED.push(ii(d1[v],v));
            }
        }
     }
}
int dfsn(){
     REP(i,1,n) d2[i]=oo;
     d2[n]=0;
     priority_queue<ii , vector<ii>, greater<ii>> ED;
     ED.push(ii(0,n));
     while (ED.size()){
        int u=ED.top().Y;
        int dd=ED.top().X;
        if (u==0) return 0;
        ED.pop();
        for( auto eded:a[u]){
            int v=eded.Y;
            int uv=eded.X;
            if (d2[v]> dd+uv){
                d2[v]=dd+uv;
                ED.push(ii(d2[v],v));
            }
        }
     }
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>k;
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        if (u!=v) a[u].push_back(ii(w,v));
    }
    REP(i,1,n) a[i].push_back(ii(0,0));
    dfs1();
    dfsn();
    REP(i,1,k){
        long long q,p;
        cin>>p>>q;
        long long res=oo;
        REP(j,1,n) res=min(res,p*d1[j]+q*d2[j]);
        cout<<res<<"\n";
    }
    return 0;
}
