#include <bits/stdc++.h>
#define task "SO"
#define REP(i,a,b) for(int i = a; i<= b; ++i)

using namespace std;
int F[] ={0, 1 ,2, 4, 8, 16, 23, 46, 29, 58, 116, 223, 446, 289, 578, 1156, 1223, 2446,
          2489, 4789, 5789, 11578, 12356, 12247, 24449, 48889, 77789, 155578, 111356, 122227, 244445};
int n;
int main(){

    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    cout<< (n<=30?F[n]: F[(n-30)% 6 +24] );
    return 0;
}
