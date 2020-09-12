#include <bits/stdc++.h>
#define task "ZQM"
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define Nmax 200005
using namespace std;

int n,a[Nmax] , b[Nmax]  , N;
double d[Nmax];


int print_res(){
    sort(d+1 , d+1+N);
    int ans=1;
    int now=1;
    REP(i,2,N){
        if (d[i]==d[i-1]) now++;
            else{
                ans=max(ans,now);
                now=1;
            }
    }
    ans = max(ans, now);
    cout<<ans;
    return 0;
}

int zeroRes(){
    cout<<"0";
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    //
    cin>>n;
    N=0;
    REP(i,1,n) cin>>a[i];
    REP(i,1,n) cin>>b[i];
    //
    REP(i,1,n){
        if (a[i]==0) continue;
        double now =  - double(b[i] ) / double(a[i]);
        N++;
        d[N] = now;
    }
    if (N==0) zeroRes();
    else
            print_res();

    return 0;

}
