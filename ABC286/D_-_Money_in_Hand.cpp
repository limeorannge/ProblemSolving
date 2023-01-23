#define rp ' '
#define ln '\n'
#define ll long long int
#include <iostream>
#include <algorithm>
using namespace std;
int n, X;
int c[2550];
bool dp[2550][10010];
int main(){
    cin >> n >> X;
    int cnt = 1;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        while(b--) c[cnt++] = a;
    }
    cnt--;
    dp[0][0] = 1;
    for(int i=1; i<=cnt; i++){
        for(int j=0; j<=X; j++){
            dp[i][j] = dp[i][j] | dp[i-1][j];
            if(j>=c[i]) {
                dp[i][j] = dp[i][j] | dp[i-1][j-c[i]];
            }
        }
    }
    if(dp[cnt][X]) cout << "Yes";
    else cout << "No";
}