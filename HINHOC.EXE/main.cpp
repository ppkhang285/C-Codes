#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> Point;
struct circle{
    Point A;
    double r;
};
int operator *(Point u, Point v){
    return (u.X*v.X + u.Y*v.Y);
}

int operator ^(Point u, Point v){
    return (u.X*v.Y - u.Y*v.X);
}
double Distance(Point A, Point B){ //Khoang cach giua diem A va Diem B
    return sqrt( (B.X - A.X) * (B.X - A.X) + (B.Y - A.Y) * (B.Y - A.Y) );
}

int ccw(Point A, Point B, Point C){//Chieu quay cua 3 diem/ 2 vector
    double t = (B.X - A.X)*(C.Y - A.X) - (B.Y - A.Y)*(C.X - A.X);
    if (t>0){
        return 1; //quay trai
    }
    if (t<0){
        return -1;//quay phai
    }
    return 0;//Thang hang
}

double angle(Point A){//tinh goc tao boi OA va truc Ox
    double t = atan2(A.Y , A.X);
    if (t<0) t += 2*acos(-1);
    return t;
}

double sTriagle(Point A, Point B, Point C){
    double s = (B.X - A.X)*(C.Y - A.Y) - (B.Y - A.Y)*(C.X - A.X);
    return abs(s/2);
}

double dist2( Point A, Point B, Point C){// Khoang cach tu c den duong thang AB
    return 2*sTriagle(A,B,C) / Distance(A,B);
}




int main()
{
    //int t =  Point(1,2) ^ Point(2,3);
    //cout << t;
    return 0;
}
