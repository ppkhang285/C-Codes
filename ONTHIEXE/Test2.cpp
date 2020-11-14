#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = a; i<= b;++i)
#define task "DIJHEAP"
#define pair<int,int> pp
#define first X
#define second Y

using namespace std;

vector< pair<int,int> > a;
int n,m;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(make_pair(v,w));
    }
    return 0;
}
