#define rp ' '
#define ln '\n'
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct dst{
    ll d, sov;
    bool operator<(const dst &tmp) const{
        if(d==tmp.d) return sov>tmp.sov;
        return d<tmp.d;
    }
}dst;
ll n;
ll a[330];
ll INF = 1e18;
bool map[330][330];
dst dist[330][330];
int main(){
    fastio;
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    for(ll i=1; i<=n; i++){
        char tmp[330];
        cin >> tmp;
        for(ll j=0; j<n; j++){
            if(tmp[j]=='Y') map[i][j+1] = 1;
            else map[i][j+1] = 0;
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(i==j){
                dist[i][j] = {0, a[i]};
            }
            else{
                dist[i][j] = {INF, 0};
            }
            if(map[i][j]){
                dist[i][j] = {1, a[i] + a[j]};
            }
        }
    }
    for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                dst nxt = {dist[i][k].d + dist[k][j].d, dist[i][k].sov + dist[k][j].sov - a[k]};
                // cout << i << rp << j << rp << k << ln;
                // cout << nxt.d << rp << nxt.sov << ln;
                // cout << dist[i][j].d << rp << dist[i][j].sov << ln;
                if(nxt < dist[i][j]){
                    dist[i][j] = nxt;
                }
            }
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int s, e;
        cin >> s >> e;
        if(dist[s][e].d >= INF) cout << "Impossible" << ln;
        else cout << dist[s][e].d << rp << dist[s][e].sov << ln;
    }
}