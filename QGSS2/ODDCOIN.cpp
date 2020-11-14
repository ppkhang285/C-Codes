#include <bits/stdc++.h>
#define task "ODDCOIN"
#define REP(x,i,j) for(int x=i;x<=j;++x)

using namespace std;


int doing(int x,int t){
    int note=0;
    int a[17]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};
    a[16]=x;
    sort(a+1,a+17);
    int res=200000000;
    REP(i,1,16) note=(t>=a[i])?i:note;
    note++;
    while (--note > 0){
        int now=0;
        int coin=t;
        int i=note;
        while (coin>0 && i>=1) {
            while (coin<a[i]) i--;
            now += coin/a[i];
            coin%=a[i];
        }
        res=min(res,now);
    }
    cout<<res<<"\n";
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int q,t,x;
    cin>>q;
    REP(z,1,q){
        cin>>x>>t;
        doing(x,t);
    }
    return 0;
}
