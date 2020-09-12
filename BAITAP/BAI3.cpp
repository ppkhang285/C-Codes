#include <bits/stdc++.h>
#define task "BAI3"
#define REP(i, a ,b) for(int i =a; i<=b ; ++i)

using namespace std;

int A[5];
int maxNum = 0;
int Prime[5];
bool is_Prime(int x ){

    if (x<2) return false;

    if (x==2) return true;

    int no = (int)sqrt(x);

    REP(i,2,no){
        if (x % i ==0) return false;
    }
    return true;

}
int main(){

    int N = -1;

    REP(i,0,4){
        cout<< "A[" <<i<< "]=";
        cin>>A[i];
        cout<<"\n";
    }

    REP(i,0,4){
        if ( is_Prime(A[i])){
            Prime[++N] = A[i];
            maxNum = max(maxNum , A[i]);
        }
    }
    if (N <0) {
        cout<<"Khong co so nguyen to trong mang";
    }
    else{
        cout<<"Cac so nguyen to la:";
        REP(i,0,N) cout<<Prime[i]<<" ";;
        cout<<"\n";
        cout<<"So nguyen to lon nhat la:"<<maxNum;
    }
}
