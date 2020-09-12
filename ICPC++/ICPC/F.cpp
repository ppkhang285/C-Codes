#include <bits/stdc++.h>
#define task "F"
bool dd={false};
bool free;
int trace,a;
int DFS(int u){

    if (u==s) {
        int longd=0;
        int g=s;
        int mind=100000000;
        while (g != t){
            if (mind>a[g,trace[g]){ mind=a[g,trace[g];}
            g=trace[g];
            longd+=1;
        }
        D[s,t]=longd*mind;
        D[t,s]=D[s,t];
    }
    for (int v=1 ; v<=n; v++){
        if (free[v]==true && dd[u,v]==true){
               free[u]=false;
               trace[v]=u;
               DFS(v);
               free[u]=true;
        }
    }
return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
     cin>>n,m;
     for (int i=1; i<=m;i++){
        int u,v;
        cin>>u,v,a[u,v];
         a[v,u]=a[u,v];
         dd[u,v]=true;
         dd[v,u]=true;
     }
     for (int i=1 ; i<n ; i++){
        for (int j=i+1; j<=n; j++){
            free={true};
            trace=0;
            DFS(i,j);
            res=res+D[i,j];
        }
     }
     cout<<res;
     return 0;
}
