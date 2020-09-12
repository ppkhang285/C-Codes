#include <bits/stdc++.h>
#define task "DPALIN"
#define REP(i,a,b) for(int i=a; i<=b ;i++)
#define rREP(i,a,b) for(int i=a; i>=b ;i--)
#define MaxN 200

using namespace std;

long long Pow[1000], Hash[1000], rHash[1000], base=1e9+7;
string s;
int point,n;
long long getHash(int i, int j){
    return (Hash[j] - Hash[i-1]*Pow[j-i+1]);
}
long long getrHash(int i, int j){
    return (rHash[i] - rHash[j+1]*Pow[j-i+1] );
}
bool check(int i, int j){
    int mid = (i+j) /2;
    if ( (j-i+1)%2 !=0 ){
        if ( getHash(i,mid) == getrHash(mid, j)) return true;
            else return false;
    }
    else{
        if ( getHash(i,mid) == getrHash(mid+1,j)) return true;
            else return false;
    }
}
void find( int i, int j , int depth){
    if (i>=j) return;
     point = max(depth, point);
    int mid = (j+i) /2;

    if (  (j-i+1)%2 != 0){
        if (check(i,mid)){
            find(i, mid, depth+1);
        }
        if (check(mid, j)){
            find(mid, j ,depth+1);
        }
    }
    else{
        if (check(i,mid)){
            find(i, mid, depth+1);
        }
        if (check(mid, j)){
            find(mid+1, j ,depth+1);
    }
}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    Pow[0] =1;
    REP(i,1,MaxN) Pow[i] = Pow[i-1]* base;
    while (cin>>s){
        s ="0" +s;
        n = s.size()-1;
        Hash[0]= 0;
        rHash[n+1]= 0;
        REP(i,1,n)
            Hash[i] = Hash[i-1]*base + s[i];
        rREP(i,n,1)
            rHash[i]= rHash[i+1]*base + s[i];
        point = 0;
        if (check(1,n))
            find(1,n,1);
        cout<<n<<" "<<  point << " " <<1 << "\n";
    }
    return 0;
}
