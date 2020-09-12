#include <bits/stdc++.h>
#define task "GIFTS"
#define REP(i,a,b) for(int i=a; i<=b ;i++)
#define long long long
using namespace std;

int n,res;
long a[5001];
bool finding(int i, int j, long x)
{
    int L=i;
    int R=j;
    while (L<=R)
    {
        int Mid =(L+R) /2;
        if (a[Mid] == x)
            return Mid;
        else
        {
            if (a[Mid] >x)
                R = Mid-1;
            else
                L= Mid+1;
        }

    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    //
    n=0;
    while (!cin.eof())
    {
        cin>>a[++n];
    }
    n--;
    res=0;
    bool picked[5001];
    memset(picked, true, sizeof(picked));
    sort(a+1, a+1+n);
    REP(i,1,n)
    {
        REP(j,i+2,n)
        {
            long x= (a[i]+a[j])/2;
            int vt=finding(i+1,j-1,x);
            if (vt != 0 && picked[vt]==true)
            {
                res++;
                picked[vt]=false;
            }
        }
    }
    cout<<res;
    return 0;

}
