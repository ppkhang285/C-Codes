#include <bits/stdc++.h>
#define task "EGG"

using namespace std;
struct seller{
    int cost, num;
};
bool cmd( seller i, seller j){
    return i.cost < j.cost;
}
seller a[100000];
int n,m;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i<=m;++i){
        cin>>a[i].cost>>a[i].num;
    }
    sort(a+1,a+1+m,cmd);
    int seller_now =1;
    long long res = 0;
    while (n>0 && seller_now <= m){
        if (n< a[seller_now].num){
            res+= n* a[seller_now].cost;
            break;
        }
        else {
            res+= a[seller_now].num* a[seller_now].cost;
            n-= a[seller_now].num;
            seller_now++;
        }
    }
    cout<<res;
    return 0;
}
