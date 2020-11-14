#include <bits/stdc++.h>
#define task "TEAM"
#define REP(i,a,b) for(int i = a ;i<=b;++i)
#define A first
#define B second
using namespace std;
typedef long long LL;
typedef pair<int, int> ii;

ii teamMate[200005];
int dPos[200005];
int n;

bool comp(ii a, ii b){
    return a.B<b.B;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    REP(i,1,n) cin>>teamMate[i].A>>teamMate[i].B;
    sort(teamMate+1, teamMate+1+n, comp);
    dPos[n] = teamMate[n].A;
    for(int i = n-1; i>=1;--i) dPos[i] = min(dPos[i+1], teamMate[i].A);
    LL s = 0;
    LL dNow = 0;
    REP(i,1,n){
        s += teamMate[i].B;
        if (i >1) dNow = max(dNow, LL(teamMate[i].B - teamMate[i].A)); else dNow = teamMate[i].B - teamMate[i].A;
        LL res =  min(s - teamMate[i].B + dPos[i], s - dNow );
        cout<<res<<"\n";
    }
    return 0;
}
