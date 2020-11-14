#include <bits/stdc++.h>
#define task "HCN"
#define pii pair<int,int>
#define x first
#define y second
//#define DIS(piia, pii b) return( sqrt ( pow(a.x-b.x,2)+ pow(a.y-b.y,2)))
#define DT(i) return( (p[i].y.x - p[i].x.x)*(p[i].x.y - p[i].y.y) )
#define HULL(i,j) return(p[i].x.x<=p[j].x.x && p[i].x.y>=p[j].x.y && p[i].y.x>=p[j].y.x && p[i].y.y<=p[j].y.y
pii p1[1000],p2[1000];
pair<pii,pii> p;
bool cmd(const pii &i, const pii &j){
    return(DT(i)<DT(j));
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>p1[i].x>>p1[i].y>>p2[i].x>>p2[i].y;
    p = make_pair(p1, p2);
    sort(p+1,p+n+1,cmd);
    int F[1000]={1};
    for (int i =1;i<=n;i++){
        for (int j=1;j<i;j++)
            if HULL(p[i],p[j]) F[i]=F[j]+1;
    }
    int res=-1;
    if (F[n]>=2) res=F[n];
    cout<<res;
    return 0;
}



