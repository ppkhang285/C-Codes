#include <bits/stdc++.h>
#define task "QBPOINT"
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
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i].X>>a[i].Y;
    int res = 0;
    REP(i,1,n-2){
        map<ii, int> m;
        REP(j,i+1,n){
            int Upper = a[j].Y - a[i].Y;
            int Lower = a[j].X - a[i].X;
            Simplify(Upper, Lower);
            ii k = ii(Upper, Lower);
            if ( m[k] > 0){
                res += m[k];
            }
            m[k]++;
        }
    }
    cout<<res;
    return 0;
}
