/*
Solved by Insoo Chung (limeorannge/Saycorn)
Problem link: 
*/
#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
using namespace std;
void dbg(){puts("okay");}
int n, Q;
int main(){
    cin >> Q;
    while(Q--){
        int r, s;
        cin >> n >> s >> r;
        int maxi = s-r;
        int sz = n;
        for(int i=maxi; i>=1; i--){
            int icnt = 0;
            while(1){
                if(s - i*icnt < sz - icnt || icnt == sz+1){
                    break;
                }
                icnt++;
            } 
            icnt--;
            for(int j=1; j<=icnt; j++) cout << i << rp;
            //cout << ln;
            s-=i*icnt;
            sz-=icnt;
            //cout << s << rp << sz << ln;
            if(s==0) break;
        }
        cout << ln;
    }
}