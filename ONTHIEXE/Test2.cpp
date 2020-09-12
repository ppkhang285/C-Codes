#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<= b;++i)
#define task "PRIMEMAX"
using namespace std;
int n,a[100005],res;
map <int,int> b;
int check(int x)
{
    if (x==1) return 0;
    rep(i,2,trunc(sqrt(x)))
    {
        if (x%i==0) return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    res=0;
    rep(i,1,n)
    {
        if (check(a[i])) res=max(a[i],res);
    }
    if (res==0) cout<<"\n";
    else cout<<res<<endl;
    res=0;
    rep(i,1,n)
    {
        if (b[a[i]]>b[res]) res=a[i];
    }

    cout<<res;
    return 0;
}
