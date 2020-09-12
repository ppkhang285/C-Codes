#include <bits/stdc++.h>
#define REP(i,a,b) for(int i =a; i<=b;i++)
#define task "PRIMECOUNT"

using namespace std;

int count_prime(int L, int R){
    int i;
    int res = R-L+1;
    for(int i =2 ; i*i <=R ; i++){
        for (int j = max(i*i,(L+i-1) / (i*i)) ; j<=R ; j+=i){
            res--;
        }
    }
    if (i>=L) res--;
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int T;
    cin>>T;
    REP(i,1,T){
        int L,R;
        cin>>L>>R;
        cout<<count_prime(L,R);
    }
    return 0;

}
