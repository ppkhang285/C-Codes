#include <bits/stdc++.h>
#define task "TIENKS"
#define REP(i,a,b) for(int i =a ;i<=b ; ++i)
using namespace std;
struct room{
    int start, finish, cost;
};
room a[12000];
int n,L[12000], F[12000];
bool cmd( room i, room j){
    return i.finish<j.finish;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin>>n;
    REP(i,1,n) cin>>a[i].start>>a[i].finish>>a[i].cost;
    sort(a+1,a+1+n,cmd);
    L[0] = 0;
    REP(i,1,n){
        L[i] = a[i].cost;
        REP(j,1,i-1){
            if (a[j].finish <= a[i].start && L[i] < L[j] +a[i].cost) L[i] = L[j]+a[i].cost;
        }
    }
    cout<<L[n];
    return 0;
}
