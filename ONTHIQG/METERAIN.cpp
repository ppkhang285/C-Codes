#include <bits/stdc++.h>
#define task "METERAIN"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define X first
#define Y second

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
ii  p[5005];
int n,m;
int ccw(ii A, ii B, ii C){//Chieu quay cua 3 diem/ 2 vector
    //ll t = (B.X - A.X)*(C.Y - A.Y) - (B.Y - A.Y)*(C.X - A.X);

    ll t = A.X*(C.Y - B.Y) + B.X*(A.Y - C.Y) + C.X*(B.Y - A.Y);
    if (t>0){
        return 1;
    }
    if (t<0){
        return -1;
    }
    return 0;
}
ll sTriagle(ii A, ii B, ii C){
    //ll s = (B.X - A.X)*(C.Y - A.Y) - (B.Y - A.Y)*(C.X - A.X);
    //ll s = (B.X - A.X)*(B.Y + A.Y) + (C.X - B.X)*(C.Y + B.Y) + (A.X - C.X)*(A.Y + C.Y);
    ll s = A.X*(C.Y - B.Y) + B.X*(A.Y - C.Y) + C.X*(B.Y - A.Y);
    return abs(s);
}
int solve(ii mete){
    int L = 2;
    int R = n;
    while (R - L > 1){
        int mid = (L+R)/2;
        if (ccw(p[1], p[mid], mete) < 0) L = mid;
            else R = mid;
    }
    if ( L == 2 && ccw(p[1], p[2],mete) >=0) return 0;
    if ( R == n && ccw(p[1], p[n],mete) <=0) return 0;
    ll s1 = sTriagle(p[1], p[L],mete);
    ll s2 = sTriagle(p[1], mete, p[R]);
    ll s3 = sTriagle(p[L], mete, p[R]);
    ll S = sTriagle(p[1], p[L], p[R]);
    if (!s3) return 0;
    return (s1 + s2 + s3 == S);
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>p[i].X>>p[i].Y;
    cin>>m;
    REP(i,1,m){
        ii mete;
        cin>>mete.X>>mete.Y;
        bool ok = solve(mete);
        cout<<(ok == true?"YES":"NO")<<"\n";
    }
    return 0;

}
;
