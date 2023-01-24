#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
int n;
map<string, int> mp;
vector<int> v[200100];
int vis[200100];
bool findcycle(int now){
    if(vis[now]){
        return vis[now]==-1;
    }
    vis[now] = -1;
    for(auto i:v[now]){
        if(findcycle(i)) return 1;
    }
    vis[now] = 1;
    return 0;
}
string s, e;
int main(){
    cin >> n;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        cin >> s >> e;
        if(mp.find(s) == mp.end()){
            mp.insert({s, cnt});
            cnt++;
        }
        if(mp.find(e) == mp.end()){
            mp.insert({e, cnt});
            cnt++;
        }
        v[mp[s]].push_back(mp[e]);
    }
    for(int i=0; i<cnt; i++){
        // cout << i << ": ";
        // for(auto j:v[i]){
        //     cout << j << rp;
        // }
        cout << ln;
        if(findcycle(i)){
            cout << "No" << ln;
            return 0;
        }
    }
    cout << "Yes" << ln;
}