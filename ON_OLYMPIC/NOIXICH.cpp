#include <bits/stdc++.h>
#define task "NOIXICH"
#define REP(i,a,b) for(int i =a;i<=b;++i)

using namespace std;
int a[20001],n;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    int current = n-1;
    int res=0;
    int p;
    sort(a+1,a+n + 1);
    REP(i,1,n){
        if (a[i]!=1){
                p = i;
                break;
        }
        current--;
        res++;
    }
    REP(i,p,n){
        int now = a[i];
        while (now>0 && current>1) {
            now--;
            current--;
            res++;
        }
        if (current==1) break;
    }
    if (n==1) cout<<"0";
        else
            cout<<res;
    return 0;
}
