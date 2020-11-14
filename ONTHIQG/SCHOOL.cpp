#include <bits/stdc++.h>
#define task "LIS"
#define REP(i,a,b) for(int i =a; i<=b;++i)
#define oo 10000
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;

vector<ii> a[10005];
vector<ii> b[10005];
int DHome[10005], DOffice[10005], DSchool[10005];
int n,m,k;
int CarFromHome(){
    //memset(DHome, oo, sizeof(DHome));
    REP(i,1,n) DHome[i] = oo;
    DHome[1] = 0;
    bool Free[10005];
    memset(Free, true, sizeof(Free));
    priority_queue<ii, vector<ii>, greater<ii> > PQ;
    PQ.push(ii(0,1));
    while(PQ.size() > 0){
        int u = PQ.top().Y;
        int dd = PQ.top().X;
        PQ.pop();
        if (Free[u] == false || u ==0) continue;
        Free[u] = false;
        for(auto t:b[u]){
            int v = t.X;
            int ss = t.Y;
            if ( Free[v] || DHome[v] > dd + ss ){
                DHome[v] = dd + ss;
                PQ.push(ii(DHome[v], v));
            }

        }
    }
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    REP(i,1,m){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        a[u].push_back(ii(x,v));
        b[u].push_back(ii(y,v));
    }
    CarFromHome();
    return 0;

}
