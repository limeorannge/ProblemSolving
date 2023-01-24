#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
using namespace std;
ll n;
ll a[10] = {4, 5, 7, 9, 11, 13, 17, 19, 23};
ll mods[10];
ll b[110];
int main(){
    cout << 108 << ln;
    cout.flush();
    ll cnt = 0;
    for(ll i=0; i<9; i++){
        for(ll j=0; j<a[i]; j++){
            cout << cnt + 1 + (j+1)%a[i] << rp;
        }
        cnt+=a[i];
    }
    cout << ln;
    cout.flush();
    for(ll i=1; i<=108; i++){
        cin >> b[i];
    }
    ll j = 1;
    ll all = 1;
    for(ll i=0; i<9; i++){
        mods[i] = (b[j]-j)%a[i];
        j+=a[i];
        all*=a[i];
    }
    ll ans = 0;
    for(ll i=0; i<9; i++){
        ll mi = all/a[i];
        ll ni;
        for(int j=0; j<a[i]; j++){
            if((mi*j)%a[i]==1) ni= j;
        }
        ans += mi*mods[i]*ni;
    }
    cout << ans % all << ln;
    cout.flush();
}