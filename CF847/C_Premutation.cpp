/*
Solved by Insoo Chung (limeorannge/Saycorn)
Problem link: 
*/
#define rp ' '
#define ln '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void dbg(){puts("okay");}
int n, Q;
int cnt[110][2];
int arr[110];
int main(){
    fastio;
    cin >> Q;
    while(Q--){
        memset(cnt, 0, sizeof(cnt));
        memset(arr, 0, sizeof(arr));
        cin >> n;
        int c;
        for(int j=1; j<=n; j++){
            for(int i=1; i<=n-1; i++){
                cin >> c;
                if(cnt[c][0] && cnt[c][0] != i) cnt[c][1] = i;  
                else cnt[c][0] = i;
            }
        }
        for(int i=1; i<=n; i++){
            if(cnt[i][1]==0)
            {
                if(cnt[i][0]==n-1) arr[n] = i;
                else arr[1] = i;
            }
            else arr[max(cnt[i][0], cnt[i][1])] = i;
        }
        for(int i=1; i<=n; i++) cout << arr[i] << rp;
        cout << ln;
    }
}