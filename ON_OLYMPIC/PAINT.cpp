#include <bits/stdc++.h>
#define task "PAINT"
#define REP(i,a,b) for(int i= a; i<=b; i++)

using namespace std;

struct CL
{
    char corL[1000];
    int step[1000];
    int Size;
};

map<char, CL> color;
char room[1000];
int N,n;
void Init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    for (char i ='a' ; i<= 'z' ; i++)
    {
        color[i].corL[1] = i;
        color[i].step[1] = 0;
        color[i].Size = 1;
    }
}
void readInput()
{
    cin>>n;
    REP(i,1,n)
    {
        int cmd;
        cin>>cmd;
        if (cmd==1)
        {
            char COlor;
            cin>>COlor;
            room[++N] = COlor;
        }
        else
        {
            char child, par;
            cin>>child>>par;
            color[child].corL[++color[child].Size] = par;
            color[child].step[color[child].Size] = N;
        }
    }
}
char findColor(char nowCol , int i)
{
    int N= color[nowCol].Size;
    while (i > color[nowCol].step[N] && N>1) N--;
    if (N == 1) return (nowCol);
        else
            return findColor(color[nowCol].corL[N], i);
}
void process()
{
    for (int  i= N ; i>=1 ;i--){
        room[i] = findColor(room[i], i);
    }
    REP(i,1,N) cout<<room[i];
}
int main()
{
    Init();
    readInput();
    process();
    return 0;
}
