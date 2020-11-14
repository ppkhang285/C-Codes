#include <bits/stdc++.h>
#define task "LINES"
#define REP(i,a,b) for(int i =a ; i<=b; ++i)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;

ii a[2005];
int n;
int gcd(int a, int b){
    int tmp;
    while (b!=0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
int Simplify(int &a, int &b){
    int g = gcd(a,b);
    a /= g;
    b /= g;
    return 0;
}
int solve(){
    REP(i,1,n) cin>>a[i].X>>a[i].Y;
    set<ii> m;
    REP(i,1,n-1){
        REP(j,i+1,n){
            int Upper = a[j].Y - a[i].Y;
            int Lower = a[j].X - a[i].X;
            Simplify(Upper, Lower);
            ii k = ii(Upper, Lower);
            m.insert(k);
        }
    }
    cout<<m.size()<<"\n";
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    while(true){
        cin>>n;
        if (n==0) return 0;
        solve();
    }
    return 0;
}

