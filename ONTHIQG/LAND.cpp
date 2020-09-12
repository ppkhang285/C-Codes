#include <bits/stdc++.h>
#define task "LAND"
#define pii pair<int,int>
vector<int> pt;
int DT(pii p1, pii p2, pii p3){
    int t1=p1.x*(p3.y-p2.y);
    int t2=p2.x*(p1.y-p3.y);
    int t3=p3.x*(p2.y-p1.y);
    return t1+t2+t3;
}

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>p[i].x>>p[i].y
}

