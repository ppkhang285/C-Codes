#include <bits/stdc++.h>
#define task "NENDAYSO"
using namespace std;

long long n,res,MOD;
long long sqr(long long x){
    return x*x;
}
long long moldule(int a, long long b, int MOD){
    if (b==0) return 1%MOD;
    else
        if (b%2 == 0){
            return sqr(moldule(a, b/2,MOD)) %MOD;
        }
        else{
            return (a* sqr(moldule(a,b/2,MOD))%MOD) % MOD;
        }
}
void let_do_it(long long n){
    long long B = moldule(2,n-2,MOD);
    long long C = (n+1)% MOD;
    res = (B * C) % MOD;
    cout<<res<<"\n";
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    MOD = 1000000000;
    for(int i =1; i<=10;++i){
        cin>>n;
        if (n <=1) cout<<"1\n";
        else
            let_do_it(n);
    }
    return 0;
}
