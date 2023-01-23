#define rp ' '
#define ln '\n'
#define ll long long int
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
ll n, a, b;
char s[10010];
int main(){
    cin >> n >> a >> b;
    cin >> s;
    ll pr = 0;
    ll ans = 1e18;
    for(ll i=0; i<n; i++){
        ll cnt = 0;
        for(ll j=i; j<i+n; j++){
            if(s[j] != s[n - 1 + 2*i - j]) cnt++;
        }
        cnt/=2;
        ans = min(ans, pr+cnt*b);
        pr+=a;
        s[n+i] = s[i];
    }
    cout << ans;
}