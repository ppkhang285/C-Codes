#include <bits/stdc++.h>
#define task "DAYCONS"
#define REP(i,a,b) for(int i = a ; i<=b; ++i)
#define X first
#define Y second

using namespace std;
typedef pair<int, int> ii;

ii L[100005];
int n,S,ans, a[100005];
int Pos[100005];
bool comp(ii a, ii b){
    if (a.X == b.X) return a.Y< a.Y;
     else return a.X < b.X;
}
int Find(int Le, int R, ii F){
    int res = 0;
    while (Le <= R){
        int mid = (Le + R) / 2;
        if ( L[mid].X - F.X == S && abs( F.Y - L[mid].Y) >= 2 ){
            res = mid;
            R = mid-1;
            continue;
        }
        if (L[mid]. X - F.X >S){
            R = mid-1;
        }
        else Le = mid +1;
    }

    return Pos[res];
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>S;
    REP(i,1,n) cin>>a[i];
    L[1].X = a[1];
    L[1].Y = 1;
    REP(i,2,n){
        L[i].X = a[i];
        L[i].Y = i;
    }
    sort(L+1, L+1+n, comp);
    Pos[0] = 0;
    Pos[n] = 1;
    for(int i = n-1; i>=1; --i){
        if  (L[i].X == L[i+1].X) Pos[i] = Pos[i+1] +1;
            else Pos[i] = 1;
    }
    ans = 0;
    REP(i,1,n-2){
        int k = Find(i+1, n, L[i]);
        ans +=k;
    }
    return 0;
}
