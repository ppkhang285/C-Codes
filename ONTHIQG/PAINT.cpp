#include <bits/stdc++.h>
#define task "PAINT"
#define REP(x,i,j) for(int x=i;x<=j;++x)
using namespace std;


int main()
{
    vector<int> sp[30];
    char a[1000000];
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int k=0;
    int n;
    cin>>n;
    REP(z,1,n)
    {
        int cmd;
        cin>>cmd;
        if (cmd==1)
        {
            char kt;
            cin>>kt;
            k++;
            a[k]=kt;
            sp[int(kt)-97].push_back(k);
        }
        else
        {
            char kt1,kt2;
            cin>>kt1>>kt2;
            for (auto i: sp[int(kt1)-97])
            {
                a[i]=kt2;
                sp[int(kt2)-97].push_back(i);
            }
            sp[int(kt1)-97].clear();
        }
    }
    REP(i,1,k) cout<<a[i];
    return 0;
}
