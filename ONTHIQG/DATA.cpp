#include <bits/stdc++.h>
#define task "DATA"
#define REP(i,a,b) for(int i = a; i<=b;++i)
using namespace std;
int a[100];

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    string cmd;
    REP(i,1,3){
         cin>>cmd;
         //cout<<cmd;
    }
    int n = 0;
    cin>>n;
    REP(i,1,3) {
        cin>>cmd;
    }
    int res = 0;
    REP(i,1,n){
        cin>>a[i];
        res += a[i];
    }
    cout<<"Tong cua "<<n<<" so:\n";
    REP(i,1,n){
        if (a[i] >=0) cout<<"+"<<a[i]<<" ";
        else cout<<a[i]<<" ";
    }
    cout<<"= "<<res;
    return 0;

}

