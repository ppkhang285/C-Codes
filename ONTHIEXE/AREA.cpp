#include <bits/stdc++.h>
#define task "AREA"
#define REP(x,i,j) for (int x=i;x<=j;x++)
#define X first
#define Y second
#define db double
using namespace std;

typedef pair<db, db> Point;
vector<Point> d;
Point pbase=make_pair(0,0);
double DT(Point p1, Point p2, Point p3 )
{
    int t1=p1.X*(p3.Y-p2.Y);
    int t2=p2.X*(p1.Y-p3.Y);
    int t3=p3.X*(p2.Y-p1.Y);
    return (t1+t2+t3)/2;
}

bool CWW(Point p1, Point p2, Point p3)
{
    return DT(p1,p2,p3)>0;
}

Point Find( Point a1, Point b1, Point a2, Point b2)
{
    Point ponow;
    db A1=a1.Y-b1.Y;
    db B1=b1.X-a1.X;
    db C1=a1.X*b1.Y-a1.Y*b1.X;
    db A2=a2.Y-b2.Y;
    db B2=b2.X-a2.X;
    db C2=a2.X*b2.Y-a2.Y*b2.X;
    ponow.X=(   (B1*C2-B2*C1)   / (A1*B2-A2*B1)   );
    ponow.Y=(-A1*ponow.X-C1)/B1;
    return ponow;
}
int process()
{
    double Snow=0, res=0;;
    queue<int> isgt;
    vector<Point> pgt;
#define ds d.size()
    REP(i,0,ds-2)
    {
        if (i>=2 && CWW(pbase,d.back(), d[i])!=CWW(pbase,d.back(), d[i-1]))
        {
            Point gt=Find(pbase, d.back(),d[i-1], d[i]);
            pgt.push_back(gt);
            pgt.push_back(d[i]);
            isgt.push(pgt.size()-2);
        }
        else
            pgt.push_back(d[i]);
    }
    pgt.push_back(d.back());
    isgt.push(pgt.size()-1);
    int sis2=pgt.size();
    int sis3=isgt.size();
    Point pbacker=make_pair(0,0);
    REP(i,0,pgt.size()-1)
    {
        if (i!= isgt.front())
        {
            Snow+=(d[i+1].X-d[i].X) * (d[i+1].Y+d[i].Y);
        }
        else
        {
            Snow+=(pbacker.X-d[i].X)* (pbacker.Y+d[i].Y);
            res+= abs(Snow/2);
            pbacker=d[i];
            Snow=(d[i+1].X-d[i].X) * (d[i+1].Y+d[i].Y);
            isgt.pop();
        }
    }
    cout<<abs(res)<<"\n";
    return 0;

}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char cmt;
    do
    {

        int xnow=0;
        int ynow=0;

        d.push_back(make_pair(xnow,ynow));
        do
        {
            cin>>cmt;
            if (cmt=='S') break;
            if (cmt=='R')
                xnow++;
            else
                ynow++;
            d.push_back(make_pair(xnow,ynow));
        }
        while (cmt!='S');

        if (cin.eof())
            return 0;

        int sis=d.size();
        process();

    }
    while (!cin.eof());
    return 0;
}
