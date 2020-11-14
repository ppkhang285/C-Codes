#include <bits/stdc++.h>
#define task "KNNL"
#define REP(i,a,b) for(int i = a; i<=b; ++i)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
vector<int> Task[205];
int Time[205];
bool Free[205];
int n,m;
ii a[205];

bool comp(ii k, ii l){
    return k.X > l.X;
}

int Find(int C, int L, int R){
    int res = 0;
    while (L<=R){
        int mid = (L+R) /2;
        if (a[mid].X + C <=m){
            res = mid;
            R = mid - 1;
        }
        else L = mid+1;
    }
    if (res == n && Free[res] == false) return 0;
    if (Free[res] == false && res<n) res = Find(C, res+1, n);
    return res;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    REP(i,1,n){
        cin>>a[i].X;
        a[i].Y = i;
    }
    sort(a+1, a+1+n, comp);
    memset(Free,true, sizeof(Free));
    int company = 1;//cong ty thu i
    int i = 1;
    while(i <=n){
        if (Free[i] == false){
            i++;
            continue;
        }
        if (Time[company] + a[i].X <= m){
            Time[company] += a[i].X;
            Task[company].push_back(a[i].Y);
            Free[i] = false;
            i++;

        }
        else{
            while (true){
                int Now = Find(Time[company] , i+1, n);
                if (Now == 0) {company++;break;}
                Time[company] += a[Now].X;
                Task[company].push_back(a[Now].Y);
                Free[Now] = false;
            }
        }
    }
    cout<<company<<"\n";
    REP(i,1,company){
        for(auto tasks:Task[i]) cout<<tasks<<" ";
        cout<<"\n";
    }

    return 0;

}

