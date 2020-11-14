#include <bits/stdc++.h>
#define task "NKBUS"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;
int n,m, numEmp;
int TimeToPoint[200005];
int TimeOfEmp[200005];
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //---------
    cin>>n>>m;
    numEmp = 0;
    TimeToPoint[1] = 0;
    REP(i,1,n){
        int time,num;
        cin>>time>>num;
        TimeToPoint[i+1] = TimeToPoint[i] + time;//Thoi gian toi diem thu i+1
        REP(j,1,num){
            int ti;
            cin>>ti;
            TimeOfEmp[++numEmp] = (ti-TimeToPoint[i])<0?0: (ti - TimeToPoint[i]); //thoi gian phai cho

        }
    }
    sort(TimeOfEmp+1, TimeOfEmp+1+numEmp);
    cout<<TimeOfEmp[m]+TimeToPoint[n+1];
    return 0;
}
