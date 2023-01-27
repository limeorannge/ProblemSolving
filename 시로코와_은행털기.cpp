/*
Solved by Insoo Chung (limeorannge/Saycorn)
Problem link: https://www.acmicpc.net/problem/26607
*/
#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void dbg(){puts("okay");}
int n;
int a[88];
int b[88];
bool dp[88][8080];
int main(){
    int k, x;
    cin >> n >> k >> x;
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i];
    int X = k*x/2;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=X; j++){
            if(j>=a[i]) dp[i][j] |= dp[i-1][j-a[i]];
            dp[i][j] |= dp[i-1][j];
            //cout << dp[i][j] << rp;
        }
        //cout << ln;
    }
    int ans = 0;
    for(int i=X; i>=0; i--){
        if(dp[n][i]) {
            ans = i*(k*x-i);
            break;
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=X; j++){
            if(j>=b[i]) dp[i][j] |= dp[i-1][j-b[i]];
            dp[i][j] |= dp[i-1][j];
        }
    }
    for(int i=X; i>=0; i--){
        if(dp[n][i]) {
            ans = max(ans, i*(k*x-i));
            break;
        }
    }
    cout << ans;
}