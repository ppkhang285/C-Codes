#include <bits/stdc++.h>
#define task "MGAME"
#define rep(i,a,b) for(int i =a ;i <=b ;++i)
using namespace std;
long long  n;
int k,F[11];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>k>>n;
    rep(i,0,9) F[i] =  i;
    //
    if (k==1){
        F[2] = 4;
        F[3] = 9;
        F[4] = 6;
        F[7] = 9;
        F[8] = 4;
        F[9] = 1;
    }
    else if (k>1){
        F[2] = 6;
        F[3] = 1;
        F[4] = 6;
        F[7] = 1;
        F[8] = 6;
        F[9] = 1;
    }
    if (n<=9){
        int tong =0;
        rep(i,1,n) tong+=F[i];
        cout<<tong %10;
    }
    else{
        int tong = 0;
        rep(i,1,9) tong+=F[i];
        tong = tong % 10;
        int res = 0;
        long long lap = n / 10;
        int du =  n % 10 ;
        res = ( (tong % 10) * (lap % 10) ) % 10;
        tong = 0;
        rep(i,1,du) tong+=F[i];
        res = (res + tong%10) %10;
        cout<<res;

    }
    return 0;
}
