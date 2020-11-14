#include <bits/stdc++.h>
#define task "RLINE"
#define REP(i,a,b) for(int  i = a; i<=b ; ++i)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
set<int> S;
iii P[300005];
int Cover[300005];
int n;

/*bool comp(iii a, iii b){
    return a.X < b.X;
}*/
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n){
        int a,b;
        cin>>a>>b;
        P[i*2- 1] = iii(ii(a,i), 1);
        P[i*2] = iii(ii(b,i), 2);
    }
    sort(P +1, P+1+2*n);
    S.clear();
    int T =0;
    int u = 0;
    int lines = 0;
    REP(i,1,2*n){
        if (P[i].Y == 1){
            int v = P[i].X.X;
            if (lines == 1){
                int id = *S.begin();
                Cover[id] += v - u;
            }
            if (lines >0) T += v - u;
            lines++;
            S.insert(P[i].X.Y);
            u = v;
        }
        else{
            int v = P[i].X.X;
            if (lines == 1){
                int id = *S.begin();
                Cover[id] += v - u;
            }
            if (lines >0) T += v - u;
            lines--;
            S.erase(P[i].X.Y);
            u = v;
        }
    }
    int res = 0;
    REP(i,1,n) res = max(res, T - Cover[i]);
    cout<<res;
    return 0;
}
