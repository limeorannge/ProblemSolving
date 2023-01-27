/*
Solved by Insoo Chung (limeorannge/Saycorn)
Problem link: 
*/
#define rp ' '
#define ln '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
void dbg(){puts("okay");}
int n, Q;
int bits[32];
int main(){
    fastio;
    cin >> Q;
    while(Q--){
        memset(bits, 0, sizeof(bits));
        cin >> n;
        int cnt = 0;
        while(n>0){
            bits[cnt++] = n%2;
            n/=2;
        }
        bool crpt = 0;
        for(int i=cnt-1; i>=0; i--){
            if(bits[i]==1){
                if(i==0 || bits[i-1] != 0){
                    cout << "-1" << ln;
                    crpt = 1;
                    break;
                }
            }
        }
        if(crpt) continue;
        int a = 0;
        int b = 0;
        int i = cnt-1;
        while(i>=0){
            if(bits[i]==1){
                a<<=2;
                b<<=2;
                a+=3;
                b+=1;
                i-=2;
            }
            else{
                a<<=1, b<<=1;
                i--;
            }
        }
        cout << a << rp << b << ln;
    }
}