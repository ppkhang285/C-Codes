#include <bits/stdc++.h>
#define task "BWPOINTS"
#define REP(i,a,b) for(int i = a; i<= b;++i)

using namespace std;
struct POINT{
    int p,color;
};
bool cmd(POINT a, POINT b){
    return a.p < b.p;
}
POINT A[200010];
int n;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    int N = n*2;
    REP(i,1,n){
        cin>>A[i].p;
        A[i].color = 0;
    }
    REP(i,1+n, n+n){
         cin>>A[i].p;
         A[i].color = 1;
    }
    sort(A+1,A+1+N,cmd);
    int res = 0;
    for(int i =1; i<N; i++){
        if (A[i].color != A[i+1].color){
            res++;
            i++;
        }
    }
    cout<<res;
    return 0;
}
