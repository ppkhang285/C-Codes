#include <bits/stdc++.h>
#define task "TRAVEL12"
#define REP(i,a,b) for(int i = a; i <= b ;++i)

using namespace std;
typedef bitset<10005> bs;
typedef vector<vector<int>> vv;
int n,m;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin>>n>>m;
    bs bit[n+5];
    vv C(n+5);
    REP(i,1,m){
        int u,v;
        cin>>u>>v;
        if (bit[u].test(v) ==false){
            C[u].push_back(v);
            C[v].push_back(u);
            bit[u].set(v);
            bit[v].set(u);
        }
    }
    REP(u,1,n){
        bs Cof;
        for(int v: C[u]){
            bit[v][u] = false;
            if ( (Cof & bit[v]).any()){
                Cof = Cof & bit[v];
                int w1 = 1;
                while (Cof[w1] == false) w1++;
                for (int w2:C[w1])
                    if (bit[u][w2] == true){
                        cout<<u<<" "<<v<<" "<<w1<<" "<<w2;
                        return 0;
                    }
            }
            else Cof = Cof | bit[v];
            bit[v][u] = true;
        }
    }
    cout<<-1;
    return 0;
}
