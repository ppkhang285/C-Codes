#include <bits/stdc++.h>
#define task "DOTHI2"
#define REP(i,a,b) for(int i=a ; i<=b ;  i++)

using namespace std;
struct EDG{
    int u,v ,w;
};
EDG C[100];
bool cmd(EDG i, EDG j){
    return (i.w< j.w);
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int u,v,w;
    int m =0,n =0;
    while (cin>>u>>v>>w){
        n = max(n , max(u,v));
        C[++m].u =u;
        C[m].v= v;
        C[m].w =w;
    }
    sort(C+1, C+1+m , cmd);
    REP(i,1,m)
        cout<<C[i].u<<" "<<C[i].v<<" "<<C[i].w<<"\n";
    return 0;
}
