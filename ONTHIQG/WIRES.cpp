#include <bits/stdc++.h>
#define task "WIRES"
#define REP(i,a,b) for(int i = a;i<=b;++i)

using namespace std;
int n,k , a[100005];

int Check( long long X){
    int know = 0;
    REP(i,1,n) know += a[i] / X;
    return know;
}
long long Find(int L, int R){
    long long res = 0;
    while (L <= R){
       long long mid = (L+R) /2 ;
       int know = Check(mid);
       if( know < k ){
            R = mid-1;
       }
       else {
            L = mid+1;
            res = mid;
       }
    }
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>k;
    int sum = 0;
    REP(i,1,n){
        cin>>a[i];
        sum += a[i];
    }
    int R;
    R = sum / k;
    int res = Find(1, R);
    cout<<res;
    return 0;
}
