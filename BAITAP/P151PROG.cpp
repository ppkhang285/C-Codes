#include <bits/stdc++.h>
#define task "P151PROG"
#define REP(i,a,b) for(int i = a;i<=b;++i)

using namespace std;
int n;
int res[1000005];
int fir,sec;
int app[1000005];
map<int, int> R;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;

    memset(app,0,sizeof(app));
    REP(i,1,n){
        int l,r;
        cin>>l>>r;
        R[l] = r;
        app[r]++;
        if (l == 0) sec = r;
    }
    for(auto& it: R){
        int l = it.first;
        if (app[l] == 0){
            fir = l;
            break;
        }
    }
    res[1] = fir;
    res[2] = sec;
    int k =1;
    int now = R[fir];
    while (now !=0){
        res[2*k+1] = now;
        now = R[now];
        ++k;
    }
    k =2;
    now = R[sec];
    while (now !=0){
        res[2*k] = now;
        now = R[now];
        ++k;
    }
    REP(i,1,n) cout<<res[i]<<" ";
    return 0;
}

