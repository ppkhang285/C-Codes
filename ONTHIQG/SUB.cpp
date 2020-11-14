#include <bits/stdc++.h>
#define task "SUB"
#define REP(i,a,b) for(int i = a; i<= b; ++i)

/*
 F[i] - F[j-1] >= S
 F [i] > = S + F[j-1] => tim j lon nhat sao cho thoa man S + F[j] <= F[i]
						=> F[j] <= F[i] - S      => ans = min( i - j);                                */
using namespace std;
typedef long long ll;
int n, S, a[100005];
ll F[100005];

int Find(int L, int R ,ll x ){
    int res = 0;
    while(L<=R){
        int mid = (L+R)>>1;
        if ( F[mid] <= x - S){
            res = mid;
            L = mid + 1;
        }
        else R = mid -1;
    }
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>S;
    REP(i,1,n) cin>>a[i];
    F[0] = 0;
    int ans = 1000000;
    REP(i,1,n) F[i] = F[i-1] + a[i];
    REP(i,1,n){
        if (F[i] < S) continue;
        int j = Find(1,i, F[i]);
        ans = (j==0?ans:min(ans, i - j));
    }
    cout<<ans;
    return 0;
}


