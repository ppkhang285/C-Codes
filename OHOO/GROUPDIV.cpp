#include <bits/stdc++.h>
#define task "GROUPDIV"
#define REP(x,i,j) for (int x=i;x<=j;x++)

using namespace std;
#define N 300015
int n,a[N];
vector<int> c[N];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n){
        cin>>a[i];
        REP(j,1,a[i]) {
            int x;
            cin>>x;
            c[i].push_back(x);
        }
    }
    bool killed[N];
    memset(killed, true, sizeof(killed));
    REP(i,1,n){
        if (a[i]>=2){
            killed[i]=false;
            for (auto x: c[i]){
                a[x]--;
            }
        }
    }
    cout<<"YES" <<"\n";
    REP(i,1,n)
        if (killed[i]) cout<<i<<" ";
    cout<<"\n";
    REP(i,1,n)
        if (killed[i]==false) cout<<i<<" ";

}
