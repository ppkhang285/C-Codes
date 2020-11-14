#include <bits/stdc++.h>
#define task "GSS"
#define REP(i,a,b) for(int i =a ;i<=b; ++i)

using namespace std;

struct node{
    int pre,pos,sum,F;
};

int a[50005],n,m;
node Get(int i, int  j){
    if (i == j){
        node now;
        now.pos = now.pre = now.sum = now.F = a[i];
        return now;
    }
    int mid = (i+j) / 2;
    node u,v,now;
    u = Get(i, mid);
    v = Get(mid+1,j);
    now.sum = u.sum + v.sum;
    now.pre = max(u.pre, u.sum + v.pre);
    now.pos = max(v.pos, v.sum + u.pos);
    now.F = max(u.F,max( v.F, v.pre + u.pos) );
    return now;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n){
        cin>>a[i];
    }
    cin>>m;
    REP(i,1,m){
        int x,y;
        cin>>x>>y;
        int res = Get(x,y).F;
        cout<<res<<"\n";
    }
    return 0;
}
