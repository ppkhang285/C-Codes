#include <bits/stdc++.h>
#define task "PRIMEMAX"
#define REP(i,a,b) for(int i=a; i<=b;++i)

using namespace std;

int n,a[100000];
string keys[100000];
map<int, int> F;
bool check_prime(int x){
    if (x==2) return true;
    if (x<2) return false;
    int q = trunc(sqrt(x));
    REP(i,2,q){
        if ((x % i) ==0) return false;
    }
    return true;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    int res1= 0;
    for(int i = n; i>=1 ;--i){
        if (check_prime(a[i]) && res1<a[i]){
            res1 = a[i];
        }
    }
    cout<<res1<<"\n";
    int maxnum =0 ;
    REP(i,1,n){
        F[a[i]]++;
        maxnum = max(maxnum, F[a[i]]);
    }
    REP(i,1,n){
        if (F[a[i]] == maxnum){
            cout<<a[i];
            break;
        }
    }
    return 0;
}
