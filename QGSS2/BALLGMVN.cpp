#include <bits/stdc++.h>
#define task "BALLGMVN"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define X first
#define Y second
using namespace std;//He so goc By-Ay/Bx-Ax
typedef pair<int, int> ii;
ii a[2010];
int n;
int gcd(int a, int b) {//Euclid
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int simp(int &a, int &b){ //Toi gian phan so
    int Gcd = gcd(a,b);
    a /= Gcd;
    b /= Gcd;
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    n*=2;
    REP(i,1,n) cin>>a[i].X>>a[i].Y;
    //TH1
    REP(i,1,n/2){
        map<ii, int> k;
        REP(j,n/2+1, n){
            int Upper = a[j].Y - a[i].Y;
            int Lower = a[j].X - a[i].X;
            simp(Upper, Lower);
            if (k[(ii(Upper, Lower))] > 0){
                int nowP = k[ii(Upper, Lower)];
                cout<<i<<" "<<j<<" "<<nowP;
                return 0;
            }
            k[ii(Upper,Lower)] = j;
        }
    }
    //T2
    REP(i,n/2+1,n){
        map<ii, int> k;
        REP(j,1, n/2){
            int Upper = a[j].Y - a[i].Y;
            int Lower = a[j].X - a[i].X;
            simp(Upper, Lower);
            if (k.count(ii(Upper, Lower)) > 0){
                int nowP = k[ii(Upper, Lower)];
                cout<<i<<" "<<j<<" "<<nowP;
                return 0;
            }
            k[ii(Upper,Lower)] = j;
        }
    }
    cout<<-1;
    return 0;
}
