#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
using namespace std;
int n;
char s[5050];
int main(){
    cin >> n;
    cin >> s;
    for(int i=1; i<n; i++){
        bool crpt = 0;
        for(int j=0; j<n-i; j++){
            if(s[j]==s[j+i]){
                crpt = 1;
                cout << j << ln;
                break;
            }
        }
        if(!crpt) cout << n-i<<ln;
    }
}