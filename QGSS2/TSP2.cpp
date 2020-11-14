#include <bits/stdc++.h>
#define task "TSP2"
#define REP(i,a,b) for(int i =a ;i<=b ++i)

using namespace std;

struct edge{
    int w, u,v;
};
struct connect{
    int n1, n2;
    bool is1 = true;
};

edge A[1005];
connect F[1005];
bool taken[1005];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int N = 0;
    cin>>n;
    REP(i,1,n)
        REP(j,1,n){
            cin>>x;
            if ( i<j){
                A[++N].u = i;
                A[N].v = j;
                A[N].v
            }
        }
}
