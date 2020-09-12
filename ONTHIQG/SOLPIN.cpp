#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x,0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x> (y)) x=(y)
#define MAX(x,y) if (x<(y)) x=(y)
#define PB push_back
#define mp make_pair;
#define F first
#define S second
#define maxn 1005
#define MOD 1000000007
#define remain(x) if (x > MOD) x=MOD
#define pii pair<int,int>
#define ll long
#define Task "SOLPIN"

using namespace std;

int a[maxn][maxn], s[maxn][maxn], m,n;

int Get(int u, int v, int p, int q){
    return s[p][q]-s[p][v-1]-s[u-1][q]+s[u-1][v-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();cout.tie();
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >>m >>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            a[i+m][j]=a[i][j+n]=a[i+m][j+n]=a[i][j];
    }
    for (int i=1;i<=m+m;i++)
        for (int j=1;j<=n+n;j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }
    int dx=0,dy=0,q;
    cin>>q;
    while (q--){
        int type,x,y,u,v,s,t;
        cin>>type;
        if (type==0){
            cin>>x>>y;
            dx=(dx+x) %n;
            dy=(dy+y) %m;
        }
        else {
            cin>>u>>v>>s>>t;
            cout<<Get(u+dy,v+dx,s+dy,t+dx) <<"\n";
        }
    }
    return 0;
}
