#include <bits/stdc++.h>
#define X first
#define task "BAOLOI"
#define Y second

const int N = 300005;

using namespace std;
typedef pair<long long, long long> Line;

int n;
pair<int, int> a[N];

long long eval(long long x, Line line) {
    return x * line.X + line.Y;
}

bool bad(Line d1, Line d2, Line d3) {
    return (d2.Y - d1.Y) * (d1.X - d3.X) >= (d3.Y - d1.Y) * (d1.X - d2.X);
}

int main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++) scanf("%d %d", &a[i].X, &a[i].Y);
    sort(a + 1, a + 1 + n);
    vector<pair<int, int> > b;
    for (i = 1; i <= n; i++) {
        while (b.size() && b.back().Y < a[i].Y) b.pop_back();
        b.push_back(a[i]);
    }
    vector<Line> d; long long last = 0; Line new_line; int best = 0;
    for (i = 0; i < b.size(); i++) {
        new_line = Line(b[i].Y, last);
        while (d.size() >= 2 && bad(d[d.size() - 2], d[d.size() - 1], new_line)) {
            if (best >= d.size() - 1) best--; d.pop_back();
        }
        d.push_back(new_line);
        while (best + 1 < d.size() &&
	    eval(b[i].X, d[best]) >= eval(b[i].X, d[best + 1])) best++;
        last = eval(b[i].X, d[best]);
    }
    cout << last << endl;
    return 0;
}
