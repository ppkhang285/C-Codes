#include <bits/stdc++.h>
#define task "PATH"
#define REP(i,a,b) for(int i=a; i<=b ; i++)
#define oo 10000000
using namespace std;

struct EDGED{
    int u,v,w;
};

EDGED ED[1000];
int n,m,c[1000][1000] , res[1000];

int ReadInput(){
    //
    ios_base::sync_with_stdio(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    //DOc input
    cin>>n>>m;
    //Init Array
    REP(i,1,n){
        REP(j,1,n){
            if (i==j){
                c[i][j]=0;
            }
            else{
                c[i][j]=oo;
            }
        }
    }
    //
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        c[u][v]=w;
        ED[i].u=u;
        ED[i].v=v;
        ED[i].w=w;
    }
    return 0;
}

int FLOYD(){
    REP(k,1,n){
        REP(i,1,n){
            REP(j,1,n){
                if (c[i][j] > c[i][k]+c[k][j]){
                    c[i][j]=c[i][k]+ c[k][j];
                }
            }
        }
    }
    return 0;
}

int Find_Cross(int t){
    if (t==m+1) return 0;
    int u=ED[t].u;
    int v=ED[t].v;
    int w=ED[t].w;
    REP(i,1,n){
        REP(j,1,n){
            if (i!=j){
                if (c[i][u] + c[v][j] + w == c[i][j]){
                    res[t]++;
                }
            }
        }
    }
    Find_Cross(t+1);
    return 0;
}

int Write_Res(){
    REP(i,1,m){
        cout<<res[i]<<"\n";
    }
    return 0;
}
int main(){
    ReadInput();
    FLOYD();
    Find_Cross(1);
    Write_Res();

}
