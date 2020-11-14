#include <bits/stdc++.h>
#define task "STREET"
#define REP(i,a,b) for(int i = a; i<= b; ++i)
#define M 1000000000000000000
using namespace std;
typedef long long ll;
int n, N;
ll Street[4050];
ll pow3[40], pow5[30], pow7[30];

int createPow(){
    pow3[0] = 1;
    pow5[0] = 1;
    pow7[0] = 1;
    REP(i,1,37) pow3[i] = pow3[i-1] * 3;
    REP(i,1,25) pow5[i] = pow5[i-1] * 5;
    REP(i,1,22) pow7[i] = pow7[i-1] * 7;
    return 0;
}
int createStreet(){
    ll now = 1;
    REP(i,0,37){
        now *= pow3[i];
        REP(j,0, 25 ){
           if (M/now < pow5[j]) break;
           now *= pow5[j];
           REP(k, 0,  22){
               if (M/now < pow7[k]) break;
                now *= pow7[k];
                if (now>1) Street[++N] = now;
                now /= pow7[k];
           }
           now /= pow5[j];
        }
        now /= pow3[i];
    }

    return 0;
}
int Find(ll x){
    if (x % 2 == 0){
        return 0;
    }
    int L = 1;
    int R = N;
    int res = 0;
    while (L<= R){
        int mid = (L+R) >>1;
        if ( x == Street[mid]){
            res = mid;
        }
        if (Street[mid] < x) L = mid + 1;
            else R = mid -1;
    }
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    N = 0;
    createPow();
    createStreet();
    sort(Street+1, Street+1+N);
    while(true){
        ll x = 0;
        cin>>x;
        if (x == 0) break;
        int k = Find(x);
        if(k == 0) cout<<"N\n";
        else if ( k % 2 == 1) cout<<"L\n";
            else cout<<"R\n";
    }

    return 0;
}
