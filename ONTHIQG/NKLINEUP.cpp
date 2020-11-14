#include <bits/stdc++.h>
#define task "NKLINEUP"
#define REP(i,a,b) for(int i = a;i<=b;++i)
#define X first
#define Y second
#define oo 1000005
using namespace std;
typedef pair<int, int> ii;

int L[200005],R[200005], Leaf[50005],Cow[50005];
int MxTall[200005], MnTall[200005];
int n,Q;
int Build(int node, int Le, int Ri){
    L[node] = Le;
    R[node] = Ri;
    if (Le == Ri){
        Leaf[Le] = node;
        MxTall[node] = MnTall[node] = Cow[Le];
        return 0;
    }
    int mid = (Le+Ri) / 2;
    Build(node*2, Le, mid);
    Build(node*2+1, mid +1, Ri);

    MxTall[node] = max(MxTall[node*2], MxTall[node*2+1]);
    MnTall[node] = min(MnTall[node*2], MnTall[node*2+1]);
    return 0;
}
ii Get(int node, int Le, int Ri){
    if (Ri < L[node] || Le> R[node]) return ii(0,oo);//L va R cua node nam ngoai doan can xet
    if (Le <= L[node] && R[node] <= Ri){   // L va R cua node nam hoan toan trong doan can xet
        return ii(MxTall[node], MnTall[node]);
    }

    ii P1 = Get(node*2, Le, Ri);
    ii P2 = Get(node*2+1,Le,Ri);
    return ii(max(P1.X,P2.X), min(P1.Y, P2.Y));
}

int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //------
    cin>>n>>Q;
    REP(i,1,n) cin>>Cow[i];
    Build(1,1,n);
    REP(i,1,Q){
        int A,B;
        cin>>A>>B;
        ii ans = Get(1,A,B);
        cout<<ans.X - ans.Y<<"\n";
    }
    return 0;

}
