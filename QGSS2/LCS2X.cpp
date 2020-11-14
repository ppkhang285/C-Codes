#include <iostream>
#define task "LCS2X"
using namespace std;

int C[1502]={0};
int A[1502];
int B[1502];
int F[1502][1502]={0};
int m,n;
int Len=0;
int trace(int i, int j){
    if (i<=0 && j<=0) return 0;
    if (A[i]==B[j]){
        C[++Len]=A[i];
        trace(i-1,j-1);
    }
    else {
        if (F[i][j-1]>F[i-1][j]) trace(i,j-1);
             else trace(i-1,j);
    }
    return 0;
}
int main(){
     freopen(task".inp","r",stdin);
     freopen(task".out","w",stdout);
     int T;
     cin>>T;
     for (int z=1;z<=T;z++){
        cin>>m>>n;
        for (int i=1;i<=m;i++) cin>>A[i];
        for (int i=1;i<=n;i++) cin>>B[i];

     for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++){
       if (A[i]==B[j]) F[i][j]=F[i-1][j-1]+1;
          else F[i][j]=max(F[i-1][j],F[i][j-1]);
     }
     trace(m,n);
     int G[1500]={0};
     for (int i=1;i<=Len;i++){
        G[i]=1;
        for (int j=1;j<=i;j++)
        if (C[j]>=C[i]*2 && G[i]<G[j]+1) G[i]=G[j]+1;
     }
     int res=-1000000;
     for (int i=1;i<=Len;i++)
        res=max(res,G[i]);
    cout<<res;
    return 0;
     }
}
