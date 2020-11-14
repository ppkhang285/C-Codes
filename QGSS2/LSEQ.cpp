#include <bits/stdc++.h>
#define task "LSEQ"
#define REP(x,i,j) for(int x=i;x<=j;++x)

#define REPD(x,i,j) for(int x=i;x>=j;--x)

using namespace std;
int S1[1000000],S2[1000000];
int t;
int n;
int a[1000000];
int rep;
bool cmd(int  i, int j) {return( abs(i)<abs(j));}
int Find1(int i)
{
    int L=t+1;
    int R=i;
    int res=(L+R)/2;
    while (L>=1 && R<=i && L<=R)
    {
        int Mid=int((L+R)/2);
        if (S2[Mid]-S2[i]>rep)
        {
            L=Mid+1;
            res=Mid+1;
        }
        else
        {
            R=Mid;
            res=Mid;
            R=Mid-1;
            res=Mid;
        }

    }
    return res;
}

int Find2(int i)
{
    int L=i;
    int R=n;
    int res=((L+R)/2);
    while (L>=i && R<=n && L<=R)
    {
        int Mid=int((L+R)/2);
        if (S1[Mid]-S1[i]>rep)
        {
            R=Mid-1;
            res=Mid-1;
        }
        else
        {
            L=Mid+1;
            res=Mid;
        }
    }
    return res;
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    a[0]=0;
    REP(i,1,n)
    {
        cin>>a[i];
        if (a[i]==0)
            t++;
    }
    int Res=0;
    sort(a+1,a+1+n,cmd);
    sort(a+1+t,a+1+n);
    if (a[n]==0 && a[1]==0)
        cout<<n;
            else
        {
            REP(i,t+2,n) S1[i]=(a[i]==a[i-1])?S1[i-1]:(S1[i-1]+a[i]-a[i-1]-1);
            S2[n]=0;
            int now=0;
            S2[n]=0;
            REPD(i,n-1,t+1) S2[i]=(a[i]==a[i+1])?S2[i+1]:(S2[i+1]+a[i+1]-a[i]-1);

            // findfirst
            rep=t;
            int j=Find2(t+1);
            now+=a[j]-a[t+1]+1+rep-S1[j]+S1[t+1];
            Res=now;

            //findmid
            REP(i,t+2,n-1)
            {
                rep=t;
                int j=Find1(i);
                now=a[i]-a[j]+1;
                rep=rep-S2[j]+S2[i];
                if (rep>0)
                {
                    int j=Find2(i);
                    now+=a[j]-a[i]+rep-S1[j]+S1[i-1];
                }
                Res=max(Res,now);
            }
            //findlast
            rep=t;
            j=Find1(n);
            now=a[j]-a[n]+1+rep-(S2[j]-S2[n]);
            Res=max(Res,now);
            cout<<Res;
        }
    return 0;
}
