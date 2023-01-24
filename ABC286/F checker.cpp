#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int f[110];
int a[110];
int main(){
    for(int i=1; i<=108; i++){
        cin >> f[i];
        a[i] = i;
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=108; j++) a[j] = f[a[j]];
    }
    for(int i=1; i<=108; i++){
        cout << a[i] << rp;
    }
}