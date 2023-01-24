#define rp ' '
#define ln '\n'
#define ll long long int
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    cout << a/b << ln;
    cout << a - (a/b)*b;
}