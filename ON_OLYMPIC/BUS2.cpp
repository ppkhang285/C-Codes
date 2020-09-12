#include <bits/stdc++.h>
#define task "BUS2"
#defineREP(x,i,j) for(int x= i; x<=j ;++x)

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin>>n>>m;
    REP(i,1,n)
        REP(j,1,m){
            cin>>a[i][j];
            if (a[i][j] == 1) a[i][j] = 0
                    else a[i][j] = 1;
        }
    if (a[1][1] ==1) C[1][1]=1
            else C[1][1] = 2;
    REP(i,1,n)
        REP(j,1,m){
            if (i!=1 && j!=1)
                if (i!=n && j!=m){

            }
        }

}
