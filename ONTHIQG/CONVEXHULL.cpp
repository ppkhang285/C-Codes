#include <bits/stdc++.h>
#define task "CONVEXHULL"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
ii p[100005];
ii S1[100005], S2[100005] , S[100005];
double Sq = 0;
int n, N1, N2, N;
bool comp(ii a, ii b){
    //return (a.X == b.X?(a.Y < b.Y):(a.X < b.X));
    return (a.Y == b.Y?(a.X < b.X):(a.Y < b.Y));
}
ll Square(ii A , ii B, ii C){
    ll t =A.X*(C.Y - B.Y) + B.X*(A.Y - C.Y) + C.X*(B.Y - A.Y);
    return abs(t);
}
int ccw(ii A, ii B, ii C){
    ll t = A.X*(C.Y - B.Y) + B.X*(A.Y - C.Y) + C.X*(B.Y - A.Y);
    if (t>0) return 1;
    if (t<0) return -1;
    return 0;
}
int FindTheUpper(){
    S1[++N1] = p[1];
    S1[++N1] = p[2];
    REP(i,3,n){
        while (ccw(S1[N1-1], S1[N1], p[i]) <=0 && N1 > 1) N1--;
        S1[++N1] = p[i];
    }
    return 0;
}
int FindTheLower(){
    S2[++N2] = p[1];
    S2[++N2] = p[2];
    REP(i,3,n){
        while (ccw(S2[N2-1], S2[N2], p[i])  >=0 && N2 > 1) N2--;
        S2[++N2] = p[i];
    }
    return 0;
}
int FuseAndCalc(){
    REP(i,1,N1) S[++N] = S1[i];
    for(int i = N2-1; i>1; --i) S[++N] = S2[i];
    REP(i,2,N-1) Sq += Square(S[1], S[i], S[i+1]);
    Sq /= 2;
    return 0;
}
int WriteOutPut(){
    cout<<N<<"\n";
    cout<<setprecision(1)<<fixed<<Sq<<"\n";
    ii now = S[1];
    int id  = 1;
    REP(i,2,N){
        if (S[i].Y < now.Y){
            id = i;
            now = S[i];
        }
        else
        if (S[i].Y == now.Y && S[i].X < now.X){
            id = i;
            now = S[i];
        }
    }
    for(int i = id; i>=1; --i) cout<<S[i].X<<" "<<S[i].Y<<"\n";
    for(int i = N; i>id ; --i) cout<<S[i].X<<" "<<S[i].Y<<"\n";
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>p[i].X>>p[i].Y;
    sort(p+1, p+1+n, comp);
    N1 = 0;
    N2 = 0;
    N = 0;
    FindTheUpper();
    FindTheLower();
    FuseAndCalc();
    WriteOutPut();
    return 0;
}
