#include <bits/stdc++.h>
#define task "NKDIVSEQ"
#define REP(i,a,b) for(int i = a;i<=b;++i)

using namespace std;
int n;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    int mod = 1;
    long long res = 1;
    REP(i,2,n){
        if (i > (mod)*(mod+1)/2){
            mod++;
            res = res + mod- (res % mod);
        }
        else res += mod;
    }
    cout<<res;
    return 0;
}
