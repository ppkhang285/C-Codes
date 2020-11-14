#include <bits/stdc++.h>
#define task "LINE"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

map<iii, int> m;
int n;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    int res = 0;
    REP(i,1,n){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
        int u = x2 - x1;
        int v = y2 - y1;
        //cout<<d<<" "<<u<<" "<<v<<"\n";
        res += m[iii(d, ii(-v,u))] + m[iii(d, ii(v,-u))];
        m[iii(d, ii(u,v))]++;
    }
    cout<<res;
    return 0;
}
