#include <bits/stdc++.h>
#define task "STARS"
#define REP(i,a,b) for(int i=a; i<=b ; i++)
#define setI set<int>::iterator
#define PI 3.14159265
using namespace std;

struct point{
    int x1,x2,y1,y2;
};

set<int> X,Y;
point a[1000];
int n,d,goc,g,trash1, trash2;
int res;

int read_inpur(){
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    //
    cin>>n>>d;
    REP(i,1,n){
        cin>>g>>goc;
        cin>>a[i].x1 >>a[i].y1;
        X.insert(a[i].x1);
        Y.insert(a[i].y1);
        cin>>trash1>>trash2;
        if (trash1!= a[i].x1 && trash2 != a[i].y1) {
                a[i].x2 =trash1;
                a[i].y2 =trash2;
                }

        cin>>trash1>>trash2;
        if (trash1!= a[i].x1 && trash2 != a[i].y1) {
                a[i].x2 =trash1;
                a[i].y2 =trash2;
                }
        cin>>trash1>>trash2;
        if (trash1!= a[i].x1 && trash2 != a[i].y1) {
                a[i].x2 =trash1;
                a[i].y2 =trash2;
                }
        int x=a[i].x2;
        int y=a[i].y2;
        int paramSin = int(sin(-goc *PI /180 ));
        int paramCos = int(cos(-goc *PI /180 ));
        a[i].x2 = ((x -a[i].x1)*paramCos - (y - a[i].y1)*paramSin) + a[i].x1;
        a[i].y2 = ((x- a[i].x1)*paramSin + (y - a[i].y1)*paramCos) + a[i].y1;
        X.insert(a[i].x2);
        Y.insert(a[i].y2);
    }
    return 0;
}
bool check(setI x,setI y,setI preX,setI preY){
    REP(k,1,n){
        if (a[k].x1<=preX && x<=a[k].x2&& a[k].y1<=preY && y<=a[k].y2) {
                return true;
        }
    }
    return false;
}
int process(){
    iterator preX =  X.begin();
    iterator preY = Y.begin();
    return 0;
}
int main(){
    read_inpur();
    process();
    return 0;
}
