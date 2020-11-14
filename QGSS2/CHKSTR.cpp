#include <bits/stdc++.h>
#define task "CHKSTR"
#define REP(i,a,b) for(int i = a; i<=b; ++i)

using namespace std;


int solve( string s ){
    int trai = 0;
    int phai = 0;
    for( auto chr:s){
        if ( chr =='(' ) trai++;
         else if (chr == ')' && trai>0) trai--;
    }
    for( int i = s.size()-1; i>=0;--i){
        if ( s[i] ==')' ) phai++;
         else if (s[i] == '(' && phai>0) phai--;
    }
    if (trai >0 || phai >0) cout<<"SAI\n";
        else cout<<"DUNG\n";
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    string s;
    while (getline(cin, s)){
        solve(s);
    }
    return 0;
}
