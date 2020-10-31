#include <bits/stdc++.h>
#define task "SCHOOL"
#define REP(i,a,b) for(int i =a; i<=b;++i)
#define oo 1000000
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;

vector<ii> a[10005];
vector<ii> b[10005];
vector<ii> nb[10005];
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
            int v = t.Y;
            int ss = t.X;
            if ( Free[v] || DHome[v] > dd + ss ){
                DHome[v] = dd + ss;
                PQ.push(ii(DHome[v], v));
            }

        }
    }
    return 0;
}
int CarToOffice(){
    //memset(DHome, oo, sizeof(DHome));
    REP(i,1,n) DOffice[i] = oo;
    DOffice[n] = 0;
    bool Free[10005];
    memset(Free, true, sizeof(Free));
    priority_queue<ii, vector<ii>, greater<ii> > PQ;
    PQ.push(ii(0,n));
    while(PQ.size() > 0){
        int u = PQ.top().Y;
        int dd = PQ.top().X;
        PQ.pop();
        if (Free[u] == false || u ==0) continue;
        Free[u] = false;
        for(auto t:nb[u]){
            int v = t.Y;
            int ss = t.X;
            if ( Free[v] && DOffice[v] > dd + ss ){
                DOffice[v] = dd + ss;
                PQ.push(ii(DOffice[v], v));
            }

        }
    }
    return 0;
}int WalkToSchool(){
    //memset(DHome, oo, sizeof(DHome));
    REP(i,1,n) DSchool[i] = oo;
    DSchool[k] = 0;
    bool Free[10005];
    memset(Free, true, sizeof(Free));
    priority_queue<ii, vector<ii>, greater<ii> > PQ;
    PQ.push(ii(0,k));
    while(PQ.size() > 0){
        int u = PQ.top().Y;
        int dd = PQ.top().X;
        PQ.pop();
        if (Free[u] == false || u ==0) continue;
        Free[u] = false;
        for(auto t:a[u]){
            int v = t.Y;
            int ss = t.X;
            if ( Free[v] && DSchool[v] > dd + ss ){
                DSchool[v] = dd + ss;
                PQ.push(ii(DSchool[v], v));
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
        a[v].push_back(ii(x,u));
        b[u].push_back(ii(y,v));
        nb[v].push_back(ii(y,u)); // mang dao cua b
    }

    CarFromHome();
    CarToOffice();
    WalkToSchool();
    int res = oo;
    REP(i,1,n){
        if (DHome[i] + DSchool[i] < 60) res = min(res, DHome[i] + DOffice[i]);
    }
    cout<<res;
    return 0;

}
