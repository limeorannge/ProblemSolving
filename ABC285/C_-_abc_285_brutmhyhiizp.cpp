#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
char s[100100];
ll pow(ll n, ll k){
    if(k==0) return 1;
    return pow(n, k-1)*n;
}
int main(){
    cin >> s;
    ll l = strlen(s);
    ll ans = 0;
    if(l>1) ans += (pow(26, l)-1)/25 -1;
    for(ll i=0; i<l-1; i++){
        ans += (ll)(s[i] - 'A')*pow(26, (l-i-1));
    }
    ans += (ll)(s[l-1] - 'A') + 1;
    cout << ans;
}