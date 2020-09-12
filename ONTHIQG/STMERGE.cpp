#include <bits/stdc++.h>
#define task "STMERGE"
#define REP(x,i,j) for(int x=i;x<=j;x++)

using namespace std;
int m,n,q,C[1000][1000];
long long F[1000][1000][2];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>q;
    for(int z=1;z<=q;z++){
        cin>>m>>n;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                cin >> C[i][j];
                F[i][j][0]=F[i][j][1]=0;
            }
    F[1][1][1]=F[1][1][0]=C[1][1];
    for(int i=2;i<=n;i++){
        F[1][i][0]=min(F[1][i-1][0],F[1][i-1][1]+C[1][i]);
        F[1][i][1]=C[1][i];
    }
    for(int i =2;i<=m;i++){
        F[i][1][0]=C[i][1];
        F[i][1][1]=min(F[i-1][1][1],F[i-1][1][0]+C[i][1]);
    }
    for(int i =2;i<=m;i++)
        for(int j=2;j<=n;j++){
        F[i][j][0]=min(F[i][j-1][0],F[i][j-1][1]+C[i][j]);
        F[i][j][1]=min(F[i-1][j][1],F[i-1][j][0]+C[i][j]);
        }
    //int res=min(F[m][n][0],F[m][n][1]);
    cout << min(F[m][n][0],F[m][n][1]) <<"\n";

    }
    return 0;
}
