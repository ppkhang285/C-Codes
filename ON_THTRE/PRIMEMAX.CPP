#include <bits/stdc++.h>
#define task "PRIMEMAX"
#define REP(i,a,b) for(int i=a; i<=b;++i)

using namespace std;

int n,a[100000],b[100000], c[100000];

bool check_prime(int x){
    if (x==2) return true;
    if (x<2) return false;
    int q = trunc(sqrt(x));
    REP(i,2,q){
        if ((x % i) ==0) return false;
    }
    return true;
}
bool Find(int x, int L, int R){
    do{
        int mid = (L+R) /2;
        if (x == b[mid]) return true;
        if (x < b[mid]) R = mid-1;
         else L = mid+1;
    }
    while (L<=R);
    return false;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    REP(i,1,n) c[i] =  a[i];
    sort(a+1,a+1+n);
    int res1= 0;
    for(int i = n; i>=1 ;--i){
        if (check_prime(a[i])){
            res1 = a[i];
            break;
        }
    }int N = 0;
    a[n+1] = -a[n];
    int numnow = a[1];
    int res2 = 1;
    int maxnow = 1;
    REP(i,2,n+1){
        if (a[i] != numnow){
            if (res2 < maxnow){
                res2 = maxnow;
                maxnow = 0 ;
                numnow = a[i];
                N = 1;
                b[N] = a[i-1];
            }
            else if (res2 == maxnow){
                numnow = a[i];
                maxnow = 0;
                b[++N] = a[i-1];
            }
        }
        maxnow++;
    }
    cout<<res1<<"\n";
    sort(b+1,b+1+N);
    REP(i,1,n){
        if (Find(c[i],1,N)){
            cout<<c[i];
            break;
        }
    }
    return 0;
}
