#include <bits/stdc++.h>
#define task "GILDER"
#define REP(x,i,j) for(int x=i;x<=j;++x)

struct hot {
    int x;
    int y;
    int len;
};

hot tmp[100000],A[100000];
int N,n,h,Fly[100000];
using namespace std;
bool cmd(hot i, hot j){ if (i.x==j.x) return(i.y<j.y);  return(i.x<j.x);}

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>n>>h;

    REP(i,1,n) cin>>tmp[i].x>>tmp[i].y;
    sort(tmp+1,tmp+1+n,cmd);
    int N=1;
    int i=1;
    A[1].x=tmp[1].x;
    A[1].y=tmp[1].y;
    while (i<n) {
            i++;
            if (A[N].y>=tmp[i].x) A[N].y=tmp[i].y;
        else A[++N]=tmp[i];
    }
    REP(i,1,N) A[i].len=A[i].y-A[i].x;
    REP(i,1,N-1) Fly[i]=A[i+1].x-A[i].y;
    int xnow=A[1].x;
    int ynow=h;
    int time=0;
    i=0;
    while (ynow>0){
        i++;
        time+=A[i].len;
        xnow=A[i].y;
        if (ynow>0 && i>=N){
            time+=ynow;break;}
        if (ynow<=Fly[i]) {
            time+=ynow;break;}
        time+=Fly[i];
        ynow-=Fly[i];
        xnow=A[i+1].x;
    }
    cout<<time;
    return 0;
}
