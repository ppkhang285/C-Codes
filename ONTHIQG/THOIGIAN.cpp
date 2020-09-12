#include <bits/stdc++.h>
#define task "THOIGIAN"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;

struct times{
    int start,finish,ind;

    bool operator<(const times& x){
        return finish < x.finish;
    }
};


int F[1005],n,pre[1005],N;
times a[1000];
int QRes[1005];
int BS(int L, int R, int x){
    int res = 0;
    while(L<=R){
        int mid = (L+R)/2;
        if (a[mid].finish < x){
            res = mid;
            L = mid+1;
        }
        else R = mid-1;

    }
    return res;
}

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n){
        cin>>a[i].start>>a[i].finish;
        a[i].ind = i;
    }
    sort(a+1,a+1+n);

    F[0] = 0;
    F[1] = 1;
    pre[1] = 0;
    REP(i,2,n){
        int k = BS(1,i-1,a[i].start);
        if (k==0) {
                F[i] = F[i-1];
                pre[i] = pre[i-1];
        }
            else if (F[i-1]> F[k]+1){
                    F[i] = F[i-1];
                    pre[i] = pre[i-1];
            }
                else{
                    F[i] = F[k] +1;
                    pre[i] = k;
                }
    }
    int i = n;
    N = 0;
    cout<<F[n]<<"\n";
    while (i>=1){
        if (pre[i] ==0 && i>0){
            QRes[++N] = a[i].ind;
            break;
        }
        while (pre[i] == pre[i-1]) --i;
        QRes[++N] = a[i].ind;
        i = pre[i];
    }
    //if (pre[1] < pre[2]) cout<<a[1].ind<<"\n";
    for(int i = N; i>=1;--i) cout<<QRes[i]<<"\n";
    return 0;
}
