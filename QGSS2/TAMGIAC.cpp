#include <bits/stdc++.h>
#define task "TAMGIAC"
#define REP(i,a,b) for(int i = a; i<=b; ++i)

using namespace std;
int n, a[5005];

int FindLess(int L, int R, int x){
    int res = 0;
    while(L<=R){
        int mid = (L + R)/2;
        if (a[mid]<x){
            res = mid;
            L = mid +1;
        }
        else R = mid - 1;
    }
    return res;
}
/*nt FindMore(int L, int R, int x){
    int res = 0;
    while(L<=R){
        int mid = (L + R)/2;
        if (a[mid]>x){
            res = mid;
            R = mid - 1;;
        }
        else L = mid + 1;
    }
    return res;
}*/
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    REP(i,1,n) cin>>a[i];
    sort(a+1, a+1+n);
    int ans = 0;
    REP(i,1,n-2){
            REP(j,i+1,n-1){
                int kLess = FindLess(j+1, n, a[i] + a[j]);
                //int kMore = FindMore(j+1, n, a[j] - a[i]);
                //ans += ((kMore == 0|| kLess == 0)?0: (kLess - kMore + 1));
                ans+= (kLess ==0?0: (kLess - j));
            }
    }
    cout<<ans;
    return 0;
}
