#include <bits/stdc++.h>
#define task "TSP"
#define REP(i,a,b) for(int i = a; i<=b; ++i)
#define oo 100000
using namespace std;
typedef pair<int, int> ii;
vector<int> C[22];
int bestSol,n, x[22], a[22][22] , res[22];
bool Free[22];
int brutalForce(int i, int v){
    if (i == 1) return 0;
    for(auto t:C[x[i-1]]){
        if (t == x[i-1] || Free[t] == false) continue;
        if (a[t][x[i-1]] + v >= bestSol) continue;
        if (i==n && a[t][1] >0 && v + a[t][x[i-1]] + a[t][1] < bestSol){
            bestSol = v + a[t][x[i-1]] + a[t][1];
            x[i] = t;
            Free[t] = false;
            REP(z,1,n+1)
                res[z] = x[z];
        }


        if (i==n) { Free[t] = true;
                continue;}
        x[i] = t;
        Free[t] = false;
        brutalForce(i+1, v + a[t][x[i-1]]);
        Free[t] = true;
    }
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n)
        REP(j,1,n){
            cin>>a[i][j];
            if (a[i][j]>0) C[i].push_back(j);
        }
    bestSol = oo;
    memset(Free,true,sizeof(Free));
    Free[1] = false;
    x[1] = 1;
    x[n+1] = 1;
    brutalForce(2,0);
    if (bestSol !=oo){
        cout<<bestSol<<"\n";
        cout<<"1";
        REP(i,2,n+1) cout<<"->"<<res[i];
    }
    return 0;
}
