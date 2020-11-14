#include <bits/stdc++.h>
#define task "SEQPART"
#define REP(i,a,b) for(int i = a ; i<=b;++i)
#define
using namespace std;


int n,G;
int a[8005], S[8005], F[805][8005];

int cost(int i, int j ){
    return (j-i+1)*(S[j]-S[i-1]);
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>G;
    REP(i,1,n) cin>>a[i];
    S[0] = 0;
    REP(i,1,n) S[i] = S[i-1] + a[i];
    REP(g,1,G){
        REP(i,1,n){
            if (g==1) F[g][i] = cost(1,i);
            else{
                F[g][i] = oo;
                REP(k,0,i){
                    int newcost = F[g-1][k] + cost(k+1,i);
                    if (F[g][i] > newcost) F[g][i] = newcost;
                }
            }
        }
    }
    return 0;
}
