#define rp ' '
#define ln '\n'
 
#include <iostream>
using namespace std;
int a[110];
int main(){
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=0; i<=q-p; i++){
        swap(a[p+i], a[r+i]);
    }
    for(int i=1; i<=n; i++) cout << a[i] << rp;
}