#include <bits/stdc++.h>
#define task "STNODE"
#define REP(i,a,b) for(int i = a; i <= b ; ++i)
#define Nmax 10005

using namespace std;

vector<int> ke[10000];
queue<int> q;
queue<int> standQ;
bool Visited[10000];
int Find_Path_BFS(){
    q = standQ;
    q.push(s);
    Visited[s] = false;
    do{
        int u = (int)q.front();
    }
    while (true);

}
int main(){
    //open and read after eating
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    REP(i,1,m){
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
    }


}
