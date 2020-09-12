#include <bits/stdc++.h>
#define task "PPATH"
#define REP(i,a,b) for(int i=a; i<=b ;i++)
#define Nmax 9999
using namespace std;
bool NT[Nmax+1], Free[Nmax];
int N,Prime[Nmax], Dis[Nmax], n;
vector<int> ED[Nmax];
queue<int> Q;
int setUp(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    return 0;
}
int erathos(){
    memset(NT, true , sizeof(NT));

    NT[1]= false;
    NT[0] = false;
    NT[2]= true;
    REP(i,2, sqrt(Nmax)){
        for(int j = i*i; j<=Nmax ;j+=i){
            NT[j] =false;
        }
    }
    return 0;
}
int getPrimeList(){
    N=0;
    REP(i,1001, Nmax){
        if (NT[i]){
            Prime[++N] = i;
        }
    }
    return 0;
}
bool check(int x, int y){
    int diff =0;
    REP(i,1,4){
        if (x%10 !=y%10)
            diff++;
        x= x /10;
        y = y /10;
    }
    if (diff == 1) return true;
        else
            return false;
}
int makeED(){
    REP(i,1,N){
        REP(j,i+1,N){
            if ( check(Prime[i], Prime[j])){
                ED[Prime[i]].push_back(Prime[j]);
                ED[Prime[j]].push_back(Prime[i]);

            }
        }
    }
    return 0;
}
int EmptyQ(){
    queue<int> emptyy;
    swap(Q, emptyy);
    return 0;
}
int BFS(int a, int b){
      memset(Free, true, sizeof(Free));
      memset(Dis, 0, sizeof(Dis));
      EmptyQ();
      Q.push(a);
      Dis[a]=0;
    do{
        if (Q.size() == 0) return 0;
        int u= Q.front();
        Q.pop();
        if (u==b) return 0;
        for( unsigned int i=0; i< ED[u].size() ;i++ ){
            int v= ED[u][i];
            if (Free[v]== true){
                Q.push(v);
                Free[v]= false;
                Dis[v] = Dis[u]+1;
            }
        }
    }
    while (true);
    return 0;
}
int main(){
    setUp();
    erathos();
    getPrimeList();
    makeED();
    int a,b;
    cin>>n;
    REP(z,1,n){
        cin>>a>>b;
      if (a==b) cout<<"0\n";
        else{
        BFS(a,b);
        if (Free[b]==true) cout<<"Impossible\n";
            else cout<<Dis[b]<<"\n";
        }
    }
    return 0;
}
