#include <bits/stdc++.h>
#define task "XEPLICHNV"
#define REP(i,a,b) for(int i =a ;i<= b;++i)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;

ii A[100005];
int ans,n;
bool comp(ii a, ii b){
    return a.Y < b.Y;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>A[i].X>>A[i].Y;
    sort(A+1, A+1+n, comp);
    int R = A[1].Y;
    ans = 1;
    REP(i,2,n){
        if (A[i].X >= R){
            ans++;
            R = A[i].Y;
        }
    }
    cout<<ans;
    return 0;

}
