#include<bits/stdc++.h>
#define task "EXTENDED_EUCLID" //Thuat toan Euclid mo rong Extended Euclid Algorithm

using namespace std;
typedef long long LL;
void ext_gcd(LL a, LL b, LL &d, LL &x, LL &y){
    if (b == 0){
        d = a;
        x = 1;
        y = 0;
        return;
    }
    LL x1, y1;
    ext_gcd(b, a%b, d, x1 ,y1);
    x = y1;
    y = x1 - a/b*y1;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    LL a,b,d,x,y;
    cin>>a>>b;
    ext_gcd(abs(a), abs(b), d,x,y);
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    cout<<d<<" "<<x<<" "<<y<<"\n";
    return 0;

}
