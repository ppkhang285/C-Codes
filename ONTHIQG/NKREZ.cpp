#include <bits/stdc++.h>
#define task "NKREZ"
#define REP(i,a,b) for(int i = a;i<=b;++i)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;

ii Quer[10005];
int T[10005];
int n;
bool comp(ii a, ii b){
    return a.Y < b.Y;
}
int Find( int L, int R, int S){
    int res = 0;
    while (L<=R){
        int mid = (L+R) / 2;
        if (Quer[mid].Y <=  S){
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //------
    cin>>n;
    REP(i,1,n) cin>>Quer[i].X>>Quer[i].Y;
    sort(Quer + 1, Quer + 1 + n, comp);
    Quer[0].X = Quer[0].Y = 0;
    T[1] = Quer[1].Y - Quer[1].X;
    REP(i,2,n){
        int k = Find(1,i-1, Quer[i].X);
        T[i] = max( T[i-1], T[k] + Quer[i].Y - Quer[i].X);
    }
    cout<<T[n];
    return 0;
}
