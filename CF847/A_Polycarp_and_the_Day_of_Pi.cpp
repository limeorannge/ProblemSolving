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
int n;
char s[100] = "31415926535897932384626433832795028841971693993751058209749445923";
int main(){
    int Q;
    cin >> Q;
    while(Q--){
        char a[100];
        cin >> a;
        int i=0;
        int cnt = 0;
        while(a[i]){
            if(s[i]==a[i]) cnt++;
            else break;
            i++;
        }
        cout << cnt << ln;
    }
}